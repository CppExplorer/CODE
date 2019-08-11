#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,a[205][205],c[205][205],cnt;
bool f[205];
int main(){
    memset(a,0x3f,sizeof a);
    scanf("%d%d",&n,&m);
    for (int i=1,x,y,z;i<=m;++i){
        scanf("%d%d%d",&x,&y,&z);
        if (z<a[x][y]) a[x][y]=a[y][x]=z;
    }
    for (int i=1;i<=n;++i) a[i][i]=0;
    for (int k=1;k<=n;++k)
        for (int i=1;i<=n;++i)
            for (int j=1;j<=n;++j)
            if (i!=j && i!=k && j!=k){
                if (a[i][k]+a[k][j]<a[i][j]) a[i][j]=a[i][k]+a[k][j],c[i][j]=k;
                    else if (a[i][k]+a[k][j]==a[i][j]) c[i][j]=0;
            }
    for (int i=1;i<=n;++i)
        for (int j=1;j<=n;++j) f[c[i][j]]=1;
    for (int i=1;i<=n;++i) if (f[i]) printf("%d ",i),cnt++;
    if (!cnt) printf("No important cities.");
    return 0;
}