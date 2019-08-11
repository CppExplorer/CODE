#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
const int N=50005;
int n,head[N],nxt[N<<10],to[N<<10],tot,dis[N],ans,x;
bool vis[N];

void add_edge(int x,int y){
    to[++tot]=y;
    nxt[tot]=head[x];
    head[x]=tot;
}

void link(int x){
    int sum=0;
    for (int i=1,m=sqrt(x);i<=m;++i)
    if (x%i==0){
        sum+=i;
        if (i!=x/i && i!=1) sum+=x/i;
    }
    if (sum>=x) return;
    add_edge(sum,x),add_edge(x,sum);
}

void dfs(int x){
    vis[x]=1;
    for (int i=head[x];i;i=nxt[i]){
        if (vis[to[i]]) continue;
        dis[to[i]]=dis[x]+1;
        dfs(to[i]);
    }
}

int main(){
    scanf("%d",&n);
    for (int i=2;i<=n;++i) link(i);
    dfs(1);
    for (int i=1;i<=n;++i) if (dis[i]>ans) ans=dis[i],x=i;
    memset(vis,0,sizeof vis);
    memset(dis,0,sizeof dis);
    dfs(x); ans=0;
    for (int i=1;i<=n;++i) ans=max(ans,dis[i]);
    printf("%d",ans);
    return 0;
}