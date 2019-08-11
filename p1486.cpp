#include<bits/stdc++.h>
#define INF 0x7fffffff
using namespace std;
int n,low,i,add,k,leave,tot,root,num,cnt,x,y;
char opt;
struct Treap{
    int l,r,val,dat,size,cnt;
}a[300005];

int New(int val){
    tot++;
    a[tot].val=val;
    a[tot].dat=rand();
    a[tot].size=1; a[tot].cnt=1;
    return tot;
}

void update(int p){
    a[p].size=a[a[p].l].size+a[a[p].r].size+a[p].cnt;
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

int GetPre(int val){
    int ans=1,p=root;
    while (p){
        if (val==a[p].val){
            ans=p;
            break;
        }
        if (a[p].val<val && a[p].val>a[ans].val) ans=p;
        if (val<a[p].val) p=a[p].l;
            else p=a[p].r;
    }
    return a[ans].val;
}

int GetVal(int p,int rank){
    if (p==0) return INF;
    if (a[a[p].l].size>=rank) return GetVal(a[p].l,rank);
    if (a[a[p].l].size+a[p].cnt>=rank) return a[p].val;
    return GetVal(a[p].r,rank-a[a[p].l].size-a[p].cnt);
}

void insert(int &p,int val){
    if (p==0){
        p=New(val);
        return;
    }
    if (val==a[p].val){
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

void remove(int &p,int val){
    if (p==0) return;
    if (val==a[p].val){
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
    build();
    scanf("%d%d",&n,&low);
    for (i=1;i<=n;++i){
        scanf("\n%c%d",&opt,&k);
        switch (opt){
            case 'I':
                if (k-add>=low){
                    insert(root,k-add);
                    num++; cnt++;
                }
                break;
            case 'A':
                add+=k; low-=k;
                break;
            case 'S':
                add-=k; low+=k;
                x=low-1;
                while (GetPre(x)!=-INF){
                    y=x; x=GetPre(x);
                    remove(root,GetPre(y));
                    num--;
                }
                break;
            case 'F':
                if (num<k){printf("-1\n"); break;}
                printf("%d\n",GetVal(root,num-k+2)+add);
                break;
        }
    }
    printf("%d",cnt-num);
    return 0;
}