#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cmath>
using namespace std;
const int N=100005;
int n,m,x,y,z,head[N],to[N<<1],nxt[N<<1],k,f[N][20],tn,d[N];
int X[N],Y[N],Z[N],cnt,b[N],a[N],root[N],tot,ans[N];
bool vis[N];
struct SegmentTree{
    int l,r,max,pos;
}t[N<<6];

void add_edge(int x,int y){
    to[++k]=y; nxt[k]=head[x]; head[x]=k;
}

void dfs_father(int x,int fa){
    vis[x]=1; d[x]=d[fa]+1;
    f[x][0]=fa;
    for (int i=1;(1<<i)<=d[x];++i)
        f[x][i]=f[f[x][i-1]][i-1];
    for (int i=head[x];i;i=nxt[i]){
        if (vis[to[i]]) continue;
        dfs_father(to[i],x);
    }
}

int lca(int x,int y){
    if (d[x]>d[y]) swap(x,y);
    for (int i=tn;i>=0;--i)
        if (d[f[y][i]]>=d[x]) y=f[y][i];
    if (x==y) return x;
    for (int i=tn;i>=0;--i)
        if (f[x][i]!=f[y][i]) x=f[x][i],y=f[y][i];
    return f[x][0];
}

int build(){
    tot++;
    t[tot].l=t[tot].r=t[tot].max=t[tot].pos=0;
    return tot;
}

void insert(int x,int l,int r,int p,int val){
    if (l==r){
        t[x].max+=val;
        t[x].pos=(t[x].max?l:0);
        return;
    }
    int mid=(l+r)>>1;
    if (p<=mid){
        if (!t[x].l) t[x].l=build();
        insert(t[x].l,l,mid,p,val);
    }else{
        if (!t[x].r) t[x].r=build();
        insert(t[x].r,mid+1,r,p,val);
    }
    t[x].max=max(t[t[x].l].max,t[t[x].r].max);
    t[x].pos=(t[t[x].l].max>=t[t[x].r].max?t[t[x].l].pos:t[t[x].r].pos);
}

int Merge(int p,int q,int l,int r){
    if (!p) return q;
    if (!q) return p;
    if (l==r){
        t[p].max+=t[q].max;
        t[p].pos=(t[p].max?l:0);
        return p;
    }
    int mid=(l+r)>>1;
    t[p].l=Merge(t[p].l,t[q].l,l,mid);
    t[p].r=Merge(t[p].r,t[q].r,mid+1,r);
    t[p].max=max(t[t[p].l].max,t[t[p].r].max);
    t[p].pos=(t[t[p].l].max>=t[t[p].r].max?t[t[p].l].pos:t[t[p].r].pos);
    return p;
}

void dfs_ans(int x){
    for (int i=head[x];i;i=nxt[i]){
        if (to[i]==f[x][0]) continue;
        dfs_ans(to[i]);
        root[x]=Merge(root[x],root[to[i]],1,cnt);
    }
    ans[x]=t[root[x]].pos;
}

int main(){
    scanf("%d%d",&n,&m);
    tn=(int)(log(n)/log(2))+1;
    for (int i=1;i<n;++i){
        scanf("%d%d",&x,&y);
        add_edge(x,y);
        add_edge(y,x);
    }
    for (int i=1;i<=n;++i) root[i]=build();
    dfs_father(1,0);
    for (int i=1;i<=m;++i) scanf("%d%d%d",&X[i],&Y[i],&Z[i]),b[i]=Z[i];
    sort(b+1,b+1+m);
    for (int i=1;i<=m;++i)
        if (i==1 || b[i]!=b[i-1]) a[++cnt]=b[i];
    for (int i=1;i<=m;++i){
        x=X[i]; y=Y[i];
        z=lower_bound(a+1,a+1+cnt,Z[i])-a;
        insert(root[x],1,cnt,z,1);
        insert(root[y],1,cnt,z,1);
        int fa=lca(x,y);
        insert(root[fa],1,cnt,z,-1);
        if (f[fa][0]) insert(root[f[fa][0]],1,cnt,z,-1);
    }
    dfs_ans(1);
    for (int i=1;i<=n;++i) printf("%d\n",a[ans[i]]);
    return 0;
}