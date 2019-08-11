#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,i,a,c[2000005],f,x,y;

ll lowbit(ll x){
    return x&(-x);
}

ll ask(ll x){
    ll res=0;
    while (x){
        res+=c[x];
        x-=lowbit(x);
    }
    return res;
}

void add(ll x,ll y){
    while (x<=n){
        c[x]+=y;
        x+=lowbit(x);
    }
}

int main(){
    scanf("%lld%lld",&n,&m);
    for (i=1;i<=n;++i){
        scanf("%lld",&a);
        add(i,a);
    }
    for (i=1;i<=m;++i){
        scanf("%lld%lld%lld",&f,&x,&y);
        if (f==1) add(x,y);
        else printf("%lld\n",ask(y)-ask(x-1));
    }
    return 0;
}