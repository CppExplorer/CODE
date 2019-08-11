#include<cmath>
#include<cstdio>
#include<iostream>
#define M 9901
using namespace std;
long long a,b,p[1000000],c[1000000],ans=1,n,pr[100000],cnt;
bool f[1000000];

long long power(long x,long y){
    long long ans=1;
    long long a=x,b=y;
    while (b){
        if (b&1) ans=(ans*a)%M;
        a=(a*a)%M;
        b>>=1;
    }
    return ans;
}

long long sum(long long p,long long c){
    if (!p) return 0;
    if (!c) return 1;
    if (c&1) return ((1+power(p,(c+1)>>1))*sum(p,(c-1)>>1))%M;
        else return ((1+power(p,c>>1))*sum(p,(c>>1)-1)+power(p,c))%M;
}

int main(){
    for (int i=2;i<=10003;++i){
        if (f[i]) continue;
        cnt++; pr[cnt]=i;
        for (int j=1;i*j<=10003;++j)
            f[i*j]=1;
    }
    scanf("%lld%lld",&a,&b);
    int x=a;
    for (int i=1;i<=cnt;++i){
        int po=0;
        while (x%pr[i]==0){
            po++; x/=pr[i];
        }
        if (po){
            n++; p[n]=pr[i]; c[n]=po;
        }
    }
    if (x!=1){
        n++; p[n]=x; c[n]=1;
    }
    for (int i=1;i<=n;++i) ans=(ans*sum(p[i],b*c[i]))%M;
    printf("%lld",ans);
    return 0;
}