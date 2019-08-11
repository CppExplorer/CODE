#include<cstdio>
using namespace std;
const int N=2e5+5;
int n,m,k,head[N],to[N<<1],nxt[N<<1],fr[N<<1],tot,ans[N],a[N],f[N];
bool broken[N];

void add_edge(int x,int y){
    to[++tot]=y; fr[tot]=x; nxt[tot]=head[x]; head[x]=tot;
}

int father(int x){
    return f[x]==x?x:f[x]=father(f[x]);
}

int main(){
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;++i) f[i]=i;
    for (int i=1,x,y;i<=m;++i){
        scanf("%d%d",&x,&y);
        add_edge(x,y); add_edge(y,x);
    }
    scanf("%d",&k);
    for (int i=1;i<=k;++i){
        scanf("%d",&a[i]);
        broken[a[i]]=1;
    }
    ans[k+1]=n-k;
    for (int i=1;i<=tot;++i){
        int u=father(fr[i]),v=father(to[i]);
        if (!broken[fr[i]] && !broken[to[i]] && u!=v){
            ans[k+1]--; f[u]=v;
        }
    }
    for (int i=k;i;--i){
        broken[a[i]]=0;
        ans[i]=ans[i+1]+1;
        for (int j=head[a[i]];j;j=nxt[j]){
            int u=father(a[i]),v=father(to[j]);
            if (!broken[to[j]] && u!=v){    
                ans[i]--; f[u]=v;
            }
        }
    }
    for (int i=1;i<=k+1;++i) printf("%d\n",ans[i]);
    return 0;
}