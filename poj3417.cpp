#include<cstdio>
#include<cmath>
#include<iostream>
#include<cstring>
using namespace std;
const int N=400005;
int n,m,x,y,head[N],nxt[N<<1],to[N<<1],tot,val[N],f[N][50],t,d[N],ans;
bool vis[N];

void add_edge(int x,int y){
    to[++tot]=y; nxt[tot]=head[x]; head[x]=tot;
}

void prework(int x,int fa){
    vis[x]=1; d[x]=d[fa]+1;
    f[x][0]=fa;
    for (int i=1;(1<<i)<=d[x];++i)
        f[x][i]=f[f[x][i-1]][i-1];
    for (int i=head[x];i;i=nxt[i]){
        if (vis[to[i]]) continue;
        prework(to[i],x);
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
    for (int i=head[x];i;i=nxt[i]){
        if (vis[to[i]]) continue;
        dfs(to[i]);
        val[x]+=val[to[i]];
    }
}

int main(){
    scanf("%d%d",&n,&m);
    for (int i=1;i<n;++i){
        scanf("%d%d",&x,&y);
        add_edge(x,y); add_edge(y,x);
    }
    t=(int)(log(n)/log(2))+1;
    prework(1,0);
    for (int i=1;i<=m;++i){
        scanf("%d%d",&x,&y);
        int z=lca(x,y);
        val[x]++; val[y]++; val[z]-=2;
    }
    memset(vis,0,sizeof vis);
    dfs(1);
    for (int i=2;i<=n;++i){
        if (!val[i]) ans+=m;
            else if (val[i]==1) ans++;
    }
    printf("%d",ans);
    return 0;
}