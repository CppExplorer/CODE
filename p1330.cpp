#include<bits/stdc++.h>
using namespace std;
int n,m,i,to[200005],head[10005],nxt[200005],k,c[10005],cnt[2],ans;
bool vis[10005];

void add_edge(int x,int y){
    k++;
    to[k]=y;
    nxt[k]=head[x];
    head[x]=k;
}

void dfs(int x,int colour){
    if (vis[x]){
        if (c[x]==colour) return;
        else{
            printf("Impossible");
            exit(0);
        }
    }
    vis[x]=1;
    c[x]=colour;
    cnt[colour]++;
    int kk=head[x];
    while (kk){
        dfs(to[kk],1-colour);
        kk=nxt[kk];
    }
}

int main(){
    scanf("%d%d",&n,&m);
    for (i=1;i<=m;++i){
        int x,y;
        scanf("%d%d",&x,&y);
        add_edge(x,y);
        add_edge(y,x);
    }
    for (i=1;i<=n;++i)
    if (!vis[i]){
        cnt[0]=0; cnt[1]=0;
        dfs(i,0);
        ans+=min(cnt[0],cnt[1]);
    }
    printf("%d",ans);
    return 0;
}