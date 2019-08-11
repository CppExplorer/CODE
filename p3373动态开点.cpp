#include<cstdio>
using namespace std;
const long long N=100005;
long long n,m,p,root,tot,a[N],cmd,l,r,y,k;
struct SegmentTree{
    long long l,r,sum,mul,add;
}t[N<<1];

long long build(){
    tot++;
    t[tot].l=t[tot].r=t[tot].sum=t[tot].add=0;
    t[tot].mul=1;
    return tot;
}

void insert(long long x,long long l,long long r,long long k,long long val){
    if (l==r){
        t[x].sum=val;
        return;
    }
    long long mid=(l+r)>>1;
    if (k<=mid){
        if (!t[x].l) t[x].l=build();
        insert(t[x].l,l,mid,k,val);
    }else{
        if (!t[x].r) t[x].r=build();
        insert(t[x].r,mid+1,r,k,val);
    }
    t[x].sum=(t[t[x].l].sum+t[t[x].r].sum)%p;
}

void spread(long long x,long long l,long long r){
    if (!t[x].l) t[x].l=build();
    if (!t[x].r) t[x].r=build();
    long long ls=t[x].l,rs=t[x].r,mid=(l+r)>>1;
    t[ls].mul=(t[ls].mul*t[x].mul)%p;
    t[rs].mul=(t[rs].mul*t[x].mul)%p;
    t[ls].add=(t[ls].add*t[x].mul+t[x].add)%p;
    t[rs].add=(t[rs].add*t[x].mul+t[x].add)%p;
    t[ls].sum=(t[ls].sum*t[x].mul+t[x].add*(mid-l+1))%p;
    t[rs].sum=(t[rs].sum*t[x].mul+t[x].add*(r-mid))%p;
    t[x].add=0;
    t[x].mul=1;
}

void mul(long long x,long long ln,long long rn,long long l,long long r,long long val){
    if (l<=ln && r>=rn){
        t[x].sum=(t[x].sum*val)%p;
        t[x].mul=(t[x].mul*val)%p;
        t[x].add=(t[x].add*val)%p;
        return;
    }
    spread(x,ln,rn);
    long long mid=(ln+rn)>>1;
    if (l<=mid){
        if (!t[x].l) t[x].l=build();
        mul(t[x].l,ln,mid,l,r,val);
    }
    if (r>mid){
        if (!t[x].r) t[x].r=build();
        mul(t[x].r,mid+1,rn,l,r,val);
    }
    t[x].sum=(t[t[x].l].sum+t[t[x].r].sum)%p;
}

void add(long long x,long long ln,long long rn,long long l,long long r,long long val){
    if (l<=ln && r>=rn){
        t[x].add=(t[x].add+val)%p;
        t[x].sum=(t[x].sum+(rn-ln+1)*val)%p;
        return;
    }
    spread(x,ln,rn);
    long long mid=(ln+rn)>>1;
    if (l<=mid){
        if (!t[x].l) t[x].l=build();
        add(t[x].l,ln,mid,l,r,val);
    }
    if (r>mid){
        if (!t[x].r) t[x].r=build();
        add(t[x].r,mid+1,rn,l,r,val);
    }
    t[x].sum=(t[t[x].l].sum+t[t[x].r].sum)%p;
}

long long ask(int x,int ln,int rn,int l,int r){
    if (l<=ln && r>=rn) return t[x].sum;
    spread(x,ln,rn);
    int mid=(ln+rn)>>1;
    long long val=0;
    if (l<=mid){
        if (!t[x].l) t[x].l=build();
        val=(val+ask(t[x].l,ln,mid,l,r))%p;
    }
    if (r>mid){
        if (!t[x].r) t[x].r=build();
        val=(val+ask(t[x].r,mid+1,rn,l,r))%p;
    }
    return val%p;
}

int main(){
    scanf("%lld%lld%lld",&n,&m,&p);
    for (int i=1;i<=n;++i) scanf("%lld",&a[i]);
    root=build();
    for (int i=1;i<=n;++i) insert(root,1,n,i,a[i]);
    for (int i=1;i<=m;++i){
        scanf("%lld",&cmd);
        switch (cmd){
            case 1:
                scanf("%lld%lld%lld",&l,&r,&k);
                mul(root,1,n,l,r,k);
                break;
            case 2:
                scanf("%lld%lld%lld",&l,&r,&k);
                add(root,1,n,l,r,k);
                break;
            case 3:
                scanf("%lld%lld",&l,&r);
                printf("%lld\n",ask(root,1,n,l,r));
                break;
        }
    }
    return 0;
}