#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int T,n,m,f[2005][205][205],c[205][205],a[2005];
int main(){
    scanf("%d",&T);
    while (T--){
        scanf("%d%d",&n,&m);
        for (int i=1;i<=n;++i)
            for (int j=1;j<=n;++j) scanf("%d",&c[i][j]);
        for (int i=1;i<=m;++i) scanf("%d",&a[i]);
        memset(f,0x3f,sizeof f);
        f[0][1][2]=0; a[0]=3;
        int ans=0x7f7f7f7f;
        for (int i=1;i<=m;++i)
            for (int j=1;j<=n;++j)
                for (int k=1;k<=n;++k){
                    if (j!=a[i] && k!=a[i]) f[i][j][k]=min(f[i][j][k],f[i-1][j][k]+c[a[i-1]][a[i]]);
                    if (a[i-1]!=a[i] && k!=a[i]) f[i][a[i-1]][k]=min(f[i][a[i-1]][k],f[i-1][j][k]+c[j][a[i]]);
                    if (a[i-1]!=a[i] && j!=a[i]) f[i][j][a[i-1]]=min(f[i][j][a[i-1]],f[i-1][j][k]+c[k][a[i]]);
                }
        for (int i=1;i<=n;++i)
            for (int j=1;j<=n;++j)
                ans=min(ans,f[m][i][j]);
        printf("%d\n",ans);
    }
    return 0;
}