#include<bits/stdc++.h>
using namespace std;
int root,opt,x,n,i,tot;
const int INF=INT_MAX;
struct Treap{
    int l,r,size,cnt,val,dat;
}a[100005];

int New(int val){
    tot++;
    a[tot].val=val;
    a[tot].dat=rand();
    a[tot].cnt=1; a[tot].size=1;
    return tot;
}

void update(int p){
    a[p].size=a[a[p].l].size+a[a[p].r].size+a[p].cnt;
}

void build(){
    New(-INF); New(INF);
    root=1; a[root].r=2;
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

void insert(int &p,int val){
    if (p==0){
        p=New(val);
        return;
    }
    if (a[p].val==val){
        a[p].cnt++; update(p);
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

int GetRankByVal(int p,int val){
    if (p==0) return 0;
    if (val==a[p].val) return a[a[p].l].size+1;
    if (val<a[p].val) return GetRankByVal(a[p].l,val);
    return GetRankByVal(a[p].r,val)+a[a[p].l].size+a[p].cnt;
}

int GetValByRank(int p,int rank){
    if (p==0) return INF;
    if (a[a[p].l].size>=rank) return GetValByRank(a[p].l,rank);
    if (a[a[p].l].size+a[p].cnt>=rank) return a[p].val;
    return GetValByRank(a[p].r,rank-a[a[p].l].size-a[p].cnt);
}

int GetPre(int val){
    int ans=1,p=root;
    while (p){
        if (val==a[p].val){
            if (a[p].l){
                p=a[p].l;
                while (a[p].r) p=a[p].r;
                ans=p;
            }
            break;
        }
        if (a[p].val<val && a[p].val>a[ans].val) ans=p;
        if (val<a[p].val) p=a[p].l;
            else p=a[p].r;
    }
    return a[ans].val;
}

int GetNext(int val){
    int ans=2,p=root;
    while (p){
        if (val==a[p].val){
            if (a[p].r){
                p=a[p].r;
                while (a[p].l) p=a[p].l;
                ans=p;
            }
            break;
        }
        if (val<a[p].val && a[p].val<a[ans].val) ans=p;
        if (val<a[p].val) p=a[p].l;
            else p=a[p].r;
    }
    return a[ans].val;
}

void remove(int &p,int val){
    if (p==0) return;
    if (a[p].val==val){
        if (a[p].cnt>1){
            a[p].cnt--; update(p);
            return;
        }
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
    scanf("%d",&n);
    build();
    for (i=1;i<=n;++i){
        scanf("%d%d",&opt,&x);
        switch (opt){
            case 1:
                insert(root,x);
                break;
            case 2:
                remove(root,x);
                break;
            case 3:
                printf("%d\n",GetRankByVal(root,x)-1);
                break;
            case 4:
                printf("%d\n",GetValByRank(root,x+1));
                break;
            case 5:
                printf("%d\n",GetPre(x));
                break;
            case 6:
                printf("%d\n",GetNext(x));
                break;
        }
    }
    return 0;
}