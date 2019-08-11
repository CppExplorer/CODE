#include<bits/stdc++.h>
using namespace std;
int n,i,l=INT_MAX,r,colour,lt,ans;
bool d[400005];
struct SegmentTree{
    int l,r,cor;
    bool same;
}t[400005];
struct question{
    int l,r;
    char cmd;
}q[200005];

void build(int x,int l,int r){
    t[x].l=l; t[x].r=r; t[x].same=1;
    if (l==r) return;
    int mid=(l+r)>>1;
    build(x*2,l,mid);
    build(x*2+1,mid+1,r);
}

void paint(int x){
    if (t[x].same){
        if (t[x].cor && !d[t[x].cor]){
            ans--; lt++;
        }
        d[t[x].cor]=1;
        t[x].cor=colour;
        return;
    }
    paint(x*2);
    paint(x*2+1);
    t[x].same=1; t[x].cor=colour;
}

void spread(int x){
    t[x].same=0;
    if (!t[x].cor) return;
    t[x*2].cor=t[x].cor;
    t[x*2+1].cor=t[x].cor;
    t[x].cor=0;
}

void change(int x,int l,int r){
    if (l<=t[x].l && r>=t[x].r){
        paint(x);
        return;
    }
    spread(x);
    int mid=(t[x].l+t[x].r)>>1;
    if (l<=mid) change(x*2,l,r);
    if (r>mid) change(x*2+1,l,r);
}

int main(){
    scanf("%d",&n);
    for (i=1;i<=n;++i){
        scanf("\n%c",&q[i].cmd);
        if (q[i].cmd=='A'){
            scanf("%d%d",&q[i].l,&q[i].r);
            l=min(l,q[i].l); r=max(r,q[i].r);
        }
    }
    build(1,l,r);
    for (i=1;i<=n;++i)
        if (q[i].cmd=='A'){
            colour++; ans++; lt=0;
            change(1,q[i].l,q[i].r);
            printf("%d\n",lt);
        }else printf("%d\n",ans);
    return 0;
}