#include<bits/stdc++.h>
using namespace std;
long long n,ans=1,k=3;
const int p=1000003;
int main(){
    scanf("%lld",&n);
    if (n==0){
        printf("1");
        return 0;
    }
    n--;
    while (n){
        if (n%2==1) ans=(ans*k)%p;
        n/=2;
        k=(k*k)%p;
    }
    printf("%lld",ans%p);
    return 0;
}