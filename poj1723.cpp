#include<cstdio>
#include<algorithm>
using namespace std;
int n,x[10005],y[10005],midx,midy,ans;
int main(){
    scanf("%d",&n);
    for (int i=1;i<=n;++i) scanf("%d%d",&x[i],&y[i]);
    sort(y+1,y+1+n);
    midy=y[(n+1)>>1];
    sort(x+1,x+1+n);
    for (int i=1;i<=n;++i) x[i]-=i;
    sort(x+1,x+1+n);
    midx=x[(n+1)>>1];
    for (int i=1;i<=n;++i) ans+=abs(x[i]-midx)+abs(y[i]-midy);
    printf("%d",ans);
    return 0;
}