#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,a[400],b[150],f[50][50][50][50],cnt[5];
int main(){
    // freopen("a.in","r",stdin);
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;++i) scanf("%d",&a[i]);
    for (int i=1;i<=m;++i) scanf("%d",&b[i]),cnt[b[i]]++;
    f[0][0][0][0]=a[1];
    for (int i=0;i<=cnt[1];++i)
        for (int j=0;j<=cnt[2];++j)
            for (int k=0;k<=cnt[3];++k)
                for (int l=0;l<=cnt[4];++l){
                    int tmp=f[i][j][k][l];
                    if (i) tmp=max(tmp,f[i-1][j][k][l]+a[1+i+j*2+k*3+l*4]);
                    if (j) tmp=max(tmp,f[i][j-1][k][l]+a[1+i+j*2+k*3+l*4]);
                    if (k) tmp=max(tmp,f[i][j][k-1][l]+a[1+i+j*2+k*3+l*4]);
                    if (l) tmp=max(tmp,f[i][j][k][l-1]+a[1+i+j*2+k*3+l*4]);
                    f[i][j][k][l]=tmp;
                    // printf("%d %d %d %d %d\n",i,j,k,l,tmp);
                }
    printf("%d",f[cnt[1]][cnt[2]][cnt[3]][cnt[4]]);
    return 0;
}