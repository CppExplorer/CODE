#include<cstdio>
using namespace std;
long long T,m,h;

long long power(long long a,long long b,long long p){
    long long res=1;
    a=a%p;
    while (b){
        if (b&1) res=(res*a)%p;
        a=(a*a)%p;
        b>>=1;
    }
    return res;
}

int main(){
    scanf("%lld",&T);
    while (T--){
        long long ans=0;
        scanf("%lld%lld",&m,&h);
        for (int i=1;i<=h;++i){
            long long a,b;
            scanf("%lld%lld",&a,&b);
            ans=(ans+power(a,b,m))%m;
        }
        printf("%lld\n",ans);
    }
    return 0;
}