#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#define INF 0x3f3f3f3f
using namespace std;
const int N=1e5+5;
int n,x0,m,Min1[N],Min2[N],pre[N],nxt[N],rk[N],pos;
long long A[N][20],B[N][20],f[N][20],H[N];
double ans=0x7f7f7f7f;
struct Height{
    long long h,id;
}h[N];

bool cmp(Height a,Height b){
    return a.h<b.h;
}

void Get_Min(int u,int i){
    if (pre[u] && (!nxt[u] || h[u].h-h[pre[u]].h<=h[nxt[u]].h-h[u].h)){
        Min1[i]=h[pre[u]].id;
        if (pre[pre[u]] && (!nxt[u] || h[u].h-h[pre[pre[u]]].h<=h[nxt[u]].h-h[u].h)) Min2[i]=h[pre[pre[u]]].id;
            else if (nxt[u]) Min2[i]=h[nxt[u]].id;
    }else if (nxt[u]){
        Min1[i]=h[nxt[u]].id;
        if (pre[u] && (!nxt[nxt[u]] || h[nxt[nxt[u]]].h-h[u].h>=h[u].h-h[pre[u]].h)) Min2[i]=h[pre[u]].id;
            else if (nxt[nxt[u]]) Min2[i]=h[nxt[nxt[u]]].id;
    }
    nxt[pre[u]]=nxt[u];
    pre[nxt[u]]=pre[u];
}

void pre_work(){
    memset(A,INF,sizeof A);
    memset(B,INF,sizeof B);
    sort(h+1,h+1+n,cmp);
    for (int i=1;i<=n;++i) pre[i]=i-1,nxt[i]=i+1;
    nxt[n]=0;
    for (int i=1;i<=n;++i) rk[h[i].id]=i;
    for (int i=1;i<=n;++i)
        Get_Min(rk[i],i);
    for (int i=1;i<=n;++i){
        if (Min2[i]) A[i][0]=abs(H[Min2[i]]-H[i]);
        if (Min2[i] && Min1[Min2[i]]) B[i][0]=abs(H[Min2[i]]-H[Min1[Min2[i]]]);
        f[i][0]=Min1[Min2[i]];
    }
    for (int j=1;(1<<j)<=n;++j)
        for (int i=1;i<=n;++i){
            f[i][j]=f[f[i][j-1]][j-1];
            if (A[i][j-1]<INF && A[f[i][j-1]][j-1]<INF) A[i][j]=A[i][j-1]+A[f[i][j-1]][j-1];
            if (B[i][j-1]<INF && B[f[i][j-1]][j-1]<INF) B[i][j]=B[i][j-1]+B[f[i][j-1]][j-1];
        }
}

int main(){
    scanf("%d",&n);
    for (int i=1;i<=n;++i) scanf("%lld",&H[i]),h[i].h=H[i],h[i].id=i;
    pre_work();
    scanf("%d%d",&x0,&m);
    int t=log(n)/log(2)+1;
    for (int i=1;i<=n;++i){
        long long da=0,db=0;
        int s=i;
        for (int j=t;j>=0;--j)
            if (da+A[s][j]+db+B[s][j]<=x0) da+=A[s][j],db+=B[s][j],s=f[s][j];
        if (da+A[s][0]+db<=x0)da+=A[s][0];
        if (!db) continue;
        if (((double)da)/db<ans) ans=((double)da)/db,pos=i;
    }
    printf("%d\n",pos);
    for (int i=1,s,x;i<=m;++i){
        scanf("%d%d",&s,&x);
        long long da=0,db=0;
        for (int j=t;j>=0;--j)
            if (da+A[s][j]+db+B[s][j]<=x) da+=A[s][j],db+=B[s][j],s=f[s][j];
        if (da+A[s][0]+db<=x) da+=A[s][0];
        printf("%lld %lld\n",da,db);
    }
    return 0;
}