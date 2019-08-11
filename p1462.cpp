#include<bits/stdc++.h>
#define INF 0x7fffffff
using namespace std;
int n,m,b,i,head[10005],k,c[10005],l,r;
long long dis[10005];
int h,t,q[1000005];
bool f[10005];
struct edge{
    int c,to,node;
}e[100005];

void add_edge(int x,int y,int z){
    k++; e[k].node=y; e[k].c=z;
    e[k].to=head[x];
    head[x]=k;
}

bool spfa(int mon){
    if (mon<c[1]) return false;
    for (i=1;i<=n;++i) dis[i]=INF;
    dis[1]=0; h=0; t=1; q[t]=1; f[1]=1;
    while (h<t){
        h++; int x=q[h]; f[x]=0;
        for (i=head[x];i;i=e[i].to){
            int y=e[i].node,z=e[i].c;
            if (dis[x]+z<dis[y] && c[y]<=mon){
                dis[y]=dis[x]+z;
                if (!f[y]){
                    t++; q[t]=y; f[y]=1;
                }
            }
        }
    }
    if (dis[n]<b) return true;
        else return false;
}

int main(){
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);

    scanf("%d%d%d",&n,&m,&b);
    for (i=1;i<=n;++i){
        scanf("%d",&c[i]);
        r=max(r,c[i]);
    }
    l=max(c[1],c[n]);
    for (i=1;i<=m;++i){
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        add_edge(x,y,z);
        add_edge(y,x,z);
    }
    if (!spfa(INF)){
        printf("AFK");
        return 0;
    }
    while (l<r){
        int mid=(l+r)/2;
        if (spfa(mid)) r=mid;
            else l=mid+1;
    }
    printf("%d",l);
    return 0;
}