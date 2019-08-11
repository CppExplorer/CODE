#include<bits/stdc++.h>
using namespace std;
int n,a[20][20],f[1<<20][20],i,j,k;
int main(){
    scanf("%d",&n);
    for (i=0;i<n;++i)
        for (j=0;j<n;++j)
        scanf("%d",&a[i][j]);
    memset(f,0x3f,sizeof f);
    f[1][0]=0;
    for (i=1;i<(1<<n);++i)
        for (j=0;j<n;++j) if ((i>>j)&1)
            for (k=0;k<n;++k) if (((i^(1<<j))>>k)&1)
            f[i][j]=min(f[i][j],f[i^(1<<j)][k]+a[k][j]);
    printf("%d",f[(1<<n)-1][n-1]);
    return 0;
}