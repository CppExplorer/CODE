#include<bits/stdc++.h>
using namespace std;
int m,n,i,j,a[1005],vis[1005],q[105],ans,t;
int main(){
    scanf("%d%d",&m,&n);
    for (i=1;i<=n;++i) scanf("%d",&a[i]);
    for (i=1;i<=n;++i){
          if (vis[a[i]]) continue;
          int minn=INT_MAX;
          if (t<m){
              t++;
              q[t]=i; ans++; vis[a[i]]=1;
              continue;
          }
          for (j=1;j<=t;++j)
            if (q[j]<minn) minn=q[j];
          for (j=1;j<=t;++j)
            if (q[j]==minn){
                vis[a[q[j]]]=0;
                q[j]=i;
                vis[a[i]]=1;
                ans++;
                break;
            }
      }
    printf("%d",ans);
    return 0;
}