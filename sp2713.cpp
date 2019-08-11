#include<bits/stdc++.h>
using namespace std;
int n,x,y,m,cmd,T;
long long a[100005];
struct SegmentTree{
    int l,r;
    long long sum,max;
}t[400005];

void build(int x,int l,int r){
    t[x].l=l; t[x].r=r;
    if (l==r){
        t[x].sum=a[l];
        t[x].max=a[l];
        return;
    }
    int mid=(l+r)>>1;
    build(x*2,l,mid);
    build(x*2+1,mid+1,r);
    t[x].sum=t[x*2].sum+t[x*2+1].sum;
    t[x].max=max(t[x*2].max,t[x*2+1].max);
}

void extract(int x,int l,int r){
    if (t[x].l==t[x].r){
        t[x].sum=(int)sqrt(t[x].sum);
        t[x].max=(int)sqrt(t[x].max);
        return;
    }
    int mid=(t[x].l+t[x].r)>>1;
    if (l<=mid){
        if (t[x*2].max>1) extract(x*2,l,r);
    }
    if (r>mid){
        if (t[x*2+1].max>1) extract(x*2+1,l,r);
    }
    t[x].sum=t[x*2].sum+t[x*2+1].sum;
    t[x].max=max(t[x*2].max,t[x*2+1].max);
}

long long asksum(int x,int l,int r){
    if (l<=t[x].l && r>=t[x].r) return t[x].sum;
    int mid=(t[x].l+t[x].r)>>1;
    long long ans=0;
    if (l<=mid) ans+=asksum(x*2,l,r);
    if (r>mid) ans+=asksum(x*2+1,l,r);
    return ans;
}

int main(){
    while (scanf("%d",&n)!=EOF){
        T++;
        printf("Case #%d:\n",T);
        for (int i=1;i<=n;++i) scanf("%lld",&a[i]);
        build(1,1,n);
        scanf("%d",&m);
        for (int i=1;i<=m;++i){
            scanf("%d%d%d",&cmd,&x,&y);
            if (x>y) swap(x,y);
            if (cmd==0) extract(1,x,y);
                else printf("%lld\n",asksum(1,x,y));
        }
        printf("\n");
    }
    return 0;
}