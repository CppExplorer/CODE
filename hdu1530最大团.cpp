#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;
const int N=55;
int n,a[N][N],f[N],ans;
vector<int> New[N];

bool dfs(int cnt){
    if (!New[cnt].size()){
        if (cnt>ans){ans=cnt; return true;}
        return false;
    }
    for (int i=0;i<New[cnt].size();++i){
        if (New[cnt].size()-i+cnt<=ans) return false;
        int x=New[cnt][i];
        if (f[x]+cnt<=ans) return false;
        New[cnt+1].clear();
        for (int j=i+1;j<New[cnt].size();++j)
            if (a[x][New[cnt][j]]) New[cnt+1].push_back(New[cnt][j]);
        if (dfs(cnt+1)) return true;
    }
    return false;
}

int MaxClique(){
    memset(f,0,sizeof f);
    ans=0;
    for (int i=n;i;--i){
        New[1].clear();
        for (int j=i+1;j<=n;++j)
            if (a[i][j]) New[1].push_back(j);
        dfs(1);
        f[i]=ans;
    }
    return ans;
}

int main(){
    while (scanf("%d",&n) && n){
        for (int i=1;i<=n;++i)
            for (int j=1;j<=n;++j) scanf("%d",&a[i][j]);
        printf("%d\n",MaxClique());
    }
    return 0;
}