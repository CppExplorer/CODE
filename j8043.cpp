#include<bits/stdc++.h>
using namespace std;
int n,m,i,j,tx[6000],ty[6000],head[3005],nxt[6000],k,f[3005][3000],a[3000],t[3000];

void add_edge(int x,int y,int z){
    k++;
    tx[k]=y; ty[k]=z;
    nxt[k]=head[x];
    head[x]=k;
}

int dfs(int x){
    if (x>n-m){
        f[x][1]=a[x];
        return 1;
    }
    int son=0;
    int xx=head[x];
    while (xx>0){
        int v=tx[xx];
        int sons=dfs(v);
        for (int j=0;j<=son;++j) t[j]=f[x][j];
        for (int j=0;j<=son;++j)
          for (int k=0;k<=sons;++k)
          f[x][j+k]=max(f[x][j+k],t[j]+f[v][k]-ty[xx]);
        son+=sons;
        xx=nxt[xx];
    }
    return son;
}

int main(){
    scanf("%d%d",&n,&m);
    int c,x,y;
    for (i=1;i<=n-m;++i){
        scanf("%d",&c);
        for (int j=1;j<=c;++j){
            scanf("%d%d",&x,&y);
            add_edge(i,x,y);
        }
    }
    for (i=n-m+1;i<=n;++i) scanf("%d",&a[i]);
    memset(f,128,sizeof f);
    for (i=1;i<=n;++i) f[i][0]=0;
    dfs(1);
    int ans;
    for (i=m;i>=0;--i)
        if (f[1][i]>=0){
            ans=i;
            break;
        }
    printf("%d",ans);
    return 0;
}