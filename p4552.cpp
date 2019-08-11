#include<bits/stdc++.h>
using namespace std;
int n,a[100005],c[100005];
long long z,f;
int main(){
    scanf("%d",&n);
    for (int i=1;i<=n;++i) scanf("%d",&a[i]);
    for (int i=1;i<=n;++i) c[i]=a[i]-a[i-1];
    for (int i=2;i<=n;++i){
        if (c[i]>0) z+=c[i];
        if (c[i]<0) f-=c[i];
    }
    printf("%lld\n%lld",max(z,f),abs(z-f)+1);
    return 0;
}