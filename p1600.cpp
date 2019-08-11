#include<cstdio>
#include<cmath>
#include<queue>
#include<vector>
using namespace std;
const int N=3e5+5;
int n,m,head[N],nxt[N<<1],to[N<<1],tot,x,y,w[N],f[N][20],d[N],t,c1[N<<1],c2[N<<1],ans[N];
bool vis[N];
queue<int> q;
vector<int> a1[N],b1[N],a2[N],b2[N];

void add_edge(int x,int y){
    to[++tot]=y; nxt[tot]=head[x]; head[x]=tot;
}

void bfs(){
    q.push(1); d[1]=1;
    while (!q.empty()){
        int x=q.front(); q.pop();
        for (int i=head[x];i;i=nxt[i]){
            int y=to[i];
            if (d[y]) continue;
            f[y][0]=x; d[y]=d[x]+1;
            for (int j=1;j<=t;++j)
                f[y][j]=f[f[y][j-1]][j-1];
            q.push(y);
        }
    }
}

int lca(int x,int y){
    if (d[x]>d[y]) swap(x,y);
    for (int i=t;i>=0;--i)
        if (d[f[y][i]]>=d[x]) y=f[y][i];
    if (x==y) return x;
    for (int i=t;i>=0;--i)
        if (f[x][i]!=f[y][i]) x=f[x][i],y=f[y][i];
    return f[x][0];
}

void dfs(int x){
    vis[x]=1;
    int ori1=c1[d[x]+w[x]],ori2=c2[w[x]-d[x]+n];
    for (int i=head[x];i;i=nxt[i]){
        if (vis[to[i]]) continue;
        dfs(to[i]);
    }
    for (int i=0;i<a1[x].size();++i) c1[a1[x][i]]++;
    for (int i=0;i<b1[x].size();++i) c1[b1[x][i]]--;
    for (int i=0;i<a2[x].size();++i) c2[a2[x][i]+n]++;
    for (int i=0;i<b2[x].size();++i) c2[b2[x][i]+n]--;
    ans[x]+=c1[d[x]+w[x]]-ori1+c2[w[x]-d[x]+n]-ori2;
}

int main(){
    scanf("%d%d",&n,&m);
    for (int i=1;i<n;++i){
        scanf("%d%d",&x,&y);
        add_edge(x,y); add_edge(y,x);
    }
    for (int i=1;i<=n;++i) scanf("%d",&w[i]);
    t=log(n)/log(2);
    bfs();
    for (int i=1;i<=m;++i){
        scanf("%d%d",&x,&y);
        int fa=lca(x,y);
        a1[x].push_back(d[x]);
        b1[f[fa][0]].push_back(d[x]);
        a2[y].push_back(d[x]-(d[fa]<<1));
        b2[fa].push_back(d[x]-(d[fa]<<1));
    }
    dfs(1);
    for (int i=1;i<=n;++i) printf("%d ",ans[i]);
    return 0;
}