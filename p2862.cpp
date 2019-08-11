#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int c,n,l,r,mid,sum[505][505],nx[10001],ny[10001],numx,numy;
struct node{
    int x,y;
}a[505],b[505];

bool check(int m){
    for (int i=nx[m];i<=numx;++i)
        for (int j=ny[m];j<=numy;++j){
            int tx=0,ty=0;
            if (b[i].x>=m) tx=nx[b[i].x-m];
            if (b[j].y>=m) ty=ny[b[j].y-m];
            if (sum[i][j]-sum[tx][j]-sum[i][ty]+sum[tx][ty]>=c) return true;
        }
    return false;
}

int main(){
    scanf("%d%d",&c,&n);
    for (int i=1;i<=n;++i){
        scanf("%d%d",&a[i].x,&a[i].y);
        nx[a[i].x]++; ny[a[i].y]++;
    }
    for (int i=1;i<=10000;++i){
        if (nx[i]) b[++numx].x=i;
        nx[i]=numx;
        if (ny[i]) b[++numy].y=i;
        ny[i]=numy;
    }
    for (int i=1;i<=n;++i)
        sum[nx[a[i].x]][ny[a[i].y]]++;
    for (int i=1;i<=numx;++i)
        for (int j=1;j<=numy;++j)
        sum[i][j]+=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
    l=1; r=10000;
    while (l<r){
        mid=(l+r)>>1;
        if (check(mid)) r=mid;
            else l=mid+1;
    }
    printf("%d",l);
    return 0;
}