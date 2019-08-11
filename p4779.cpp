#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
const int N=2e5+5;
int n,m,s,head[N],to[N<<1],nxt[N<<1],edge[N<<1],tot,dis[N];
bool vis[N];

void add_edge(int x,int y,int z){
	to[++tot]=y; edge[tot]=z; nxt[tot]=head[x]; head[x]=tot;
}

priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;

void dijkstra(){
	memset(dis,0x3f,sizeof dis);
	dis[s]=0;
	q.push(make_pair(0,s));
	while (q.size()){
		int x=q.top().second; q.pop();
		if (vis[x]) continue;
		vis[x]=1;
		for (int i=head[x];i;i=nxt[i]){
			int y=to[i];
			if (dis[x]+edge[i]<dis[y]){
				dis[y]=dis[x]+edge[i];
				q.push(make_pair(dis[y],y));
			}
		}
	}
}

int main(){
	scanf("%d%d%d",&n,&m,&s);
	for (int i=1,x,y,z;i<=m;++i){
		scanf("%d%d%d",&x,&y,&z);
		add_edge(x,y,z);
	}
	dijkstra();
	for (int i=1;i<=n;++i) printf("%d ",dis[i]);
	return 0;
}