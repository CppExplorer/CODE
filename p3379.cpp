#include<bits/stdc++.h>
using namespace std;
int n,m,root,i,deep[500005],k,tx[1000001],head[500005],nxt[1000001],f[500005][35];

void add_edge(int x,int y){
    k++;
    tx[k]=y;
    nxt[k]=head[x];
    head[x]=k;
}

void dfs(int u,int v){
    deep[u]=deep[v]+1;
    f[u][0]=v;
    for (int i=1;(1<<i)<=deep[u];++i)
      f[u][i]=f[f[u][i-1]][i-1];
    int xx=head[u];
    while (xx>0){
        int to=tx[xx];
        if (to!=v) dfs(to,u);
        xx=nxt[xx];
    }
}

int lca(int x,int y){
    if (deep[x]<deep[y]) swap(x,y);
    for (int i=30;i>=0;--i)
      if (deep[y]<=deep[x]-(1<<i)) x=f[x][i];
    if (x==y) return x;
    for (int i=30;i>=0;--i)
      if (f[x][i]!=f[y][i]) x=f[x][i],y=f[y][i];
    return f[x][0];
}

int main(){
    scanf("%d%d%d",&n,&m,&root);
    for (i=1;i<n;++i){
        int x,y;
        scanf("%d%d",&x,&y);
        add_edge(x,y);
        add_edge(y,x);
    }
    dfs(root,0);
    for (i=1;i<=m;++i){
        int a,b;
        scanf("%d%d",&a,&b);
        printf("%d\n",lca(a,b));
    }
    return 0;
}