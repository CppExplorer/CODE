#include<bits/stdc++.h>
using namespace std;
int n,i,nxt[100005],d[100005],vis[100005],c[100005],f[100005];
int main(){
    scanf("%d",&n);
    for (i=1;i<=n;++i) scanf("%d",&nxt[i]);
    for (i=1;i<=n;++i){
        int j=i,step=0;
        while (1){
            if (!vis[j]){
                vis[j]=i;
                d[j]=step;
            }else if (vis[j]==i){
                c[i]=step-d[j];
                f[i]=d[j];
                printf("%d\n",step);
                break;
            }else{
                c[i]=c[vis[j]];
                f[i]=step+max(f[vis[j]]-d[j],0);
                printf("%d\n",c[i]+f[i]);
                break;
            }
            j=nxt[j]; step++;
        }
    }
    return 0;
}
