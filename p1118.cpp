#include<bits/stdc++.h>
using namespace std;
int n,i,j,sum,ans[15],b[15][15];
bool vis[15];

void dfs(int k,int tot){
    if (k==n){
        if (tot==sum){
            for (int i=1;i<=n;++i) printf("%d ",ans[i]);
            exit(0);
        }else return;
    }
    if (tot>sum) return;
    for (int i=1;i<=n;++i)
    if (!vis[i]){
        vis[i]=1;
        ans[k+1]=i;
        dfs(k+1,tot+b[n][k+1]*i);
        vis[i]=0;
    }
}

int main(){
    scanf("%d%d",&n,&sum);
    b[1][1]=1;
    for (i=2;i<=n;++i)
        for (j=1;j<=i;++j)
        b[i][j]=b[i-1][j]+b[i-1][j-1];
    dfs(0,0);
    return 0;
}