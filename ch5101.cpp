#include<cstdio>
#include<algorithm>
using namespace std;
const int N=3e3+5;
int n,a[N],b[N],f[N][N],ans;
int main(){
    scanf("%d",&n);
    for (int i=1;i<=n;++i) scanf("%d",&a[i]);
    for (int i=1;i<=n;++i) scanf("%d",&b[i]);
    a[0]=b[0]=-0x7f7f7f7f;
    for (int i=1;i<=n;++i){
        int val=0;
        if (b[0]<a[i]) val=f[i-1][0];
        for (int j=1;j<=n;++j){
            if (a[i]==b[j]) f[i][j]=val+1;
                else f[i][j]=f[i-1][j];
            if (b[j]<a[i]) val=max(val,f[i-1][j]);
        }
    }
    for (int i=1;i<=n;++i) ans=max(ans,f[n][i]);
    printf("%d",ans);
    return 0;
}