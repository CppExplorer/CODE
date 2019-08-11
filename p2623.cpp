#include<cstdio>
#include<algorithm>
using namespace std;
const int N=2e5+5;
int n,m,id[N],c[N],cnt[N],tot;
long long f[2005],v[N];

void OneZeroPack(int c,long long v){
    for (int i=m;i>=c;--i)
        f[i]=max(f[i],f[i-c]+v);
}

void CompletePack(int c,long long v){
    for (int i=c;i<=m;++i)
        f[i]=max(f[i],f[i-c]+v);
}

void MutiplePack(int c,long long v,int cnt){
    if ((long long)c*cnt>=m){CompletePack(c,v); return;}
    for (int i=1;i<cnt;i<<=1) OneZeroPack(c*i,v*i),cnt-=i;
    OneZeroPack(c*cnt,v*cnt);
}

int main(){
    scanf("%d%d",&n,&m);
    for (int i=1,x,y,z,ct;i<=n;++i){
        scanf("%d%d%d",&x,&y,&z);
        if (x==1){
            for (int j=1;j<=m;++j)
                c[++tot]=j,v[tot]=1LL*y*j*j-1LL*z*j,id[tot]=x;
        }
        if (x==2){
            c[++tot]=z,v[tot]=y,id[tot]=x;
            scanf("%d",&ct);
            cnt[tot]=ct;
        }
        if (x==3) c[++tot]=z,v[tot]=y,id[tot]=x;
    }
    for (int i=1;i<=tot;++i){
        switch (id[i]){
        case 1:
            OneZeroPack(c[i],v[i]);
            break;
        case 2:
            MutiplePack(c[i],v[i],cnt[i]);
            break;
        case 3:
            CompletePack(c[i],v[i]);
            break;
        }
    }
    long long ans=0;
    for (int i=0;i<=m;++i) ans=max(ans,f[i]);
    printf("%lld",ans);
    return 0;
}