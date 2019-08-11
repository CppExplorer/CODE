#include<bits/stdc++.h>
using namespace std;
int n,m,x,y,a[55][55],i,j,k,t;
bool f[55][55][35];
int main(){
    memset(a,0x3f,sizeof a);
    scanf("%d%d",&n,&m);
    for (i=1;i<=m;++i){
        int x,y;
        scanf("%d%d",&x,&y);
        f[x][y][0]=1;
        a[x][y]=1;
    }
    for (k=1;k<=31;++k)
        for (t=1;t<=n;++t)
            for (i=1;i<=n;++i)
                for (j=1;j<=n;++j)
                if (f[i][t][k-1] && f[t][j][k-1]){
                    f[i][j][k]=1;
                    a[i][j]=1;
                }
    for (k=1;k<=n;++k)
        for (i=1;i<=n;++i)
            for (j=1;j<=n;++j)
            a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
    printf("%d",a[1][n]);
    return 0;
}