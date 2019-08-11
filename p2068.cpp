#include<bits/stdc++.h>
using namespace std;
int n,w,i,a,b;
char c;
struct SegmentTree{
    int l,r;
    long long sum;
}t[400005];

void build(int x,int l,int r){
    t[x].l=l; t[x].r=r;
    if (l==r) return;
    int mid=(l+r)/2;
    build(x*2,l,mid);
    build(x*2+1,mid+1,r);
}

void change(int p,int x,int v){
    if (t[p].l==t[p].r){
        t[p].sum+=v;
        return;
    }
    int mid=(t[p].l+t[p].r)/2;
    if (x<=mid) change(p*2,x,v);
        else change(p*2+1,x,v);
    t[p].sum=t[p*2].sum+t[p*2+1].sum;
}

int ask(int x,int l,int r){
    if (l<=t[x].l && r>=t[x].r) return t[x].sum;
    int val=0,mid=(t[x].l+t[x].r)/2;
    if (l<=mid) val+=ask(x*2,l,r);
    if (r>mid) val+=ask(x*2+1,l,r);
    return val;
}

int main(){
    scanf("%d%d",&n,&w);
    build(1,1,n);
    for (i=1;i<=w;++i){
        scanf("\n%c%d%d",&c,&a,&b);
        if (c=='x') change(1,a,b);
            else printf("%d\n",ask(1,a,b));
    }
    return 0;
}