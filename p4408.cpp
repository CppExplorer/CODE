#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int N=200005;
int n,m,head[N],nxt[N<<1],to[N<<1],edge[N<<1],x,y,z,tot,fa[N];
long long d[2][N],dia,ans;
bool v[N];

void add_edge(int x,int y,int z){
    to[++tot]=y; edge[tot]=z; nxt[tot]=head[x]; head[x]=tot;
}

void dfs(int x,int cmd){
    for (int i=head[x];i;i=nxt[i]){
        if (to[i]==fa[x]) continue;
        d[cmd][to[i]]=d[cmd][x]+edge[i];
        fa[to[i]]=x;
        dfs(to[i],cmd);
    }
}

int main(){
    scanf("%d%d",&n,&m);
    for (int i=1;i<=m;++i){
        scanf("%d%d%d",&x,&y,&z);
        add_edge(x,y,z);
        add_edge(y,x,z);
    }
    dfs(1,0); x=1;
    for (int i=2;i<=n;++i) if (d[0][i]>d[0][x]) x=i;
    memset(fa,0,sizeof fa); d[0][x]=0;
    dfs(x,0);
    for (int i=1;i<=n;++i) if (d[0][i]>dia) dia=d[0][i],y=i;
    z=y;
    while (z!=x){
        v[z]=1; z=fa[z];
    }
    v[x]=1;
    memset(fa,0,sizeof fa);
    dfs(y,1);
    for (int i=1;i<=n;++i) ans=max(min(d[0][i],d[1][i]),ans);
    printf("%lld",ans+dia);
    return 0;
}