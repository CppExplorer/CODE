#include<cstdio>
#include<algorithm>
using namespace std;
const int N=100005;
int n,tot,a[N],b[N],root[N],fa[N],head[N],to[N<<1],nxt[N<<1],k,ans[N];
struct SegmentTree{
    int l,r,sum;
}t[N<<5];

void add_edge(int x,int y){
    to[++k]=y; nxt[k]=head[x]; head[x]=k;
}

int build(){
    tot++;
    t[tot].l=t[tot].r=t[tot].sum=0;
    return tot;
}

void insert(int x,int l,int r,int p){
    if (l==r){
        t[x].sum++;
        return;
    }
    int mid=(l+r)>>1;
    if (p<=mid){
        if (!t[x].l) t[x].l=build();
        insert(t[x].l,l,mid,p);
    }else{
        if (!t[x].r) t[x].r=build();
        insert(t[x].r,mid+1,r,p);
    }
    t[x].sum=t[t[x].l].sum+t[t[x].r].sum;
}

int Merge(int p,int q,int l,int r){
    if (!p) return q;
    if (!q) return p;
    if (l==r){
        t[p].sum+=t[q].sum;
        return p;
    }
    int mid=(l+r)>>1;
    t[p].l=Merge(t[p].l,t[q].l,l,mid);
    t[p].r=Merge(t[p].r,t[q].r,mid+1,r);
    t[p].sum=t[t[p].l].sum+t[t[p].r].sum;
    return p;
}

int ask(int x,int ln,int rn,int l,int r){
    if (l<=ln && r>=rn) return t[x].sum;
    int mid=(ln+rn)>>1,val=0;
    if (l<=mid) val+=ask(t[x].l,ln,mid,l,r);
    if (r>mid) val+=ask(t[x].r,mid+1,rn,l,r);
    return val;
}

void dfs(int x){
    for (int i=head[x];i;i=nxt[i]){
        if (fa[x]==to[i]) continue;
        dfs(to[i]);
        root[x]=Merge(root[x],root[to[i]],1,n);
    }
    ans[x]=ask(root[x],1,n,a[x]+1,n);
}

int main(){
    scanf("%d",&n);
    for (int i=1;i<=n;++i) scanf("%d",&b[i]),a[i]=b[i];
    sort(b+1,b+1+n);
    for (int i=1;i<=n;++i) a[i]=lower_bound(b+1,b+1+n,a[i])-b;
    for (int i=1;i<=n;++i){
        root[i]=build();
        insert(root[i],1,n,a[i]);
    }
    for (int i=2;i<=n;++i){
        scanf("%d",&fa[i]);
        add_edge(fa[i],i);
        add_edge(i,fa[i]);
    }
    dfs(1);
    for (int i=1;i<=n;++i) printf("%d\n",ans[i]);
    return 0;
}