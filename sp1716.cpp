#include<bits/stdc++.h>
using namespace std;
int n,q,i,x,y,cmd,a[500005];
struct SegmentTree{
    int l,r,lmax,rmax,sum,ans;
}t[2000005];

void update(int x){
    t[x].sum=t[x*2].sum+t[x*2+1].sum;
    t[x].lmax=max(t[x*2].lmax,t[x*2].sum+t[x*2+1].lmax);
    t[x].rmax=max(t[x*2+1].rmax,t[x*2+1].sum+t[x*2].rmax);
    t[x].ans=max(max(t[x*2].ans,t[x*2+1].ans),t[x*2].rmax+t[x*2+1].lmax);
}

void build(int x,int l,int r){
    t[x].l=l; t[x].r=r;
    if (l==r){
        t[x].sum=a[l];
        t[x].lmax=a[l];
        t[x].rmax=a[l];
        t[x].ans=a[l];
        return;
    }
    int mid=(l+r)>>1;
    build(x*2,l,mid);
    build(x*2+1,mid+1,r);
    update(x);
}

SegmentTree ask(int x,int l,int r){
    if (l<=t[x].l && r>=t[x].r) return t[x];
    int mid=(t[x].l+t[x].r)>>1;
    SegmentTree a,b,c;
    a.sum=a.lmax=a.rmax=a.ans=b.sum=b.lmax=b.rmax=b.ans=-0x3f3f3f3f;
    c.sum=0;
    if (l<=mid){
        a=ask(x*2,l,r);
        c.sum+=a.sum;
    }
    if (r>mid){
        b=ask(x*2+1,l,r);
        c.sum+=b.sum;
    }
    c.ans=max(max(a.ans,b.ans),a.rmax+b.lmax);
    c.lmax=max(a.lmax,a.sum+b.lmax);
    if (l>mid) c.lmax=max(c.lmax,b.lmax);
    c.rmax=max(b.rmax,b.sum+a.rmax);
    if (r<=mid) c.rmax=max(c.rmax,a.rmax);
    return c;
}

void change(int x,int p,int val){
    if (t[x].l==t[x].r){
        t[x].sum=val;
        t[x].lmax=val;
        t[x].rmax=val;
        t[x].ans=val;
        return;
    }
    int mid=(t[x].l+t[x].r)>>1;
    if (p<=mid) change(x*2,p,val);
        else change(x*2+1,p,val);
    update(x);
}

int main(){
    scanf("%d",&n);
    for (i=1;i<=n;++i) scanf("%d",&a[i]);
    build(1,1,n);
    scanf("%d",&q);
    for (i=1;i<=q;++i){
        scanf("%d%d%d",&cmd,&x,&y);
        if (cmd==1){
            if (x>y) swap(x,y);
            printf("%d\n",ask(1,x,y).ans);
        }else change(1,x,y);
    }
    return 0;
}