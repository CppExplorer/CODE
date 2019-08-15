#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=205;
int n,num,id1[N],id2[N],tot;
double b[N],c[N],val[N];
struct Edge{
    double x,l,r;
    int k;
}a[N];
struct SegmentTree{
    int cnt;
    double len;
}t[N<<7];

bool cmp(Edge a,Edge b){
    return a.x<b.x;
}

int query(double x){
    return lower_bound(c+1,c+1+num,x)-c;
}

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

int main(){
    while (scanf("%d",&n) && n){
        double ans=0;
        for (int i=1;i<=n;++i){
            double x1,y1,x2,y2;
            scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
            a[(i<<1)-1]=(Edge){x1,y1,y2,1};
            a[i<<1]=(Edge){x2,y1,y2,-1};
            b[(i<<1)-1]=y1;
            b[i<<1]=y2;
        }
        n<<=1; num=0;
        sort(a+1,a+1+n,cmp);
        sort(b+1,b+1+n);
        memset(t,0,sizeof t);
        for (int i=1;i<=n;++i)
            if (i==1 || b[i]!=b[i-1]) c[++num]=b[i];
        for (int i=1;i<=n;++i){
            int mx=query(a[i].l),my=query(a[i].r);
            id1[i]=mx,id2[i]=my;
            val[mx]=a[i].l,val[my]=a[i].r;
        }
        for (int i=1;i<n;++i){
            change(1,1,n,id1[i]+1,id2[i],a[i].k);
            ans+=t[1].len*(a[i+1].x-a[i].x);
        }
        printf("Test case #%d\nTotal explored area: %.2f\n\n",++tot,ans);
    }
    return 0;
}