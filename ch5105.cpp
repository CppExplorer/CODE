#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int M=5005,N=35;
int n,m,sum[N],lsti[N][M],lstj[N][M],ans[N];
long long f[N][M];
struct Cookies{
    int g,id;
}a[N];

bool cmp(Cookies x,Cookies y){
    return x.g>y.g;
}

void print(int x,int y){
    if (!x) return;
    // printf("%d %d\n",x,y);
    print(lsti[x][y],lstj[x][y]);
    if (lsti[x][y]==x){
        for (int i=1;i<=n;++i) ans[a[i].id]++;
    }else{
        for (int i=lsti[x][y]+1;i<=n;++i) ans[a[i].id]=1;
    }
}

int main(){
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;++i) scanf("%d",&a[i].g),a[i].id=i;
    sort(a+1,a+1+n,cmp);
    for (int i=1;i<=n;++i) sum[i]=sum[i-1]+a[i].g;
    memset(f,0x3f,sizeof f);
    f[0][0]=0;
    for (int i=1;i<=n;++i)
        for (int j=i;j<=m;++j){
            // f[i][j]=min(f[i][j],f[i][j-i]);
            f[i][j]=f[i][j-i];
            lsti[i][j]=i,lstj[i][j]=j-i;
            for (int k=0;k<i;++k)
                // f[i][j]=min(f[i][j],f[k][j-(i-k)]+1LL*(sumg[i]-sumg[k])*k);
                if (f[k][j-(i-k)]+1LL*(sum[i]-sum[k])*k<f[i][j]){
                    f[i][j]=f[k][j-(i-k)]+1LL*(sum[i]-sum[k])*k;
                    lsti[i][j]=k,lstj[i][j]=j-(i-k);
                }
        }
    printf("%lld\n",f[n][m]);
    print(n,m);
    for (int i=1;i<=n;++i) printf("%d ",ans[i]);
    return 0;
}