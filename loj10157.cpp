#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=1505;
int n,head[N],to[N<<1],nxt[N<<1],tot,a[N],f[N][3],root,fa[N];
bool vis[N];

void add_edge(int x,int y){
    to[++tot]=y; nxt[tot]=head[x]; head[x]=tot;
}

void dfs(int x){
    vis[x]=1; f[x][2]=a[x];
    int Min=0x7f7f7f7f;
    for (int i=head[x];i;i=nxt[i]){
        int y=to[i];
        if (vis[y]) continue;
        dfs(y);
        f[x][0]+=min(f[y][0],f[y][2]);
        f[x][1]+=min(f[y][0],f[y][2]);
        f[x][2]+=min(f[y][0],min(f[y][1],f[y][2]));
        Min=min(Min,f[y][2]-min(f[y][0],f[y][2]));
    }
    f[x][0]+=Min;
}

int main(){
    scanf("%d",&n);
    for (int i=1,id,m;i<=n;++i){
        scanf("%d",&id);
        scanf("%d%d",&a[id],&m);
        for (int j=1,x;j<=m;++j){
            scanf("%d",&x);
            add_edge(x,id);
            add_edge(id,x);
            fa[x]=id;
        }
    }
    for (int i=1;i<=n;++i) if (!fa[i]){root=i; break;}
    dfs(root);
    printf("%d",min(f[root][0],f[root][2]));
    return 0;
}