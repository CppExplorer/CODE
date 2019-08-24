#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=2e4+5;
int n,w,h,num,id1[N],id2[N];
long long b[N],c[N];
struct Edge{
    long long x,l,r,c;
}a[N];
struct SegmentTree{
    long long add,max;
}t[N<<4];

bool cmp(Edge a,Edge b){
    return a.x==b.x?a.c>b.c:a.x<b.x;
}

int query(long long x){
    return lower_bound(c+1,c+1+num,x)-c;
}

void spread(int p,int l,int r){
    if (t[p].add){
        t[p<<1].add+=t[p].add,t[(p<<1)|1].add+=t[p].add;
        t[p<<1].max+=t[p].add,t[(p<<1)|1].max+=t[p].add;
        t[p].add=0;
    }
}

void add(int p,int nowl,int nowr,int l,int r,long long c){
    if (nowl>r || nowr<l) return;
    if (l<=nowl && r>=nowr){
        t[p].add+=c,t[p].max+=c;
        return;
    }
    spread(p,nowl,nowr);
    int mid=(nowl+nowr)>>1;
    add(p<<1,nowl,mid,l,r,c);
    add((p<<1)|1,mid+1,nowr,l,r,c);
    t[p].max=max(t[p<<1].max,t[(p<<1)|1].max);
}

int main(){
    while (scanf("%d%d%d",&n,&w,&h)==3){
        for (int i=1;i<=n;++i){
            long long x,y,z;
            scanf("%lld%lld%lld",&x,&y,&z);
            a[(i<<1)-1]=(Edge){x,y,y+h-1,z};
            a[i<<1]=(Edge){x+w-1,y,y+h-1,-z};
            b[(i<<1)-1]=y; b[i<<1]=y+h-1;
        }
        n<<=1; num=0;
        sort(a+1,a+1+n,cmp);
        sort(b+1,b+1+n);
        for (int i=1;i<=n;++i)
            if (i==1 || b[i]!=b[i-1]) c[++num]=b[i];
        for (int i=1;i<=n;++i){
            int x=query(a[i].l),y=query(a[i].r);
            id1[i]=x,id2[i]=y;
        }
        long long ans=-0x7f7f7f7f7f7f7f7f;
        memset(t,0,sizeof t);
        for (int i=1;i<=n;++i){
            add(1,1,num,id1[i],id2[i],a[i].c);
            ans=max(ans,t[1].max);
        }
        printf("%lld\n",ans);
    }
    return 0;
}