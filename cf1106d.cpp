#include<cstdio>
#include<queue>
using namespace std;
const int N=1e5+5;
int n,m,head[N],to[N<<1],nxt[N<<1],tot;
bool vis[N];

void add_edge(int x,int y){
    to[++tot]=y; nxt[tot]=head[x]; head[x]=tot;
}

priority_queue<int,vector<int>,greater<int> > pq,q;
int main(){
    scanf("%d%d",&n,&m);
    for (int i=1,x,y;i<=m;++i){
        scanf("%d%d",&x,&y);
        add_edge(x,y);
        add_edge(y,x);
    }
    q.push(1);
    while (!q.empty()){
        int x=q.top(); q.pop();
        if (vis[x]) continue;
        vis[x]=1; printf("%d ",x);
        for (int i=head[x];i;i=nxt[i]) pq.push(to[i]);
        while (!pq.empty()){
            int y=pq.top(); pq.pop();
            if (vis[y]) continue;
            q.push(y);
        }
    }
    return 0;
}