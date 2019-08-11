#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,T,a[105][2005],l,ans[2005],temp[2005];
struct heap{
    int x,y,val;
    bool last;
}h[5000];

void push(int i,int j,bool flag,int x){
    h[++l].x=i; h[l].y=j; h[l].val=ans[i]+a[x][j]; h[l].last=flag;
    int now=l,nxt;
    while (now>1){
        nxt=now>>1;
        if (h[nxt].val<h[now].val) return;
        heap t=h[nxt]; h[nxt]=h[now]; h[now]=t;
        now=nxt;
    }
}

void pop(){
    h[1]=h[l--];
    int now=1,nxt;
    while (now*2<=l){
        nxt=now*2;
        if (nxt<l && h[nxt+1].val<h[nxt].val) nxt++;
        if (h[now].val<h[nxt].val) return;
        heap t=h[now]; h[now]=h[nxt]; h[nxt]=t;
        now=nxt;
    }
}

int main(){
    scanf("%d",&T);
    while (T--){
        scanf("%d%d",&m,&n);
        for (int i=1;i<=m;++i){
            for (int j=1;j<=n;++j) scanf("%d",&a[i][j]);
            sort(a[i]+1,a[i]+1+n);
        }
        for (int i=1;i<=n;++i) ans[i]=a[1][i];
        for (int i=2;i<=m;++i){
            l=0;
            push(1,1,false,i);
            for (int j=1;j<=n;++j){
                heap x=h[1]; pop();
                temp[j]=x.val;
                push(x.x,x.y+1,true,i);
                if (x.last==false) push(x.x+1,x.y,false,i);
            }
            for (int j=1;j<=n;++j) ans[j]=temp[j];
        }
        for (int i=1;i<=n;++i) printf("%d ",ans[i]);
        printf("\n");
    }
    return 0;
}