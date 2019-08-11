#include<cstdio>
#include<iostream>
using namespace std;
const int N=2005;
int n,m,head[N],nxt[N<<1],to[N<<1],x,tot,f[N][2];
bool vis[N];

void add_edge(int x,int y){
    to[++tot]=y; nxt[tot]=head[x]; head[x]=tot;
}

void dp(int x){
    vis[x]=1;
    f[x][0]=0; f[x][1]=1;
    for (int i=head[x];i;i=nxt[i]){
        int y=to[i];
        if (vis[y]) continue;
        dp(y);
        f[x][0]+=f[y][1];
        f[x][1]+=min(f[y][0],f[y][1]);
    }
}

int main(){
    scanf("%d",&n);
    for (int i=0;i<n;++i){
        scanf("%d%d",&x,&m);
        for (int j=1;j<=m;++j){
            scanf("%d",&x);
            add_edge(i,x); add_edge(x,i);
        }
    }
    dp(0);
    printf("%d",min(f[0][0],f[0][1]));
    return 0;
}