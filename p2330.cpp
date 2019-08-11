#include<bits/stdc++.h>
using namespace std;
int n,m,f[305],ans,cnt,i;
struct road{
    int x,y,z;
}a[100005];

bool cmp(road a,road b){
    return a.z<b.z;
}

int father(int x){
    if (x==f[x]) return x;
    else return f[x]=father(f[x]);
}

int main(){
    scanf("%d%d",&n,&m);
    for (i=1;i<=m;++i) scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
    sort(a+1,a+1+m,cmp);
    for (i=1;i<=n;++i) f[i]=i;
    for (i=1;i<=m;++i){
        int u=father(a[i].x),v=father(a[i].y);
        if (u!=v){
            f[u]=v;
            ans=max(ans,a[i].z);
            cnt++;
            if (cnt==n-1){
                printf("%d %d",cnt,ans);
                return 0;
            }
        }
    }
    return 0;
}