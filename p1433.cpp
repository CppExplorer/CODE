#include<bits/stdc++.h>
#define lf double
using namespace std;
int n,i,j;
lf x[20],y[20],ans=INT_MAX;
bool vis[20];

lf distance(lf x1,lf y1,lf x2,lf y2){
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

void dfs(lf a,lf b,lf dis,int k){
    if (dis>ans) return;
    if (k==n){
        if (dis<ans) ans=dis;
        return;
    }
    for (int i=1;i<=n;++i)
    if (!vis[i]){
        vis[i]=1;
        dfs(x[i],y[i],dis+distance(a,b,x[i],y[i]),k+1);
        vis[i]=0;
    }
}

int main(){
    scanf("%d",&n);
    for (i=1;i<=n;++i) scanf("%lf%lf",&x[i],&y[i]);
    dfs(0,0,0,0);
    printf("%.2lf",ans);
    return 0;
}