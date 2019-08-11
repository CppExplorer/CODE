#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
const int N=1005;
int n,d[N],cnt,st,ans[N],x[N],y[N],rd[N],cd[N],tot,fa[26],num;
bool f[26],vis[N];
struct String{
    char s[50];
    int len;
}str[N];

int father(int x){
    return fa[x]==x?x:fa[x]=father(fa[x]);
}

bool check(){
    for (int i=0;i<26;++i) fa[i]=i;
    for (int i=1;i<=tot;++i){
        int u=father(x[i]),v=father(y[i]);
        if (u!=v) fa[u]=v;
    }
    int cnt=0;
    for (int i=0;i<26;++i)
        if (f[i] && fa[i]==i) cnt++;
    if (cnt!=1) return false;
    return true;
}

void dfs(int x){
    for (int i=1;i<=n;++i)
        if (str[i].s[1]-'a'==x && !vis[i]){
            vis[i]=1;
            dfs(str[i].s[str[i].len]-'a');
            ans[++num]=i;
        }
}

bool cmp(String a,String b){
    int len=min(a.len,b.len);
    for (int i=1;i<=len;++i)
        if (a.s[i]!=b.s[i]) return a.s[i]<b.s[i];
    return a.len<b.len;
}

int main(){
    scanf("%d",&n);
    for (int i=1;i<=n;++i){
        scanf("%s",str[i].s+1);
        str[i].len=strlen(str[i].s+1);
    }
    sort(str+1,str+1+n,cmp);
    for (int i=1;i<=n;++i){
        int a=str[i].s[1]-'a',b=str[i].s[str[i].len]-'a';
        f[a]=f[b]=1;
        x[++tot]=a; y[tot]=b;
        rd[b]++; cd[a]++;
    }
    if (!check()){
        printf("***");
        return 0;
    }
    st=-1;
    for (int i=0;i<26;++i)
        if (abs(rd[i]-cd[i])>=1){
            cnt++;
            if (abs(rd[i]-cd[i])>1){
                printf("***");
                return 0;
            }
            if (cd[i]-rd[i]==1 && st==-1) st=i;
        }
    if (cnt && cnt!=2){
        printf("***");
        return 0;
    }else if (cnt==2) dfs(st);
    else for (int i=0;i<26;++i) if (f[i]) dfs(i);
    for (int i=num;i;--i){
        printf("%s",str[ans[i]].s+1);
        if (i>1) printf("."); 
    }
    return 0;
}