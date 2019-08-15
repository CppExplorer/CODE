#include<cstdio>
#include<algorithm>
using namespace std;
const int N=2e5+5;
int n,m,b[N],c[N],num,val[N],id1[N],id2[N];
long long ans;
struct Matrix{
    int x,y1,y2,k;
}a[N];
struct SegmentTree{
    int cnt;
    long long len;
}t[N<<3];

void update(int p,int l,int r){
    if (t[p].cnt) t[p].len=val[r]-val[l-1];
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

bool cmp(Matrix a,Matrix b){
    return a.x<b.x;
}

int query(int x){
    return lower_bound(c+1,c+1+num,x)-c;
}

int main(){
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    scanf("%d",&n);
    for (int i=1,x1,y1,x2,y2;i<=n;++i){
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        a[++m]=(Matrix){x1,y1,y2,1}; b[m]=y1;
        a[++m]=(Matrix){x2,y1,y2,-1}; b[m]=y2;
    }
    sort(a+1,a+1+m,cmp);
    sort(b+1,b+1+m);
    for (int i=1;i<=m;++i)
        if (i==1 || b[i]!=b[i-1]) c[++num]=b[i];
    for (int i=1;i<=m;++i) val[query(b[i])]=b[i];
    for (int i=1;i<=m;++i) id1[i]=query(a[i].y1),id2[i]=query(a[i].y2);
    for (int i=1;i<m;++i){
        change(1,1,m,id1[i]+1,id2[i],a[i].k);
        ans+=t[1].len*1LL*(a[i+1].x-a[i].x);
    }
    printf("%lld",ans);
    return 0;
}