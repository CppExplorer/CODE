#include<bits/stdc++.h>
using namespace std;
int T,n,m,a[10005],l1,r1,l2,r2;
struct SegmentTree{
    int l,r,ans,lmax,rmax,sum;
}t[40005];

void clear(SegmentTree &a,int val){
    a.lmax=a.rmax=a.sum=a.ans=val;
}

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
    if (l>r){
        SegmentTree res;
        res.l=res.r=res.lmax=res.rmax=res.sum=res.ans=0;
        return res;
    }
    if (l<=t[x].l && r>=t[x].r) return t[x];
    int mid=(t[x].l+t[x].r)>>1;
    SegmentTree a,b,c;
    clear(a,-0x3f3f3f3f); clear(b,-0x3f3f3f3f);
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

int main(){
    scanf("%d",&T);
    while (T--){
        memset(t,0,sizeof t);
        memset(a,0,sizeof a);
        scanf("%d",&n);
        for (int i=1;i<=n;++i) scanf("%d",&a[i]);
        build(1,1,n);
        scanf("%d",&m);
        for (int i=1;i<=m;++i){
            scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
            if (r1<l2) printf("%d\n",ask(1,l1,r1).rmax+ask(1,r1+1,l2-1).sum+ask(1,l2,r2).lmax);
                else{
                    int ans=ask(1,l2,r1).ans;
                    if (l1<l2) ans=max(ans,ask(1,l1,l2).rmax+ask(1,l2,r2).lmax-a[l2]);
                    if (r1<r2) ans=max(ans,ask(1,l1,r1).rmax+ask(1,r1,r2).lmax-a[r1]);
                    printf("%d\n",ans);
                }
        }
    }
    return 0;
}