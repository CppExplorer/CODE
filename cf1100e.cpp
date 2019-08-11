#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
const int N=1e5+5;
int n,m,head[N],to[N<<1],nxt[N<<1],edge[N<<1],tot,id[N<<1],l,r,rd[N],dfn[N],cnt,ans[N];
bool vis[N];
 
void add_edge(int x,int y,int z,int i){
    to[++tot]=y; edge[tot]=z; nxt[tot]=head[x]; head[x]=tot; id[tot]=i;
}
 
queue<int> q;
void topsort(int mid){
    int now=0;
    while (!q.empty()) q.pop();
    for (int i=1;i<=n;++i) if (!rd[i]) q.push(i);
    while (!q.empty()){
        int x=q.front(); q.pop();
        dfn[x]=++now; vis[x]=1;
        for (int i=head[x];i;i=nxt[i]){
            if (edge[i]<=mid) continue;
            if (--rd[to[i]]==0) q.push(to[i]);
        }
    }
}
 
bool check(int x){
    memset(rd,0,sizeof rd);
    memset(vis,0,sizeof vis);
    for (int i=1;i<=n;++i)
        for (int j=head[i];j;j=nxt[j])
        if (edge[j]>x) rd[to[j]]++;
    topsort(x);
    for (int i=1;i<=n;++i) if (!vis[i]) return false;
    cnt=0;
    for (int i=1;i<=n;++i)
        for (int j=head[i];j;j=nxt[j])
        if (dfn[to[j]]<dfn[i] && edge[j]<=x) ans[++cnt]=id[j];
    // printf("%d\n",cnt);
    return true;
}
 
int main(){
    scanf("%d%d",&n,&m);
    for (int i=1,x,y,z;i<=m;++i){
        scanf("%d%d%d",&x,&y,&z);
        add_edge(x,y,z,i); r=max(r,z);
    }
    int anss=0;
    while (l<=r){
        int mid=(l+r)>>1;
        if (check(mid)) anss=mid,r=mid-1;
            else l=mid+1;
    }
    printf("%d %d\n",anss,cnt);
    sort(ans+1,ans+1+cnt);
    for (int i=1;i<=cnt;++i) printf("%d ",ans[i]);
}