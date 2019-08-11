#include<cstdio>
#include<iostream>
using namespace std;
int n,a[505][505],sum[505][505],b[505],f[505],ans=-2e9;
int main(){
    scanf("%d",&n);
    for (int i=1;i<=n;++i)
        for (int j=1;j<=n;++j) scanf("%d",&a[i][j]);
    for (int i=1;i<=n;++i)
        for (int j=1;j<=n;++j) sum[i][j]=a[i][j]+sum[i][j-1];
    for (int i=0;i<n;++i)
        for (int j=i+i;j<=n;++j){
            for (int k=1;k<=n;++k) b[k]=sum[k][j]-sum[k][i];
            f[1]=b[1];
            for (int k=1;k<=n;++k){
                f[k]=max(f[k-1]+b[k],b[k]);
                ans=max(ans,f[k]);
            }
        }
    printf("%d",ans);
    return 0;
}