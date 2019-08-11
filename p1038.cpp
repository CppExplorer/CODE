#include<cstdio>
#include<queue>
using namespace std;
const int N=1e4+5;
int n,m,head[N],nxt[N<<1],to[N<<1],edge[N<<1],tot,rd[N],c[N],ans[N],cnt;
bool vis[N];

void add_edge(int x,int y,int z){
    to[++tot]=y; edge[tot]=z; nxt[tot]=head[x]; head[x]=tot;
}

queue<int> q;

void topsort(){
    while (!q.empty()){
        int x=q.front(); q.pop(); vis[x]=1;
        if (c[x]<=0) continue;
        for (int i=head[x];i;i=nxt[i]){
            int y=to[i];
            if (vis[y]) continue;
            rd[y]--; c[y]+=edge[i]*c[x];
            if (!rd[y]) q.push(y);
        }
    }
}

int main(){
    scanf("%d%d",&n,&m);
    for (int i=1,u;i<=n;++i){
        scanf("%d%d",&c[i],&u);
        if (c[i]) q.push(i);
            else c[i]-=u; 
    }
    for (int i=1,x,y,z;i<=m;++i){
        scanf("%d%d%d",&x,&y,&z);
        add_edge(x,y,z);
        rd[y]++;
    }
    topsort();
    for (int i=1;i<=n;++i) if (!head[i] && c[i]>0) ans[++cnt]=i;
    for (int i=1;i<=cnt;++i) printf("%d %d\n",ans[i],c[ans[i]]);
    if (!cnt) printf("NULL");
    return 0;
}