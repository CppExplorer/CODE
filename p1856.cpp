#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
const int N=10005;
int n,Minx=0x7f7f7f7f,Maxx=-0x7f7f7f7f,Miny=0x7f7f7f7f,Maxy=-0x7f7f7f7f,lst;
long long ans;
struct Edge{
    int x,l,r,k;
}a[N],b[N];
struct SegmentTree{
    int cnt,len;
}t[N<<4];

bool cmp(Edge a,Edge b){
    return a.x==b.x?a.k>b.k:a.x<b.x;
}

void update(int p,int l,int r){
    if (t[p].cnt) t[p].len=r-l+1;
        else t[p].len=t[p<<1].len+t[(p<<1)|1].len;
}

void change(int p,int nowl,int nowr,int l,int r,int k){
    if (nowl>r || nowr<l) return;
    if (l<=nowl && r>=nowr){
        t[p].cnt+=k;
        update(p,nowl,nowr);
        return;
    }
    int mid=(nowl+nowr)>>1;
    change(p<<1,nowl,mid,l,r,k);
    change((p<<1)|1,mid+1,nowr,l,r,k);
    update(p,nowl,nowr);
}

int main(){
    scanf("%d",&n);
    for (int i=1,x1,y1,x2,y2;i<=n;++i){
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        a[(i<<1)-1]=(Edge){x1,y1,y2,1};
        a[i<<1]=(Edge){x2,y1,y2,-1};
        b[(i<<1)-1]=(Edge){y1,x1,x2,1};
        b[i<<1]=(Edge){y2,x1,x2,-1};
        Minx=min(Minx,x1),Maxx=max(Maxx,x2);
        Miny=min(Miny,y1),Maxy=max(Maxy,y2);
    }
    n<<=1;
    sort(a+1,a+1+n,cmp);
    sort(b+1,b+1+n,cmp);
    for (int i=1;i<=n;++i){
        change(1,Miny,Maxy,a[i].l+1,a[i].r,a[i].k);
        ans+=abs(t[1].len-lst); lst=t[1].len;
    }
    memset(t,0,sizeof t); lst=0;
    for (int i=1;i<=n;++i){
        change(1,Minx,Maxx,b[i].l+1,b[i].r,b[i].k);
        ans+=abs(t[1].len-lst); lst=t[1].len;
    }
    printf("%lld",ans);
    return 0;
}