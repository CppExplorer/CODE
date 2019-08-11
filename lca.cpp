#include <bits/stdc++.h>
using namespace std;
int n,i,j,k,m,tx[80005],head[40005],nxt[80005],x,y,f[40005][21],root,deep[40005];
int const maxdeep=20;

void add_edge(int x,int y){
    k++;
    tx[k]=y;
    nxt[k]=head[x];
    head[x]=k;
}

void dfs(int x,int fa){
    deep[x]=deep[fa]+1;
    f[x][0]=fa;
    for (int i=1;(1<<i)<=deep[x];++i)
      f[x][i]=f[f[x][i-1]][i-1];
    int xx=head[x];
    while (xx>0){
        if (tx[xx]!=fa) dfs(tx[xx],x);
        xx=nxt[xx];
    }
}

int lca(int x,int y){
    if (deep[x]<deep[y]) swap(x,y);
    for (int i=maxdeep;i>=0;--i)
      if (deep[y]<=deep[x]-(1<<i)) x=f[x][i];
    if (x==y) return x;
    for (int i=maxdeep;i>=0;--i)
      if (f[x][i]!=f[y][i]) x=f[x][i],y=f[y][i];
    return f[x][0];
}

int main(){
    scanf("%d",&n);
    for (i=1;i<=n;++i){
        scanf("%d%d",&x,&y);
        if (y==-1){
            root=x;
            continue;
        }
        add_edge(x,y);
        add_edge(y,x);
    }
    dfs(root,0);
    scanf("%d",&m);
    for (i=1;i<=m;++i){
        scanf("%d%d",&x,&y);
        printf("%d\n",lca(x,y));
    }
    return 0;
}