#include<cstdio>
#include<queue>
#include<algorithm>
#include<cmath>
using namespace std;
const int N=1e5+5;
int n,k,head[N],to[N<<1],nxt[N<<1],tot,cnt[N],f[N][20],d[N],t,ans[N<<1];
bool flag[N<<1];

void add_edge(int x,int y){
	to[++tot]=y; nxt[tot]=head[x]; head[x]=tot;
}

queue<int> q;

void bfs(){
	q.push(1); d[1]=1;
	while (!q.empty()){
		int x=q.front(); q.pop();
		for (int i=head[x];i;i=nxt[i]){
			int y=to[i];
			if (d[y]) continue;
			d[y]=d[x]+1;
			f[y][0]=x;
			for (int j=1;j<=t;++j)
				f[y][j]=f[f[y][j-1]][j-1];
			q.push(y);
		}
	}
}

int lca(int x,int y){
	if (d[x]<d[y]) swap(x,y);
	for (int i=t;i>=0;--i)
		if (d[f[x][i]]>=d[y]) x=f[x][i];
	if (x==y) return x;
	for (int i=t;i>=0;--i)
		if (f[x][i]!=f[y][i]) x=f[x][i],y=f[y][i];
	return f[x][0];
}

void dfs(int x){
	for (int i=head[x];i;i=nxt[i]){
		if (to[i]==f[x][0]) continue;
		dfs(to[i]);
		cnt[x]+=cnt[to[i]];
	}
}

int main(){
	scanf("%d",&n);
	for (int i=1,x,y;i<n;++i){
		scanf("%d%d",&x,&y);
		add_edge(x,y); add_edge(y,x);
	}
	t=(int)(log(n)/log(2))+1;
	bfs();
	scanf("%d",&k);
	for (int i=1,x,y;i<=k;++i){
		scanf("%d%d",&x,&y);
		int z=lca(x,y);
		// printf("%d\n",z);
		cnt[x]++; cnt[y]++;
		cnt[z]-=2;
	}
	dfs(1);
	for (int i=1;i<=n;++i)
		for (int j=head[i];j;j=nxt[j])
			if (to[j]==f[i][0]){
				ans[j]=cnt[i];
				flag[j]=1;
				break;
			}
	for (int i=1;i<=tot;++i) if (flag[i]) printf("%d ",ans[i]);
	return 0;
}