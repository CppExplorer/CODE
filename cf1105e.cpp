#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int N=1e5+5;
unsigned long long p[45],b[N],c[N],d[N];
int n,m,a[45][45],cmd[N],tot,cnt,f[45],ans;
char s[N][45];

void Hash(int num){
    int len=strlen(s[num]+1);
    unsigned long long val=0;
    for (int i=1;i<=len;++i)
        val+=p[i-1]*s[num][i];
    d[num]=val;
    b[++tot]=val;
}

int query(unsigned long long x){
    return lower_bound(c+1,c+1+cnt,x)-c;
}

vector<int> v[45];
bool dfs(int cnt){
    if (!v[cnt].size()){
        if (cnt>ans){ans=cnt; return true;}
        return false;
    }
    for (int i=0;i<v[cnt].size();++i){
        if (v[cnt].size()-i+cnt<=ans) return false;
        int x=v[cnt][i];
        if (f[x]+cnt<=ans) return false;
        v[cnt+1].clear();
        for (int j=i+1;j<v[cnt].size();++j)
            if (a[x][v[cnt][j]]) v[cnt+1].push_back(v[cnt][j]);
        if (dfs(cnt+1)) return true;
    }
    return false;
}

int MaxClique(int n){
    for (int i=n;i;--i){
        v[1].clear();
        for (int j=i+1;j<=n;++j)
            if (a[i][j]) v[1].push_back(j);
        dfs(1);
        f[i]=ans;
    }
    return ans;
}

int main(){
    scanf("%d%d",&n,&m);
    p[0]=1;
    for (int i=1;i<=40;++i) p[i]=p[i-1]*131;
    for (int i=1;i<=n;++i){
        scanf("%d",&cmd[i]);
        if (cmd[i]==2) scanf("%s",s[i]+1),Hash(i);
    }
    sort(b+1,b+1+tot);
    for (int i=1;i<=tot;++i)
        if (i==1 || b[i]!=b[i-1]) c[++cnt]=b[i];
    for (int i=1;i<=n;){
        if (cmd[i]==1){
            int j=i+1;
            for (;cmd[j]!=1 && j<=n;j++); j--;
            for (int k=i+1;k<j;++k)
                for (int t=i+2;t<=j;++t){
                    int x=query(d[k]),y=query(d[t]);
                    a[x][y]=a[y][x]=1;
                }
            i=j+1;
        }else i++;
    }
    for (int i=1;i<=cnt;++i)
        for (int j=1;j<=cnt;++j)
        if (!a[i][j] && i!=j) a[i][j]=1;
            else a[i][j]=0;
    // for (int i=1;i<=cnt;++i){
    //     for (int j=1;j<=cnt;++j) printf("%d ",a[i][j]);
    //     printf("\n");
    // }
    printf("%d\n",MaxClique(cnt));
    return 0;
}