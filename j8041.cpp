#include<bits/stdc++.h>
using namespace std;
int n,m,i,j,k,fa[1050],f[1050][150],c[1050],e[1050];
int main(){
    scanf("%d%d",&n,&m);
    for (i=2;i<=n;++i) scanf("%d",&fa[i]);
    for (i=1;i<=n;++i) scanf("%d",&c[i]);
    for (i=1;i<=n;++i) scanf("%d",&e[i]);
    for (i=n;i>=1;--i){
        for (j=c[i];j<=m;++j)
            f[i][j]=max(f[i][j],e[i]);
        for (j=m;j>=0;--j)
            for (k=0;k<=j;++k)
            f[fa[i]][j]=max(f[fa[i]][j],f[fa[i]][j-k]+f[i][k]);
    }
    printf("%d",f[1][m]);
    return 0;
}