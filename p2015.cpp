#include<bits/stdc++.h>
using namespace std;
int n,q,i,l[105],r[105],f[105][105],a[105][105],v[105];
bool vis[105];

void maketree(int x){
    for (i=1;i<=n;++i)
        if (a[x][i]>-1){
            l[x]=i;
            v[i]=a[x][i];
            a[x][i]=a[i][x]=-1;
            maketree(i);
            break;
        }
    for (i=1;i<=n;++i)
        if (a[x][i]>-1){
            r[x]=i;
            v[i]=a[x][i];
            a[x][i]=a[i][x]=-1;
            maketree(i);
            break;
        }
}

void cut(int x,int y){
    if (f[x][y]!=0) return;
    if (y==0){
        f[x][y]=0;
        return ;
    } 
    if (l[x]==0 && r[x]==0){
        f[x][y]=v[x];
        return;
    }
    for (int i=0;i<y;++i){
        cut(l[x],i);
        cut(r[x],y-i-1);
        f[x][y]=max(f[x][y],f[l[x]][i]+f[r[x]][y-i-1]+v[x]);
    }
}

int main(){
    scanf("%d%d",&n,&q);
    for (i=1;i<=n;++i)
      for (int j=1;j<=n;++j) a[i][j]=-1;
    int x,y,z;
    for (i=1;i<n;++i){
        scanf("%d%d%d",&x,&y,&z);
        a[x][y]=a[y][x]=z;
    }
    maketree(1);
    cut(1,q+1);
    printf("%d",f[1][q+1]);
    return 0;
}
