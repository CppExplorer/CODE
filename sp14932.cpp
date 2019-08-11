#include<cstdio>
#include<cmath>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
const int N=1e3+5;
int T,n,m,head[N],to[N<<1],nxt[N<<1],f[N][20],t,tot,d[N];

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
			if (y==f[x][0]) continue;
			d[y]=d[x]+1;
			f[y][0]=x;
			for (int j=1;(1<<j)<=d[y];++j)
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

int main(){
	scanf("%d",&T);
	for (int C=1;C<=T;++C){
		memset(f,0,sizeof f);
		tot=0;
		memset(nxt,0,sizeof nxt);
		memset(to,0,sizeof to);
		memset(head,0,sizeof head);
		scanf("%d",&n);
		t=(int)(log(n)/log(2))+1;
		for (int i=1,num;i<=n;++i){
			scanf("%d",&num);
			for (int j=1,y;j<=num;++j){
				scanf("%d",&y);
				add_edge(i,y); add_edge(y,i);
			}
		}
		bfs();
		scanf("%d",&m);
		printf("Case %d:\n",C);
		for (int i=1,x,y;i<=m;++i){
			scanf("%d%d",&x,&y);
			printf("%d\n",lca(x,y));
		}
	}
	return 0;
}