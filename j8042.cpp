#include<bits/stdc++.h>
using namespace std;
int n,i,k,x,tx[2005],head[1005],nxt[2005],f[1005],a[1005];
bool vis[1005];

void add_edge(int x,int y){
    k++;
    tx[k]=y;
    nxt[k]=head[x];
    head[x]=k;
}

bool cmp(int x,int y){
    return x>y;
}

void call(int x){
    int xx,y,cnt=0,son[1005];
    vis[x]=1;
    xx=head[x];
    while (xx>0){
        y=tx[xx];
        if (!vis[y]){
            call(y);
            cnt++;
            son[cnt]=f[y];
        }
        xx=nxt[xx];
    }
    if (cnt==0) f[x]=1;
    sort(son+1,son+cnt+1,cmp);
    for (int j=1;j<=cnt;++j)
        f[x]=max(f[x],son[j]+j);
}

int main(){
    scanf("%d",&n);
    for (i=2;i<=n;++i){
        scanf("%d",&x);
        add_edge(x,i);
        add_edge(i,x);
    }
    int ans=INT_MAX,sum=0;
    for (i=1;i<=n;++i){
        memset(vis,0,sizeof vis);
        memset(f,0,sizeof f);
        call(i);
        if (f[i]==ans){
            sum++;
            a[sum]=i;
        }
        if (f[i]<ans){
            ans=f[i];
            sum=1;
            a[sum]=i;
        }
    }
    printf("%d\n",ans);
    for (i=1;i<=sum;++i) printf("%d ",a[i]);
    return 0;
}