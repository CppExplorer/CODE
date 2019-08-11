#include<cstdio>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;
const int N=1e5+5;
int n,m,k,to[N],val[N],max_t;
long long f[N][205];
bool vis[N][205];
struct Redbag{
    int s,t,d,w;
}a[N];

bool operator<(const Redbag &x,const Redbag &y){
    return x.w==y.w?x.d<y.d:x.w<y.w;
}

bool cmp(Redbag x,Redbag y){
    return x.s<y.s;
}

priority_queue<Redbag> q;

int main(){
    scanf("%d%d%d",&n,&m,&k);
    for (int i=1;i<=k;++i) scanf("%d%d%d%d",&a[i].s,&a[i].t,&a[i].d,&a[i].w),max_t=max(max_t,a[i].t);
    max_t++;
    sort(a+1,a+1+k,cmp);
    int now=1;
    for (int i=a[1].s;i<=n;++i){
        for (;a[now].s<=i && a[now].t>=i;q.push(a[now++]));
        for (;!q.empty() && q.top().t<i;q.pop());
        if (!q.empty()) to[i]=q.top().d+1,val[i]=q.top().w;
    }
    memset(f,0x3f,sizeof f);
    f[a[1].s][0]=0; vis[a[1].s][0]=1;
    for (int i=a[1].s;i<=n;++i)
        for (int j=0;j<=m;++j){
            if (!vis[i][j]) continue;
            if (!to[i]){
                f[i+1][j]=min(f[i+1][j],f[i][j]);
                vis[i+1][j]=1;
                continue;
            }
            f[to[i]][j]=min(f[to[i]][j],f[i][j]+val[i]*1LL);
            vis[to[i]][j]=1;
            if (j<m) f[i+1][j+1]=min(f[i+1][j+1],f[i][j]),vis[i+1][j+1]=1;
        }
    long long ans=(1LL<<62);
    for (int i=max_t;i<=n+1;++i)
        for (int j=0;j<=m;++j) ans=min(ans,f[i][j]);
    printf("%lld",ans);
    return 0;
}