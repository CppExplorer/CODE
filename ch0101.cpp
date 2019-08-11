#include<bits/stdc++.h>
using namespace std;
long long a,b,p,ans=1;
int main(){
    scanf("%lld%lld%lld",&a,&b,&p);
    while (b){
        if (b%2) ans=ans*a%p;
        a=a*a%p;
        b/=2;
    }
    printf("%lld",ans%p);
    return 0;
}