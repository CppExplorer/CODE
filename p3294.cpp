#include<cstdio>
#include<string>
#include<cstring>
#include<iostream>
#include<queue>
using namespace std;
const int N=1e5+5;
int n,t[N*26][26],tot=1,ed[N*26],l[N*26],lon[N],near[N],head[N],to[N<<1],nxt[N<<1],total,size[N],a[N],m;
long long ans;
bool vis[N];
string s[N];

void add_edge(int x,int y){
    to[++total]=y; nxt[total]=head[x]; head[x]=total;
}

void insert(int num){
    int len=s[num].length(),p=1;
    for (int i=len-1;i>=0;--i){
        int ch=s[num][i]-'a';
        if (!t[p][ch]) t[p][ch]=++tot;
        p=t[p][ch];
    }
    ed[p]=num; l[p]=len;
}

void search(int num){
    int len=s[num].length(),p=1;
    for (int i=len-1;i>=0;--i){
        p=t[p][s[num][i]-'a'];
        if (ed[p] && ed[p]!=num && l[p]>lon[num]) lon[num]=l[p],near[num]=ed[p];
        if (!p) return;
    }
}

void dfs(int x){
    vis[x]=1; size[x]=1;
    for (int i=head[x];i;i=nxt[i]){
        if (vis[to[i]]) continue;
        dfs(to[i]);
        size[x]+=size[to[i]];
    }
}

priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
void bfs(int x){
    // printf("%d ",x);
    for (int i=head[x];i;i=nxt[i]) q.push(make_pair(size[to[i]],to[i]));
    while (q.size()){
        int y=q.top().second; q.pop();
        a[y]=++m;
        bfs(y);
    }
}

void dfs2(int x){
    vis[x]=1;
    for (int i=head[x];i;i=nxt[i]){
        if (vis[to[i]]) continue;
        ans+=a[to[i]]-a[x];
        // printf("%d %d %d %d\n",x,to[i],a[x],a[to[i]]);
        dfs2(to[i]);
    }
}

int main(){
    scanf("%d",&n);
    for (int i=1;i<=n;++i){
        cin>>s[i];
        insert(i);
    }
    for (int i=1;i<=n;++i) search(i);
    for (int i=1;i<=n;++i) add_edge(near[i],i);
    dfs(0); bfs(0);
    memset(vis,0,sizeof vis);
    dfs2(0);
    printf("%lld",ans);
    return 0;
}