#include<bits/stdc++.h>
using namespace std;
const int N=1000005;
int n,v[N],prime[N],m,p[N],c[N];

void primes(){
    for (int i=2;i<=n;++i){
        if (!v[i]){
            v[i]=i;
            prime[++m]=i;
        }
        for (int j=1;j<=m;++j){
            if (prime[j]>v[i] || prime[j]*i>n) break;
            v[prime[j]*i]=prime[j];
        }
    }
}

int main(){
    scanf("%d",&n);
    primes();
    for (int i=1;i<=m;++i){
        p[i]=prime[i];
        int k=log(n)/log(prime[i]),mul=1;
        for (int j=1;j<=k;++j){
            mul*=prime[i];
            c[i]+=n/mul;
        }
    }
    for (int i=1;i<=m;++i) printf("%d %d\n",p[i],c[i]);
    return 0;
}