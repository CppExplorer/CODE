#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const int N=200005,INF=0x7f7f7f7f;
int n,m,t[N];
struct point{
    double x,y;
}a[N];

bool cmp1(point a,point b){
    if (a.x==b.x) return a.y<b.y;
    return a.x<b.x;
}

bool cmp2(int i,int j){
    return a[i].y<a[j].y;
}

double dist(int i,int j){
    return sqrt((a[i].x-a[j].x)*(a[i].x-a[j].x)+(a[i].y-a[j].y)*(a[i].y-a[j].y));
}

double Merge(int l,int r){
    if (l==r) return INF;
    if (l+1==r) return dist(l,r);
    int mid=(l+r)>>1;
    double dis=min(Merge(l,mid),Merge(mid+1,r));
    m=0;
    for (int i=l;i<=r;++i)
        if (fabs(a[mid].x-a[i].x)<dis) t[++m]=i;
    sort(t+1,t+1+m,cmp2);
    for (int i=1;i<m;++i)
        for (int j=i+1;j<=m && a[t[j]].y-a[t[i]].y<dis;++j)
        dis=min(dis,dist(t[i],t[j]));
    return dis;
}

int main(){
    scanf("%d",&n);
    for (int i=1;i<=n;++i) scanf("%lf%lf",&a[i].x,&a[i].y);
    sort(a+1,a+1+n,cmp1);
    printf("%.4lf",Merge(1,n));
    return 0;
}