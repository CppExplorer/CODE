#include<bits/stdc++.h>
using namespace std;
long long n,a[1000005],avg,sum[1000006],ans;
int main(){
    scanf("%lld",&n);
    for (int i=1;i<=n;++i){
        scanf("%lld",&a[i]);
        avg+=a[i];
    }
    avg/=n;
    for (int i=1;i<=n;++i) a[i]-=avg;
    for (int i=1;i<=n;++i) sum[i]=a[i]+sum[i-1];
    sort(sum+1,sum+1+n);
    for (int i=1;i<=n;++i)
        ans+=abs(sum[i]-sum[(n+1)>>1]);
    printf("%lld",ans);
    return 0;
}