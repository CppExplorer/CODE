#include<cstdio>
using namespace std;
const int N=10000;
int T,n,No,hd[N],hx[N],ld,lx,x,cnt;

void pushd(int x){
    hd[++ld]=x;
    int now=ld,nxt;
    while (now>1){
        nxt=now>>1;
        if (hd[nxt]>hd[now]) return;
        int t=hd[nxt]; hd[nxt]=hd[now]; hd[now]=t;
        now=nxt;
    }
}

void popd(){
    hd[1]=hd[ld--];
    int now=1,nxt;
    while (now*2<=ld){
        nxt=now*2;
        if (nxt<ld && hd[nxt+1]>hd[nxt]) nxt++;
        if (hd[nxt]<hd[now]) return;
        int t=hd[nxt]; hd[nxt]=hd[now]; hd[now]=t;
        now=nxt;
    }
}

void pushx(int x){
    hx[++lx]=x;
    int now=lx,nxt;
    while (now>1){
        nxt=now>>1;
        if (hx[nxt]<hx[now]) return;
        int t=hx[nxt]; hx[nxt]=hx[now]; hx[now]=t;
        now=nxt;
    }
}

void popx(){
    hx[1]=hx[lx--];
    int now=1,nxt;
    while (now*2<=lx){
        nxt=now*2;
        if (nxt<lx && hx[nxt+1]<hx[nxt]) nxt++;
        if (hx[nxt]>hx[now]) return;
        int t=hx[nxt]; hx[nxt]=hx[now]; hx[now]=t;
        now=nxt;
    }
}

int main(){
    scanf("%d",&T);
    while (T--){
        scanf("%d%d",&No,&n);
        printf("%d %d\n",No,(n+1)>>1);
        ld=lx=cnt=0;
        for (int i=1;i<=n;++i){
            scanf("%d",&x);
            if (x<hd[1]) pushd(x);
                else pushx(x);
            if (ld-lx==2){
                int t=hd[1]; popd();
                pushx(t); 
            }
            if (lx-ld==2){
                int t=hx[1]; popx();
                pushd(t); 
            }
            //printf("%d %d %d %d %d\n",i,hx[1],hd[1],lx,ld);
            if (i&1){
                if (ld>lx) printf("%d ",hd[1]);
                    else printf("%d ",hx[1]);
                cnt++;
            }
            if (cnt==10){
                printf("\n");
                cnt=0;
            }
        }
        printf("\n");
    }
    return 0;
}