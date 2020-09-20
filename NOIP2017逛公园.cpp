#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int N=1e5+5,M=2e5+5;
int T,n,m,k,p,dis[N],f[N][55];
bool vis[N],err,v[N][55];
struct Node{
    int to[M],nxt[M],edge[M],tot,head[N];
}e,fe;
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;

void add_edge(Node &a,int x,int y,int z){
    a.to[++a.tot]=y,a.edge[a.tot]=z; a.nxt[a.tot]=a.head[x],a.head[x]=a.tot;
}

void dijkstra(){
    memset(dis,0x3f,sizeof dis);
    memset(vis,0,sizeof vis);
    for (;!q.empty();q.pop());
    dis[n]=0;
    q.push(make_pair(0,n));
    while(!q.empty()){
        int x=q.top().second; q.pop();
        if (vis[x]) continue;
        vis[x]=1;
        for (int i=fe.head[x];i;i=fe.nxt[i]){
            int y=fe.to[i];
            if (vis[y]) continue;
            if (dis[x]+fe.edge[i]<dis[y]){
                dis[y]=dis[x]+fe.edge[i];
                q.push(make_pair(dis[y],y));
            }
        }
    }
}

int dfs(int x,int d){
    if (err) return 0;
    int res=0;
    if (v[x][d]){err=1; return 0;}
    if (f[x][d]!=-1) return f[x][d];
    v[x][d]=1;
    for (int i=e.head[x];i;i=e.nxt[i]){
        int y=e.to[i],w=e.edge[i];
        for (int j=0;j<=k;++j){
            if (dis[y]+w>dis[x]+d) continue;
            res=(res+dfs(y,d+dis[x]+w-dis[y]))%p;
        }
    }
    if (x==n) res=1;
    f[x][0]=res;
    v[x][d]=0;
    return f[x][0];
}

int main(){
    scanf("%d",&T);
    while (T--){
        e.tot=fe.tot=0;
        memset(e.head,0,sizeof e.head);
        memset(fe.head,0,sizeof fe.head);
        scanf("%d%d%d%d",&n,&m,&k,&p);
        for (int i=1,x,y,z;i<=m;++i){
            scanf("%d%d%d",&x,&y,&z);
            add_edge(e,x,y,z);
            add_edge(fe,y,x,z);
        }
        dijkstra();
        // for (int i=1;i<=n;++i) printf("%d ",dis[i]); printf("\n");
        err=0;
        memset(f,-1,sizeof f);
        memset(v,0,sizeof v);
        dfs(1,k);
        if (err) printf("-1\n");
        else printf("%d\n",f[1][k]);
    }
    return 0;
}