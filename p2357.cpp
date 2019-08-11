#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,f,i,x,l,r,k,c[800005],c0[800005],sum[200005];

ll lowbit(ll x){
    return x&(-x);
}

void add(ll x,ll y){
    while (x<=n){
        c[x]+=y;
        x+=lowbit(x);
    }
}

void add0(ll x,ll y){
    while (x<=n){
        c0[x]+=y;
        x+=lowbit(x);
    }
}

ll ask(ll x){
    ll res=0;
    while (x){
        res+=c[x];
        x-=lowbit(x);
    }
    return res;
}

ll ask0(ll x){
    ll res=0;
    while (x){
        res+=c0[x];
        x-=lowbit(x);
    }
    return res;
}

int main(){
    scanf("%lld%lld",&n,&f);
    for (i=1;i<=n;++i){
        scanf("%lld",&x);
        sum[i]=sum[i-1]+x;
    }
    for (i=1;i<=f;++i){
        scanf("%lld",&x);
        if (x==1){
            scanf("%lld%lld%lld",&l,&r,&k);
            add0(l,k); add0(r+1,-k);
            add(l,l*k); add(r+1,(r+1)*(-k));
        }
        if (x==2){
            scanf("%lld",&k);
            add0(1,k); add0(2,-k);
            add(1,k); add(2,-2*k);
        }
        if (x==3){
            scanf("%lld",&k);
            add0(1,-k); add0(2,k);
            add(1,-k); add(2,2*k);
        }
        if (x==4){
            scanf("%lld%lld",&l,&r);
            printf("%lld\n",(sum[r]+(r+1)*ask0(r)-ask(r))-(sum[l-1]+l*ask0(l-1)-ask(l-1)));
        }
        if (x==5) printf("%lld\n",(sum[1]+2*ask0(1)-ask(1))-(sum[0]+1*ask0(0)-ask(0)));
    }
    return 0;
}