#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,f[2][205][205],c[205][205],a[1005],ans=0x7f7f7f7f;
int main(){
    scanf("%d",&n);
    for (int i=1;i<=n;++i)
        for (int j=1;j<=n;++j) scanf("%d",&c[i][j]);
    while (scanf("%d",&a[++m])==1);
    memset(f,0x3f,sizeof f);
    f[0][1][2]=0; a[0]=3;
    int lst=0,now=1;
    for (int i=1;i<=m;++i){
        for (int j=1;j<=n;++j)
            for (int k=1;k<=n;++k) f[now][j][k]=0x3f3f3f3f;
        for (int j=1;j<=n;++j)
            for (int k=1;k<=n;++k){
                if (j!=a[i] && k!=a[i]) f[now][j][k]=min(f[now][j][k],f[lst][j][k]+c[a[i-1]][a[i]]);
                if (a[i-1]!=a[i] && k!=a[i]) f[now][a[i-1]][k]=min(f[now][a[i-1]][k],f[lst][j][k]+c[j][a[i]]);
                if (a[i-1]!=a[i] && j!=a[i]) f[now][j][a[i-1]]=min(f[now][j][a[i-1]],f[lst][j][k]+c[k][a[i]]);
            }
        lst^=1,now^=1;
    }
    for (int i=1;i<=n;++i)
        for (int j=1;j<=n;++j)
            ans=min(ans,f[lst][i][j]);
    printf("%d",ans);
    return 0;
}