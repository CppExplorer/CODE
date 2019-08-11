#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int N=100005;
int n,a[N],t[N*31][2],tail[31*N],head[N],nxt[2*N],to[2*N],val[2*N],k,tot=1,ans,b[31];
bool vis[N];

void add_edge(int x,int y,int z){
    to[++k]=y; val[k]=z;
    nxt[k]=head[x];
    head[x]=k;
}

void dfs(int x){
    vis[x]=1;
    for (int i=head[x];i;i=nxt[i])
        if (!vis[to[i]]){
            a[to[i]]=a[x]^val[i];
            dfs(to[i]);
        }
}

void insert(int num){
    int x=a[num],y=31,p=1;
    memset(b,0,sizeof b);
    while (x){
        b[y--]=x%2;
        x>>=1;
    }
    for (int i=1;i<=31;++i){
        if (!t[p][b[i]]) t[p][b[i]]=++tot;
        p=t[p][b[i]];
    }
    tail[p]=num;
}

void search(int num){
    int x=a[num],y=31,p=1;
    memset(b,0,sizeof b);
    while (x){
        b[y--]=x%2;
        x>>=1;
    }
    for (int i=1;i<=31;++i){
        if (!t[p][b[i]^1]) p=t[p][b[i]];
            else p=t[p][b[i]^1];
        if (tail[p]) ans=max(ans,a[tail[p]]^a[num]);
        if (!p) return;
    }
}

int main(){
    while (scanf("%d",&n)!=EOF){
        k=0; ans=0; tot=1;
        memset(t,0,sizeof t);
        memset(head,0,sizeof head);
        memset(a,0,sizeof a);
        memset(tail,0,sizeof tail);
        memset(vis,0,sizeof vis);
        for (int i=1;i<n;++i){
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            u++; v++;
            add_edge(u,v,w);
            add_edge(v,u,w);
        }
        dfs(1);
        for (int i=1;i<=n;++i){
            search(i);
            insert(i);
        }
        printf("%d\n",ans);
    }
    return 0;
}