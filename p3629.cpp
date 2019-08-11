#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
const int N=100005;
int n,k,head[N],nxt[N<<1],to[N<<1],edge[N<<1],tot,d[N],ans,x,y,dis[N],ans2,fa[N];
bool vis[N];

void add_edge(int x,int y){
    to[++tot]=y; edge[tot]=1; nxt[tot]=head[x]; head[x]=tot;
}

void dfs(int x){
    for (int i=head[x];i;i=nxt[i]){
        if (to[i]==fa[x]) continue;
        dis[to[i]]=dis[x]+1;
        fa[to[i]]=x;
        dfs(to[i]);
    }
}

void dp(int x){
    vis[x]=1;
    for (int i=head[x];i;i=nxt[i]){
        int y=to[i];
        if (vis[y]) continue;
        dp(y);
        ans=max(ans,d[x]+d[y]+edge[i]);
        d[x]=max(d[x],d[y]+edge[i]);
    }
}

int main(){
    scanf("%d%d",&n,&k);
    for (int i=1;i<n;++i){
        scanf("%d%d",&x,&y);
        add_edge(x,y); add_edge(y,x);
    }
    if (k==1){
        dp(1);
        printf("%d",((n-1)<<1)-ans+1);
        return 0;
    }
    dfs(1);
    for (int i=1;i<=n;++i) if (dis[i]>ans) ans=dis[i],x=i;
    dis[x]=0;
    memset(fa,0,sizeof fa);
    dfs(x); ans=0;
    for (int i=1;i<=n;++i) if (dis[i]>ans) ans=dis[i],y=i;
    ans2=ans; ans=0;
    while (y!=x){
        for (int i=head[y];i;i=nxt[i]){
            if (to[i]==fa[y]){
                edge[i]=-1;
                if (to[i+1]==y) edge[i+1]=-1;
                    else edge[i-1]=-1;
            }
        }
        y=fa[y];
    }
    dp(1);
    printf("%d",(n<<1)-ans-ans2);
    return 0;
}