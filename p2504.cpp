#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
const int N=1005,M=1e6+5;
const double eps=1e-8;
int n,m,a[N],x[N],y[N],cnt,f[N],ans;
double max_d;
struct Edge{
    int x,y;
    double z;
}e[M];

double dist(int a,int b){
    return sqrt((x[a]-x[b])*(x[a]-x[b])+(y[a]-y[b])*(y[a]-y[b]));
}

bool cmp(Edge x,Edge y){
    return x.z+eps<y.z;
}

int father(int x){
    return f[x]==x?x:f[x]=father(f[x]);
}

int main(){
    scanf("%d",&m);
    for (int i=1;i<=m;++i) scanf("%d",&a[i]);
    scanf("%d",&n);
    for (int i=1;i<=n;++i) f[i]=i;
    for (int i=1;i<=n;++i) scanf("%d%d",&x[i],&y[i]);
    for (int i=1;i<n;++i)
        for (int j=i+1;j<=n;++j) 
            e[++cnt].x=i,e[cnt].y=j,e[cnt].z=dist(i,j);
    sort(e+1,e+1+cnt,cmp);
    int tot=0;
    for (int i=1;i<=cnt;++i){
        int u=father(e[i].x),v=father(e[i].y);
        if (u!=v){
            f[u]=v;
            max_d=max(max_d,e[i].z);
            if (++tot==n-1) break;
        }
    }
    for (int i=1;i<=m;++i) if ((double)a[i]>=max_d) ans++;
    printf("%d",ans);
    return 0;
}