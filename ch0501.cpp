#include<bits/stdc++.h>
using namespace std;
int n,a[100005],mid;
long long ans;
int main(){
    scanf("%d",&n);
    for (int i=1;i<=n;++i) scanf("%d",&a[i]);
    sort(a+1,a+1+n);
    if (n&1) mid=(a[n>>1]+a[n>>1+1])>>1;
        else mid=a[n>>1];
    for (int i=1;i<=n;++i) ans+=abs(mid-a[i]);
    printf("%lld",ans);
    return 0;
}