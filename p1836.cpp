#include<cstdio>
#include<algorithm>
using namespace std;
int sum[10]={0,1,3,6,10,15,21,28,36,45};
long long n;
int main(){
    scanf("%lld",&n);
    long long ans=0,a=1,b=0;
    while (n){
        ans+=a*(45*(n/10)+sum[n%10?n%10-1:0])+(n%10)*(b+1);
        b+=(n%10)*a; a*=10;
        n/=10;
    }
    printf("%lld",ans);
    return 0;
}