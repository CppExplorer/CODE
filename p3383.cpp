#include<bits/stdc++.h>
using namespace std;
const int N=10000005;
int n,m,v[N],prime[N],cnt,x;
bool f[N];

void primes(){
    for (int i=2;i<=n;++i){
        if (v[i]==0){
            v[i]=i;
            prime[++cnt]=i;
        }
        for (int j=1;j<=cnt;++j){
            if (prime[j]>v[i] || prime[j]*i>n) break;
            v[prime[j]*i]=prime[j];
        }
    }
}

void ask(int x){
    if (f[x]) printf("Yes\n");
        else printf("No\n");
}

int main(){
    scanf("%d%d",&n,&m);
    primes();
    for (int i=1;i<=cnt;++i) f[prime[i]]=1;
    for (int i=1;i<=m;++i){
        scanf("%d",&x);
        ask(x);
    }
    return 0;
}