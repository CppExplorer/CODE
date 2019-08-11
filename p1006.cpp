#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,a[55][55],f[105][55][55];
int main(){
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;++i)
        for (int j=1;j<=m;++j) scanf("%d",&a[i][j]);
    for (int i=1;i<n+m;++i)
        for (int j=1;j<=n;++j)
            for (int k=1;k<=n;++k){
                if (i-j+1<1 || i-k+1<1 ||(j==k && j!=n && k!=n)) continue;
                f[i][j][k]=max(f[i-1][j][k],max(f[i-1][j][k-1],max(f[i-1][j-1][k],f[i-1][j-1][k-1])))+a[j][i-j+1]+a[k][i-k+1];
                if (j==k) f[i][j][k]-=a[j][i-j+1];
            }
    printf("%d",f[n+m-1][n][n]);
    return 0;
}