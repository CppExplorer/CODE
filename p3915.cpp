#include<cstdio>
#include<cstring>
using namespace std;
const int N=100005;
int n,head[N],nxt[N<<1],to[N<<1],x,y,m,k,size[N],ans,T;
bool vis[N];

void add_edge(int x,int y){
    to[++m]=y;
    nxt[m]=head[x];
    head[x]=m;
}

void dfs(int x){
    vis[x]=1; size[x]=1;
    for (int i=head[x];i;i=nxt[i]){
        if (vis[to[i]]) continue;
        dfs(to[i]);
        size[x]+=size[to[i]];
    }
    if (size[x]==k) size[x]=0,ans++;
}

int main(){
    scanf("%d",&T);
    while (T--){
        m=0; ans=0;
        memset(nxt,0,sizeof nxt);
        memset(head,0,sizeof head);
        memset(vis,0,sizeof vis);
        scanf("%d%d",&n,&k);
        for (int i=1;i<n;++i){
            scanf("%d%d",&x,&y);
            add_edge(x,y);
            add_edge(y,x);
        }
        dfs(1);
        if (ans==n/k) printf("YES\n");
            else printf("NO\n");
    }
    return 0;
}