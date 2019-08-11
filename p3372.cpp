#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,i,f,x,y,k;
ll a[100005];
struct tree{
    ll l,r,sum,add;
}t[400005];

void build(int x,int l,int r){
    t[x].l=l; t[x].r=r;
    if (l==r){
        t[x].sum=a[l];
        return;
    }
    int mid=(l+r)/2;
    build(x*2,l,mid);
    build(x*2+1,mid+1,r);
    t[x].sum=t[2*x].sum+t[2*x+1].sum;
}

void spread(int x){
    if (t[x].add){
        int ls=x*2,rs=x*2+1;
        t[ls].sum+=t[x].add*(t[ls].r-t[ls].l+1);
        t[rs].sum+=t[x].add*(t[rs].r-t[rs].l+1);
        t[ls].add+=t[x].add;
        t[rs].add+=t[x].add;
        t[x].add=0;
    }
}

void change(int x,int l,int r,int k){
    if (l<=t[x].l && r>=t[x].r){
        t[x].sum+=k*(t[x].r-t[x].l+1);
        t[x].add+=k;
        return;
    }
    spread(x);
    int mid=(t[x].l+t[x].r)/2;
    if (l<=mid) change(x*2,l,r,k);
    if (r>mid) change(x*2+1,l,r,k);
    t[x].sum=t[x*2].sum+t[x*2+1].sum;
}

ll ask(int x,int l,int r){
    if (l<=t[x].l && r>=t[x].r) return t[x].sum;
    spread(x);
    int mid=(t[x].l+t[x].r)/2;
    ll res=0;
    if (l<=mid) res+=ask(x*2,l,r);
    if (r>mid) res+=ask(x*2+1,l,r);
    return res;
}

int main(){
    scanf("%d%d",&n,&m);
    for (i=1;i<=n;++i) scanf("%lld",&a[i]);
    build(1,1,n);
    for (i=1;i<=m;++i){
        scanf("%d%d%d",&f,&x,&y);
        if (f==1){
            scanf("%d",&k);
            change(1,x,y,k);
        }else printf("%lld\n",ask(1,x,y));
    }
    return 0;
}