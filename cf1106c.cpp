#include<cstdio>
#include<algorithm>
using namespace std;
const int N=3e5+5;
int n,a[N];
long long ans;
int main(){
    scanf("%d",&n);
    for (int i=1;i<=n;++i) scanf("%d",&a[i]);
    sort(a+1,a+1+n);
    for (int i=1;2*i<=n;++i)
        ans+=1LL*(a[i]+a[n-i+1])*(a[i]+a[n-i+1]);
    printf("%lld",ans);
    return 0;
}