#include<cstdio>
#include<cstring>
using namespace std;
int n,m,a[105][105];
long long num[105][105];
double ans[105];
int main(){
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    memset(a,0x3f,sizeof a);
    scanf("%d%d",&n,&m);
    for (int i=1,x,y,z;i<=m;++i){
        scanf("%d%d%d",&x,&y,&z);
        a[x][y]=a[y][x]=z;
        num[x][y]=num[y][x]=1;
    }
    for (int k=1;k<=n;++k)
        for (int i=1;i<=n;++i)
            for (int j=1;j<=n;++j)
            if (a[i][k]+a[k][j]<a[i][j]) a[i][j]=a[i][k]+a[k][j],num[i][j]=num[i][k]*num[k][j];
                else if (a[i][k]+a[k][j]==a[i][j]) num[i][j]+=num[i][k]*num[k][j];
    for (int k=1;k<=n;++k)
        for (int i=1;i<=n;++i)
            for (int j=1;j<=n;++j)
            if (i!=k && j!=k && i!=j){
                if (a[i][k]+a[k][j]==a[i][j]) ans[k]+=((double)(num[i][k]*num[k][j]))/((double)num[i][j]);
            }
    // for (int i=1;i<n;++i)
    //     for (int j=i+1;j<=n;++j) printf("%d %d %d\n",i,j,num[i][j]);
    for (int i=1;i<=n;++i) printf("%.3lf\n",ans[i]);
    return 0;
}