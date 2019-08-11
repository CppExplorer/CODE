#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int T,n;
double ans;
struct location{
    int x,y,s;
}a[200005],b[200005];

bool cmp(location x,location y){
    return x.x<y.x;
}

double dist(int x1,int y1,int x2,int y2){
    return sqrt((double)(x1-x2)*(x1-x2)+(double)(y1-y2)*(y1-y2));
}

void M(int l,int mid,int r){    
    int i=l,j=mid+1;
    for (int k=l;k<=r;++k)
        if (j>r || (i<=mid && a[i].y<a[j].y)) b[k]=a[i++];
        else b[k]=a[j++];
    for (int k=l;k<=r;++k) a[k]=b[k];
}

void work(int l,int r){
    if (l==r) return;
    int mid=(l+r)>>1;
    work(l,mid);
    work(mid+1,r);
    M(l,mid,r);
    int m=0,mx=a[mid].x;
    for (int i=l;i<=r;++i)
        if (abs(a[i].x-mx)<=ans) b[++m]=a[i];
    for (int i=1;i<m;++i)
        for (int j=i+1;j<=m;++j)
        if (b[j].y-b[i].y<ans){
            if (b[i].s!=b[j].s) ans=min(ans,dist(b[i].x,b[i].y,b[j].x,b[j].y));
        }else break;
}

int main(){
    scanf("%d",&T);
    while (T--){
        scanf("%d",&n);
        for (int i=1;i<=n;++i) scanf("%d%d",&a[i].x,&a[i].y),a[i].s=1;
        for (int i=n+1;i<=n*2;++i) scanf("%d%d",&a[i].x,&a[i].y),a[i].s=2;
        n*=2;
        sort(a+1,a+1+n,cmp);
        ans=2e9;
        work(1,n);
        printf("%.3lf\n",ans);
    }
    return 0;
}