#include<cstdio>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=1e4+5,M=5e4+5;
int n,m,k,head[N],to[M<<1],nxt[M<<1],edge[M<<1],tot,s,t,dis[N][11];
bool vis[N][11];
struct line{
    int dis,i,cnt;
    bool operator <(const line x) const {
        return dis > x.dis;
    }
};

void add_edge(int x,int y,int z){
    to[++tot]=y; edge[tot]=z; nxt[tot]=head[x]; head[x]=tot;
}

priority_queue<line> q;

void dijkstra(){
    memset(dis,0x3f,sizeof dis);
    for (int i=0;i<=k;++i) dis[s][i]=0;
    q.push((line){0,s,0});
    while (q.size()){
        int x=q.top().i,cnt=q.top().cnt; q.pop();
        if (vis[x][cnt]) continue;
        vis[x][cnt]=1;
        for (int i=head[x];i;i=nxt[i]){
            int y=to[i];
            if (cnt<k && dis[x][cnt]<dis[y][cnt+1]){
                dis[y][cnt+1]=dis[x][cnt];
                q.push((line){dis[y][cnt+1],y,cnt+1});
            }
            if (dis[x][cnt]+edge[i]<dis[y][cnt]){
                dis[y][cnt]=dis[x][cnt]+edge[i];
                q.push((line){dis[y][cnt],y,cnt});
            }
        }
    }
}

int main(){
    scanf("%d%d%d%d%d",&n,&m,&k,&s,&t);
    s++; t++;
    for (int i=1,x,y,z;i<=m;++i){
        scanf("%d%d%d",&x,&y,&z);
        add_edge(x+1,y+1,z);
        add_edge(y+1,x+1,z);
    }
    dijkstra();
    // for (int i=1;i<=n;++i){
    //     for (int j=0;j<=k;++j) printf("dis[%d][%d]=%d ",i,j,dis[i][j]);
    //     printf("\n");
    // }
    int ans=0x7f7f7f7f;
    for (int i=0;i<=k;++i) ans=min(ans,dis[t][i]);
    printf("%d",ans);
    return 0;
}