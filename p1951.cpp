#include<bits/stdc++.h>
#define INF 0x7fffffff
using namespace std;
int n,m,b,i,head[10005],k,c[10005],l,r,s,ed,a[10005];
long long dis[10005];
deque<int>q;
struct edge{
    int c,to,node;
}e[100005];

void add_edge(int x,int y,int z){
    k++; e[k].node=y; e[k].c=z;
    e[k].to=head[x];
    head[x]=k;
}

bool spfa(int mon){
    if (mon<c[s]) return false;
    for (i=1;i<=n;++i) dis[i]=INF;
    dis[s]=0; q.push_back(s);
    while (!q.empty()){
        int x=q.front(); q.pop_front();
        if (c[x]>mon) continue;
        for (i=head[x];i;i=e[i].to){
            int y=e[i].node,z=e[i].c;
            if (c[y]>mon) continue;
            if (dis[x]+z<dis[y] && c[y]<=mon){
                dis[y]=dis[x]+z;
                if (!q.empty() && dis[y]<dis[q.front()]) q.push_front(y);
                    else q.push_back(y);
            }
        }
    }
    if (dis[ed]<b) return true;
        else return false;
}

int main(){
    scanf("%d%d%d%d%d",&n,&m,&s,&ed,&b);
    for (i=1;i<=n;++i){
        scanf("%d",&c[i]);
        a[i]=c[i];
    }
    sort(a+1,a+1+n);
    for (i=1;i<=m;++i){
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        if (x==y) continue;
        add_edge(x,y,z);
        add_edge(y,x,z);
    }
    if (!spfa(INF)){
        printf("-1");
        return 0;
    }
    l=1; r=n;
    while (l<r){
        int mid=(l+r)/2;
        if (spfa(a[mid])) r=mid;
            else l=mid+1;
    }
    printf("%d",a[l]);
    return 0;
}