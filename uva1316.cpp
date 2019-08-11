#include<cstdio>
#include<algorithm>
using namespace std;
const int N=10005;
int n,h[N],m,ans;
struct goods{
    int v,t;
}a[N];

bool cmp(goods x,goods y){
    return x.t<y.t;
}

void up(){
    int now=m,nxt;
    while (now>1){
        nxt=now>>1;
        if (a[h[nxt]].v<a[h[now]].v) return;
        int t=h[nxt]; h[nxt]=h[now]; h[now]=t;
        now=nxt;
    }
}

void down(){
    int now=1,nxt;
    while (now*2<=m){
        nxt=now*2;
        if (nxt<m && a[h[nxt+1]].v<a[h[nxt]].v) nxt++;
        if (a[h[nxt]].v>=a[h[now]].v) return;
        int t=h[nxt]; h[nxt]=h[now]; h[now]=t;
        now=nxt;
    }
}

int main(){
    while (scanf("%d",&n)==1){
        m=0; ans=0;
        for (int i=1;i<=n;++i) scanf("%d%d",&a[i].v,&a[i].t);
        sort(a+1,a+1+n,cmp);
        for (int i=1;i<=n;++i)
            if (m==a[i].t){
                if (a[h[1]].v<a[i].v){
                    h[1]=i; down();
                }
            }else{
                h[++m]=i; up();
            }
        for (int i=1;i<=m;++i) ans+=a[h[i]].v;
        printf("%d\n",ans);
    }
    return 0;
}