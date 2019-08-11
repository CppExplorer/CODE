#include<bits/stdc++.h>
using namespace std;
int n,head[100005],k,x,y,i,nxt[200005],tx[200005],deep[100005];
double ans;

void add_edge(int x,int y){
    k++; tx[k]=y;
    nxt[k]=head[x];
    head[x]=k;
}

void dfs(int x,int fa){
    deep[x]=deep[fa]+1;
    for (int i=head[x];i;i=nxt[i])
    if (tx[i]!=fa) dfs(tx[i],x);
}

int main(){
    scanf("%d",&n);
    for (i=1;i<n;++i){
        scanf("%d%d",&x,&y);
        add_edge(x,y);
        add_edge(y,x);
    }
    deep[1]=1;
    dfs(1,0);
    for (i=1;i<=n;++i) ans+=1.0/deep[i];
    printf("%.20lf",ans);
    return 0;
}