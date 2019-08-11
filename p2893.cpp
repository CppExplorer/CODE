#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=2005;
int a[N],n,b[N],c[N],cnt;
long long f[N][N];
int main(){
    scanf("%d",&n);
    for (int i=1;i<=n;++i) scanf("%d",&a[i]),b[i]=a[i];
    sort(b+1,b+1+n);
    for (int i=1;i<=n;++i)
        if (i==1 || b[i]!=b[i-1]) c[++cnt]=b[i];
    for (int i=1;i<=n;++i){
        long long val=0x7f7f7f7f;
        for (int j=1;j<=cnt;++j){
            if (f[i-1][j]<val) val=f[i-1][j];
            f[i][j]=val+abs(a[i]-c[j]);
            // printf("%d %d %lld %lld\n",i,j,val,f[i][j]);
        }
    }
    long long ans=0x7f7f7f7f;
    for (int i=1;i<=cnt;++i) ans=min(ans,f[n][i]);
    memset(f,0,sizeof f);
    for (int i=1;i<=n;++i){
        long long val=0x7f7f7f7f;
        for (int j=cnt;j;--j){
            if (f[i-1][j]<val) val=f[i-1][j];
            f[i][j]=val+abs(a[i]-c[j]);
        }
    }
    for (int i=1;i<=cnt;++i) ans=min(ans,f[n][i]);
    printf("%lld",ans);
    return 0;
}