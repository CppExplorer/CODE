#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,sum[100005],f[100005];
ll ans;
struct tree{
    int x,y,z;
}a[100005];

bool cmp(tree x,tree y){
    return x.z<y.z;
}

int father(int x){
    if (f[x]==x) return x;
    else{
        f[x]=father(f[x]);
        return f[x];
    }
}
int main(){
    scanf("%d",&n);
    for (int i=1;i<n;++i) scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
    for (int i=1;i<=n;++i){
        f[i]=i;
        sum[i]=1;
    }
    sort(a+1,a+n,cmp);
    for (int i=1;i<n;++i){
        int u=father(a[i].x),v=father(a[i].y);
        ans+=((long long)sum[u]*sum[v]-1)*(a[i].z+1)+a[i].z;
        f[u]=v;
        sum[v]+=sum[u];
    }
    printf("%lld",ans);
    return 0;
}