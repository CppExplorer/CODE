#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int n,u,v,w,k,head[N],nxt[2*N],to[2*N],val[2*N],a[N],t[31*N][2],tot=1,b[31],ended[31*N],ans;

void add_edge(int x,int y,int z){
    to[++k]=y; val[k]=z;
    nxt[k]=head[x];
    head[x]=k;
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
    ended[p]=num;
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
        if (ended[p]) ans=max(ans,a[ended[p]]^a[num]);
        if (!p) return;
    }
}

queue<int> q;
int main(){
    scanf("%d",&n);
    for (int i=1;i<n;++i){
        scanf("%d%d%d",&u,&v,&w);
        add_edge(u,v,w);
        add_edge(v,u,w);
    }
    q.push(1);
    while (!q.empty()){
        int fa=q.front();
        for (int i=head[fa];i;i=nxt[i])
            if (!a[to[i]] && to[i]!=1){
                a[to[i]]=a[fa]^val[i];
                q.push(to[i]);
            }
        q.pop();
    }
    for (int i=1;i<=n;++i){
        search(i);
        insert(i);
    }
    printf("%d",ans);
    return 0;
}