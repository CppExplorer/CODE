#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,tot,f[16][16][16][256][2][2],a[16][16],sum[16][16],lstL[16][16][16][256][2][2],lstR[16][16][16][256][2][2],lstK[16][16][16][256][2][2],lstY[16][16][16][256][2][2],lstZ[16][16][16][256][2][2];//f[i][j][k][l][m]第i行,左边第j个，右边第k个，总共l个，递增还是递减

void print(int x,int l,int r,int cnt,int y,int z){
    if (!x || !l || !r || !cnt) return;
    print(x-1,lstL[x][l][r][cnt][y][z],lstR[x][l][r][cnt][y][z],lstK[x][l][r][cnt][y][z],lstY[x][l][r][cnt][y][z],lstZ[x][l][r][cnt][y][z]);
    for (int i=l;i<=r;++i) printf("%d %d\n",x,i);
}

int main(){
    scanf("%d%d%d",&n,&m,&tot);
    for (int i=1;i<=n;++i)
        for (int j=1;j<=m;++j)
            scanf("%d",&a[i][j]),sum[i][j]=sum[i][j-1]+a[i][j];
    for (int i=1;i<=n;++i)
        for (int j=1;j<=m;++j)
            for (int k=j;k<=m;++k)
                for (int l=0;l<=tot;++l)
                    if (l+k-j+1<=tot){
                        for (int lj=j;lj<=k;++lj)
                            for (int lk=lj;lk<=k;++lk)
                                if (f[i-1][lj][lk][l][0][0]+sum[i][k]-sum[i][j-1]>f[i][j][k][l+k-j+1][0][0])
                                    f[i][j][k][l+k-j+1][0][0]=f[i-1][lj][lk][l][0][0]+sum[i][k]-sum[i][j-1],lstL[i][j][k][l+k-j+1][0][0]=lj,lstR[i][j][k][l+k-j+1][0][0]=lk,lstK[i][j][k][l+k-j+1][0][0]=l,lstY[i][j][k][l+k-j+1][0][0]=0,lstZ[i][j][k][l+k-j+1][0][0]=0;
                        for (int lj=1;lj<=j;++lj)
                            for (int lk=j;lk<=k;++lk){
                                if (f[i-1][lj][lk][l][0][0]+sum[i][k]-sum[i][j-1]>f[i][j][k][l+k-j+1][1][0])
                                    f[i][j][k][l+k-j+1][1][0]=f[i-1][lj][lk][l][0][0]+sum[i][k]-sum[i][j-1],lstL[i][j][k][l+k-j+1][1][0]=lj,lstR[i][j][k][l+k-j+1][1][0]=lk,lstK[i][j][k][l+k-j+1][1][0]=l,lstY[i][j][k][l+k-j+1][1][0]=0,lstZ[i][j][k][l+k-j+1][1][0]=0;
                                if (f[i-1][lj][lk][l][1][0]+sum[i][k]-sum[i][j-1]>f[i][j][k][l+k-j+1][1][0])
                                    f[i][j][k][l+k-j+1][1][0]=f[i-1][lj][lk][l][1][0]+sum[i][k]-sum[i][j-1],lstL[i][j][k][l+k-j+1][1][0]=lj,lstR[i][j][k][l+k-j+1][1][0]=lk,lstK[i][j][k][l+k-j+1][1][0]=l,lstY[i][j][k][l+k-j+1][1][0]=1,lstZ[i][j][k][l+k-j+1][1][0]=0;
                            }
                        for (int lj=j;lj<=k;++lj)
                            for (int lk=k;lk<=m;++lk){
                                if (f[i-1][lj][lk][l][0][0]+sum[i][k]-sum[i][j-1]>f[i][j][k][l+k-j+1][0][1])
                                    f[i][j][k][l+k-j+1][0][1]=f[i-1][lj][lk][l][0][0]+sum[i][k]-sum[i][j-1],lstL[i][j][k][l+k-j+1][0][1]=lj,lstR[i][j][k][l+k-j+1][0][1]=lk,lstK[i][j][k][l+k-j+1][0][1]=l,lstY[i][j][k][l+k-j+1][0][1]=0,lstZ[i][j][k][l+k-j+1][0][1]=0;
                                if (f[i-1][lj][lk][l][0][1]+sum[i][k]-sum[i][j-1]>f[i][j][k][l+k-j+1][0][1])
                                    f[i][j][k][l+k-j+1][0][1]=f[i-1][lj][lk][l][0][1]+sum[i][k]-sum[i][j-1],lstL[i][j][k][l+k-j+1][0][1]=lj,lstR[i][j][k][l+k-j+1][0][1]=lk,lstK[i][j][k][l+k-j+1][0][1]=l,lstY[i][j][k][l+k-j+1][0][1]=0,lstZ[i][j][k][l+k-j+1][0][1]=1;
                            }
                        for (int lj=1;lj<=m;++lj)
                            for (int lk=lj;lk<=m;++lk){
                                if (j<lj || k>lk) continue;
                                if (f[i-1][lj][lk][l][1][1]+sum[i][k]-sum[i][j-1]>f[i][j][k][l+k-j+1][1][1])
                                    f[i][j][k][l+k-j+1][1][1]=f[i-1][lj][lk][l][1][1]+sum[i][k]-sum[i][j-1],lstL[i][j][k][l+k-j+1][1][1]=lj,lstR[i][j][k][l+k-j+1][1][1]=lk,lstK[i][j][k][l+k-j+1][1][1]=l,lstY[i][j][k][l+k-j+1][1][1]=1,lstZ[i][j][k][l+k-j+1][1][1]=1;
                                if (f[i-1][lj][lk][l][0][0]+sum[i][k]-sum[i][j-1]>f[i][j][k][l+k-j+1][1][1])
                                    f[i][j][k][l+k-j+1][1][1]=f[i-1][lj][lk][l][0][0]+sum[i][k]-sum[i][j-1],lstL[i][j][k][l+k-j+1][1][1]=lj,lstR[i][j][k][l+k-j+1][1][1]=lk,lstK[i][j][k][l+k-j+1][1][1]=l,lstY[i][j][k][l+k-j+1][1][1]=0,lstZ[i][j][k][l+k-j+1][1][1]=0;
                                if (f[i-1][lj][lk][l][1][0]+sum[i][k]-sum[i][j-1]>f[i][j][k][l+k-j+1][1][1])
                                    f[i][j][k][l+k-j+1][1][1]=f[i-1][lj][lk][l][1][0]+sum[i][k]-sum[i][j-1],lstL[i][j][k][l+k-j+1][1][1]=lj,lstR[i][j][k][l+k-j+1][1][1]=lk,lstK[i][j][k][l+k-j+1][1][1]=l,lstY[i][j][k][l+k-j+1][1][1]=1,lstZ[i][j][k][l+k-j+1][1][1]=0;
                                if (f[i-1][lj][lk][l][0][1]+sum[i][k]-sum[i][j-1]>f[i][j][k][l+k-j+1][1][1])
                                    f[i][j][k][l+k-j+1][1][1]=f[i-1][lj][lk][l][0][1]+sum[i][k]-sum[i][j-1],lstL[i][j][k][l+k-j+1][1][1]=lj,lstR[i][j][k][l+k-j+1][1][1]=lk,lstK[i][j][k][l+k-j+1][1][1]=l,lstY[i][j][k][l+k-j+1][1][1]=0,lstZ[i][j][k][l+k-j+1][1][1]=1;
                            }
                    }
    int ans=0,L,R,X,Y,Z;
    for (int i=1;i<=n;++i)
        for (int j=1;j<=m;++j)
            for (int k=j;k<=m;++k){
                if (f[i][j][k][tot][1][1]>ans) ans=f[i][j][k][tot][1][1],X=i,L=j,R=k,Y=1,Z=1;
                if (f[i][j][k][tot][1][0]>ans) ans=f[i][j][k][tot][1][0],X=i,L=j,R=k,Y=1,Z=0;
                if (f[i][j][k][tot][0][1]>ans) ans=f[i][j][k][tot][0][1],X=i,L=j,R=k,Y=0,Z=1;
                if (f[i][j][k][tot][0][0]>ans) ans=f[i][j][k][tot][0][0],X=i,L=j,R=k,Y=0,Z=0;
            }
    printf("Oil : %d\n",ans);
    print(X,L,R,tot,Y,Z);
    // for (int i=1;i<=n;++i){
    //     for (int j=1;j<=m;++j) if (vis[i][j]) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED),printf("%3d",a[i][j]),SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);else printf("%3d",a[i][j]);
    //     printf("\n");
    // }
    return 0;
}