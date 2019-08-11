#include<bits/stdc++.h>
using namespace std;
int hd[100005],hx[100005],ld,lx,n,a[100005],i;

void pushx(int x){
    lx++; hx[lx]=x;
    int now=lx,nxt;
    while (now>1){
        nxt=now/2;
        if (hx[nxt]<hx[now]) return;
        int t=hx[nxt]; hx[nxt]=hx[now]; hx[now]=t;
        now=nxt;
    }
}

void pushd(int x){
    ld++; hd[ld]=x;
    int now=ld,nxt;
    while (now>1){
        nxt=now/2;
        if (hd[nxt]>hd[now]) return;
        int t=hd[nxt]; hd[nxt]=hd[now]; hd[now]=t;
        now=nxt;
    }
}

void popd(){
    hd[1]=hd[ld]; ld--;
    int now=1,nxt;
    while (now*2<=ld){
        nxt=now*2;
        if (nxt<ld && hd[nxt+1]>hd[nxt]) nxt++;
        if (hd[nxt]<=hd[now]) return;
        int t=hd[nxt]; hd[nxt]=hd[now]; hd[now]=t;
        now=nxt;
    }
}

void popx(){
    hx[1]=hx[lx]; lx--;
    int now=1,nxt;
    while (now*2<=lx){
        nxt=now*2;
        if (nxt<lx && hx[nxt+1]<hx[nxt]) nxt++;
        if (hx[nxt]>=hx[now]) return;
        int t=hx[nxt]; hx[nxt]=hx[now]; hx[now]=t;
        now=nxt;
    }
}

int main(){
    scanf("%d",&n);
    for (i=1;i<=n;++i) scanf("%d",&a[i]);
    pushd(a[1]); printf("%d\n",a[1]);
    for (i=2;i<=n;++i){
        if (a[i]>=hd[1]) pushx(a[i]);
            else pushd(a[i]);
        while (abs(ld-lx)>1){
            if (ld>lx){
                pushx(hd[1]);
                popd();
            }else{
                pushd(hx[1]);
                popx();
            }
        }
        if (i%2){
            if (ld>lx) printf("%d\n",hd[1]);
            else printf("%d\n",hx[1]);
        }
    }
    return 0;
}