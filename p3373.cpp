#include<bits/stdc++.h>
using namespace std;
long long n,m,p,i,c,x,y,k,a[100005];
struct SegmentTree{
    long long sum,mul,add,l,r;
}t[500005];

void build(long long x,long long l,long long r){
    t[x].l=l; t[x].r=r; t[x].mul=1;
    if (l==r){
        t[x].sum=a[l]%p;
        return;
    }
    long long mid=(l+r)/2;
    build(x*2,l,mid);
    build(x*2+1,mid+1,r);
    t[x].sum=(t[x*2].sum+t[x*2+1].sum)%p;
}

void spread(long long x){
    t[x*2].mul=(t[x*2].mul*t[x].mul)%p;
    t[x*2+1].mul=(t[x*2+1].mul*t[x].mul)%p;
    t[x*2].add=(t[x*2].add*t[x].mul+t[x].add)%p;
    t[x*2+1].add=(t[x*2+1].add*t[x].mul+t[x].add)%p;
    t[x*2].sum=(t[x*2].sum*t[x].mul+t[x].add*(t[x*2].r-t[x*2].l+1))%p;
    t[x*2+1].sum=(t[x*2+1].sum*t[x].mul+t[x].add*(t[x*2+1].r-t[x*2+1].l+1))%p;
    t[x].add=0;
    t[x].mul=1;
}

void mulitply(long long x,long long l,long long r,long long d){
    if (l<=t[x].l && r>=t[x].r){
        t[x].sum=(t[x].sum*d)%p;
        t[x].mul=(t[x].mul*d)%p;
        t[x].add=(t[x].add*d)%p;
        return;
    }
    spread(x);
    long long mid=(t[x].l+t[x].r)/2;
    if (l<=mid) mulitply(x*2,l,r,d);
    if (r>mid) mulitply(x*2+1,l,r,d);
    t[x].sum=(t[x*2].sum+t[x*2+1].sum)%p;
}

void addition(long long x,long long l,long long r,long long d){
    if (l<=t[x].l && r>=t[x].r){
        t[x].sum=(t[x].sum+d*(t[x].r-t[x].l+1))%p;
        t[x].add=(t[x].add+d)%p;
        return;
    }
    spread(x);
    long long mid=(t[x].l+t[x].r)/2;
    if (l<=mid) addition(x*2,l,r,d);
    if (r>mid) addition(x*2+1,l,r,d);
    t[x].sum=(t[x*2].sum+t[x*2+1].sum)%p;
}

long long ask(long long x,long long l,long long r){
    if (l<=t[x].l && r>=t[x].r) return t[x].sum;
    spread(x);
    long long val=0;
    long long mid=(t[x].l+t[x].r)/2;
    if (l<=mid) val=(val+ask(x*2,l,r))%p;
    if (r>mid) val=(val+ask(x*2+1,l,r))%p;
    return val%p;
}

int main(){
    scanf("%lld%lld%lld",&n,&m,&p);
    for (i=1;i<=n;++i) scanf("%lld",&a[i]);
    build(1,1,n);
    for (i=1;i<=m;++i){
        scanf("%lld%lld%lld",&c,&x,&y);
        if (c==1){
            scanf("%lld",&k);
            mulitply(1,x,y,k);
        }else if (c==2){
            scanf("%lld",&k);
            addition(1,x,y,k);
        }else printf("%lld\n",ask(1,x,y)%p);
    }
    return 0;
}
