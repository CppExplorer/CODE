#include<bits/stdc++.h>
#define INF 0x7fffffff
using namespace std;
int n,m,i,tot,ans[50005],root,b[300005];
struct Treap{
    int l,r,size,val,dat;
}a[300005];
struct Questions{
    int l,r,k,id;
}que[50005];

bool cmp(Questions x,Questions y){
    if (x.l==y.r) return x.r<y.r;
    return x.l<y.l; 
}

void update(int x){
    a[x].size=a[a[x].l].size+a[a[x].r].size+1;
}

int New(int val){
    tot++;
    a[tot].val=val;
    a[tot].dat=rand();
    a[tot].size=1;
    return tot;
}

void build(){
    New(-INF); New(INF);
    root=1; a[1].r=2;
    update(root);
}

void TurnRight(int &p){
    int q=a[p].l;
    a[p].l=a[q].r; a[q].r=p; p=q;
    update(a[p].r); update(p);
}

void TurnLeft(int &p){
    int q=a[p].r;
    a[p].r=a[q].l; a[q].l=p; p=q;
    update(a[p].l); update(p);
}

int GetValByRank(int p,int rank){
    if (p==0) return INF;
    if (a[a[p].l].size>=rank) return GetValByRank(a[p].l,rank);
    if (a[a[p].l].size+1==rank) return a[p].val;
    return GetValByRank(a[p].r,rank-a[a[p].l].size-1);
}

void insert(int &p,int val){
    if (p==0){
        p=New(val);
        return;
    }
    if (val<a[p].val){
        insert(a[p].l,val);
        if (a[p].dat<a[a[p].l].dat) TurnRight(p);
    }else{
        insert(a[p].r,val);
        if (a[p].dat<a[a[p].r].dat) TurnLeft(p);
    }
    update(p);
}

void remove(int &p,int val){
    if (p==0) return;
    if (val==a[p].val){
        if (a[p].l || a[p].r){
            if (a[p].r==0 || a[a[p].l].dat>a[a[p].r].dat){
                TurnRight(p); remove(a[p].r,val);
            }else{
                TurnLeft(p); remove(a[p].l,val);
            }
            update(p);
        }else p=0;
        return;
    }
    if (val<a[p].val) remove(a[p].l,val);
        else remove(a[p].r,val);
    update(p);
}

int main(){
    build();
    scanf("%d%d",&n,&m);
    for (i=1;i<=n;++i) scanf("%d",&b[i]);
    for (i=1;i<=m;++i){
        scanf("%d%d%d",&que[i].l,&que[i].r,&que[i].k);
        que[i].id=i;
    }
    sort(que+1,que+1+m,cmp);
    int l=1,r=0;
    for (i=1;i<=m;++i){
        while (r<que[i].r){r++; insert(root,b[r]);}
        while (l<que[i].l){remove(root,b[l]); l++;}
        ans[que[i].id]=GetValByRank(root,que[i].k+1);
    }
    for (i=1;i<=m;++i) printf("%d\n",ans[i]);
    return 0;
}