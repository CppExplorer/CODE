#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int N=500005;
int n,s,x,y,z,head[N],nxt[N<<1],to[N<<1],edge[N<<1],tot,dis[N],d[N],a[N],m,fa[N],ans,temp;
bool vis[N];

void add_edge(int x,int y,int z){
    to[++tot]=y; edge[tot]=z; nxt[tot]=head[x]; head[x]=tot;
}

void dfs(int x){
    for (int i=head[x];i;i=nxt[i]){
        if (to[i]==fa[x]) continue;
        fa[to[i]]=x;
        dis[to[i]]=dis[x]+edge[i];
        dfs(to[i]);
    }
}

void dp(int x){
    vis[x]=1;
    for (int i=head[x];i;i=nxt[i]){
        if (vis[to[i]]) continue;
        dp(to[i]);
        d[x]=max(d[x],d[to[i]]+edge[i]);
    }
}

int main(){
    scanf("%d%d",&n,&s);
    for (int i=1;i<n;++i){
        scanf("%d%d%d",&x,&y,&z);
        add_edge(x,y,z);
        add_edge(y,x,z);
    }
    dfs(1); x=1;
    for (int i=2;i<=n;++i) if (dis[i]>dis[x]) x=i;
    memset(fa,0,sizeof fa);
    dis[x]=0;
    dfs(x); y=1;
    for (int i=2;i<=n;++i) if (dis[i]>dis[y]) y=i;
    while (y!=x){
        a[++m]=y; vis[y]=1; y=fa[y];
    }
    vis[x]=1; a[++m]=x; ans=0x7f7f7f7f;
    for (int i=1;i<=m;++i) dp(a[i]);
    for (int i=1;i<=m;++i) temp=max(temp,d[a[i]]);
    int j=m;
    for (int i=m;i;--i){
        while (j>=1 && dis[a[j]]-dis[a[i]]<=s) j--;
        ans=min(ans,max(temp,max(dis[a[i]],dis[a[1]]-dis[a[j+1]])));
    }
    printf("%d",ans);
    return 0;
}