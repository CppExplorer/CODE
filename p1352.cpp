#include<bits/stdc++.h>
using namespace std;
int n,a[6005],k,tx[6005],ty[6005],head[6005],nxt[6005],i,fa[6005],root,f[6005][2];

void add_edge(int x,int y,int z){
    k++;
    tx[k]=y; ty[k]=z;
    nxt[k]=head[x];
    head[x]=k;
}

void master(int x){
    int xx;
    f[x][0]=0;
    f[x][1]=a[x];
    xx=head[x];
    while (xx>0){
        master(tx[xx]);
        f[x][1]=f[x][1]+f[tx[xx]][0];
        f[x][0]=f[x][0]+max(f[tx[xx]][1],f[tx[xx]][0]);
        xx=nxt[xx];
    }
}

int main(){
    int x,y;
    scanf("%d",&n);
    for (i=1;i<=n;++i) scanf("%d",&a[i]);
    for (i=1;i<n;++i){
        scanf("%d%d",&x,&y);
        add_edge(y,x,a[x]);
        fa[x]=y;
    }
    scanf("%d%d",&x,&y);
    for (i=1;i<=n;++i)
        if (fa[i]==0){
            root=i;
            break;
        }
    master(root);
    printf("%d",max(f[root][1],f[root][0]));
    return 0;
}