#include<bits/stdc++.h>
using namespace std;
int n,c,i,j,x[55],p[55],f[55][55][2],sum[55];
int main(){
    scanf("%d%d",&n,&c);
    for (i=1;i<=n;++i){
        scanf("%d%d",&x[i],&p[i]);
        sum[i]=sum[i-1]+p[i];
    }
    memset(f,0x7f,sizeof f);
    f[c][c][0]=0; f[c][c][1]=0;
    for (int k=2;k<=n;++k)
        for (i=1;i+k-1<=n;++i){
            j=i+k-1;
            f[i][j][0]=min(f[i+1][j][1]+(x[j]-x[i])*(sum[n]-sum[j]+sum[i]),f[i+1][j][0]+(x[i+1]-x[i])*(sum[n]-sum[j]+sum[i]));
            f[i][j][1]=min(f[i][j-1][1]+(x[j]-x[j-1])*(sum[n]-sum[j-1]+sum[i-1]),f[i][j-1][0]+(x[j]-x[i])*(sum[n]-sum[j-1]+sum[i-1]));
        }
    printf("%d",min(f[1][n][0],f[1][n][1]));
    return 0;
}