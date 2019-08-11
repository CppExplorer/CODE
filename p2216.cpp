#include<bits/stdc++.h>
using namespace std;
const int N=1005;
int n,m,l,a[N][N],maxv[N][N][10],minv[N][N][10],ans=INT_MAX;
int main(){
    scanf("%d%d%d",&n,&m,&l);
    for (int i=1;i<=n;++i)
        for (int j=1;j<=m;++j){
            scanf("%d",&a[i][j]);
            maxv[i][j][0]=minv[i][j][0]=a[i][j];
        }
    int t=log(l)/log(2)+1;
    for (int k=1;k<t;++k)
        for (int i=1;i<=n-(1<<k)+1;++i)
            for (int j=1;j<=m-(1<<k)+1;++j){
                maxv[i][j][k]=max(max(maxv[i][j][k-1],max(maxv[i+(1<<(k-1))][j][k-1],maxv[i][j+(1<<(k-1))][k-1])),maxv[i+(1<<(k-1))][j+(1<<(k-1))][k-1]);
                minv[i][j][k]=min(minv[i][j][k-1],min(minv[i+(1<<(k-1))][j+(1<<(k-1))][k-1],min(minv[i+(1<<(k-1))][j][k-1],minv[i][j+(1<<(k-1))][k-1])));
            }
    t--;
    for (int i=1;i<=n-l+1;++i)
        for (int j=1;j<=m-l+1;++j){
            int maxa=max(maxv[i][j][t],max(maxv[i+l-(1<<t)][j+l-(1<<t)][t],max(maxv[i+l-(1<<t)][j][t],maxv[i][j+l-(1<<t)][t])));
            int mina=min(minv[i][j][t],min(minv[i+l-(1<<t)][j+l-(1<<t)][t],min(minv[i+l-(1<<t)][j][t],minv[i][j+l-(1<<t)][t])));
            //printf("%d %d\n",maxa,mina);
            ans=min(ans,maxa-mina);
        }
    printf("%d",ans);
    return 0;
}