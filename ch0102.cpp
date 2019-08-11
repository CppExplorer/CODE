#include<bits/stdc++.h>
using namespace std;
long long a,b,p,ans=0;
int main(){
    scanf("%lld%lld%lld",&a,&b,&p);
    while (b){
        if (b&1) ans=(ans+a)%p;
        a=a*2%p;
        b>>=1;
    }
    printf("%lld",ans%p);
    return 0;
}