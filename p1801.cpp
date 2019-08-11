#include<bits/stdc++.h>
using namespace std;
int m,n,i,j,a[200005],u[200005],ls,lb,hs[200005],hb[200005];

void pushs(int x){
    ls++; hs[ls]=x;
    int now=ls,nxt;
    while (now>1){
        nxt=now/2;
        if (hs[nxt]<hs[now]) return;
        int t=hs[nxt]; hs[nxt]=hs[now]; hs[now]=t;
        now=nxt;
    }
}

void pushb(int x){
    lb++; hb[lb]=x;
    int now=lb,nxt;
    while (now>1){
        nxt=now/2;
        if (hb[now]<hb[nxt]) return;
        int t=hb[now]; hb[now]=hb[nxt]; hb[nxt]=t;
        now=nxt;
    }
}

void pops(){
    hs[1]=hs[ls]; ls--;
    int now=1,nxt;
    while (now*2<=ls){
        nxt=now*2;
        if (hs[nxt+1]<hs[nxt] && nxt<ls) nxt++;
        if (hs[now]<=hs[nxt]) return;
        int t=hs[now]; hs[now]=hs[nxt]; hs[nxt]=t;
        now=nxt;
    }
}

void popb(){
    hb[1]=hb[lb]; lb--;
    int now=1,nxt;
    while (now*2<=lb){
        nxt=now*2;
        if (nxt<lb && hb[nxt+1]>hb[nxt]) nxt++;
        if (hb[now]>=hb[nxt]) return;
        int t=hb[now]; hb[now]=hb[nxt]; hb[nxt]=t;
        now=nxt;
    }
}

int main(){
    scanf("%d%d",&m,&n);
    for (i=1;i<=m;++i) scanf("%d",&a[i]);
    for (i=1;i<=n;++i) scanf("%d",&u[i]);
    for (i=1;i<=n;++i){
        for (j=u[i-1]+1;j<=u[i];++j) pushs(a[j]);
        pushb(hs[1]);
        pops();
        while (ls && hs[1]<hb[1]){
            int x=hs[1]; pops();
            int y=hb[1]; popb();
            pushs(y);
            pushb(x);
        }
        printf("%d\n",hb[1]);
    }
    return 0;
}