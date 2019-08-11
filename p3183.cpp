#include<cstdio>
using namespace std;
const int N=1e5+5;
int n,m,head[N],to[N<<1],nxt[N<<1],tot,cd[N],rd[N],f[N],ans;

void add_edge(int x,int y){
    to[++tot]=y; cd[x]++; rd[y]++; nxt[tot]=head[x]; head[x]=tot;
}

int dfs(int x){
    if (f[x]) return f[x];
    int ans=0;
    if (!cd[x] && rd[x]) return f[x]=1;
    for (int i=head[x];i;i=nxt[i]){
        int y=to[i];
        ans+=dfs(y);
    }
    f[x]=ans; return ans;
}

int main(){
    scanf("%d%d",&n,&m);
    for (int i=1,x,y;i<=m;++i){
        scanf("%d%d",&x,&y);
        add_edge(x,y);
    }
    for (int i=1;i<=n;++i)
        if (!rd[i]) ans+=dfs(i);
    printf("%d",ans);
    return 0;
}