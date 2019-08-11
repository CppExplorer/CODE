#include<cstdio>
#include<cstdlib>
using namespace std;
const int N=1e5+5,INF=0x7f7f7f7f;
int n,cmd,x,tot,root;
struct Treap{
    int l,r,val,dat,size,cnt;
}a[N];
 
void update(int p){
    a[p].size=a[a[p].l].size+a[a[p].r].size+a[p].cnt;
}
 
int New(int val){
    a[++tot].val=val;
    a[tot].dat=rand();
    a[tot].size=a[tot].cnt=1;
    return tot;
}
 
void build(){
    New(-INF); New(INF);
    root=1; a[1].r=2;
    update(root);
}
 
void zig(int &p){
    int q=a[p].l;
    a[p].l=a[q].r; a[q].r=p; p=q;
    update(a[p].r); update(p);
}
 
void zag(int &p){
    int q=a[p].r;
    a[p].r=a[q].l; a[q].l=p; p=q;
    update(a[p].l); update(p);
}
 
void insert(int &p,int val){
    if (!p){
        p=New(val);
        return;
    }
    if (a[p].val==val){
        a[p].cnt++; update(p);
        return;
    }
    if (val<a[p].val){
        insert(a[p].l,val);
        if (a[a[p].l].dat>a[p].dat) zig(p);
    }else{
        insert(a[p].r,val);
        if (a[a[p].r].dat>a[p].dat) zag(p);
    }
    update(p);
}
 
void remove(int &p,int val){
    if (!p) return;
    if (a[p].val==val){
        if (a[p].cnt>1){
            a[p].cnt--; update(p);
            return;
        }
        if (a[p].l || a[p].r){
            if (!a[p].r || a[a[p].l].dat>a[a[p].r].dat) zig(p),remove(a[p].r,val);
                else zag(p),remove(a[p].l,val);
            update(p);
        }else p=0;
        return;
    }
    if (val<a[p].val) remove(a[p].l,val);
        else remove(a[p].r,val);
    update(p);
}
 
int GetRank(int p,int val){
    if (!p) return 0;
    if (a[p].val==val) return a[a[p].l].size+1;
    if (val<a[p].val) return GetRank(a[p].l,val);
    return GetRank(a[p].r,val)+a[a[p].l].size+a[p].cnt;
}
 
int GetVal(int p,int rank){
    if (!p) return INF;
    if (rank<=a[a[p].l].size) return GetVal(a[p].l,rank);
    if (rank<=a[a[p].l].size+a[p].cnt) return a[p].val;
    return GetVal(a[p].r,rank-a[a[p].l].size-a[p].cnt);
}
 
int GetPre(int p,int val){
    int ans=1;
    while (p){
        if (a[p].val==val){
            if (a[p].l){
                p=a[p].l;
                while (a[p].r) p=a[p].r;
                ans=p;
            }
            break;
        }
        if (a[p].val<val && a[p].val>a[ans].val) ans=p;
        p=val<a[p].val?a[p].l:a[p].r;
    }
    return a[ans].val;
}
 
int GetNext(int p,int val){
    int ans=2;
    while (p){
        if (a[p].val==val){
            if (a[p].r){
                p=a[p].r;
                while (a[p].l) p=a[p].l;
                ans=p;
            }
            break;
        }
        if (a[p].val>val && a[p].val<a[ans].val) ans=p;
        p=val<a[p].val?a[p].l:a[p].r;
    }
    return a[ans].val;
}
 
int main(){
    build();
    scanf("%d",&n);
    for (int i=1;i<=n;++i){
        scanf("%d%d",&cmd,&x);
        switch (cmd){
        case 1:
            insert(root,x);
            break;
        case 2:
            remove(root,x);
            break;
        case 3:
            printf("%d\n",GetRank(root,x)-1);
            break;
        case 4:
            printf("%d\n",GetVal(root,x+1));
            break;
        case 5:
            printf("%d\n",GetPre(root,x));
            break;
        case 6:
            printf("%d\n",GetNext(root,x));
            break;
        }
    }
    return 0;
}