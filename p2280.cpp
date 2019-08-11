#include<bits/stdc++.h>
using namespace std;
int n,r,x,y,z,i,j,f[5002][5002],ans;
int main(){
    scanf("%d%d",&n,&r);
    for (i=1;i<=n;++i){
        scanf("%d%d%d",&x,&y,&z);
        f[x+1][y+1]=z;
    }
    for (i=1;i<=5001;++i)
        for (j=1;j<=5001;++j)
        f[i][j]=f[i-1][j]+f[i][j-1]-f[i-1][j-1]+f[i][j];
    for (i=r;i<=5001;++i)
        for (j=r;j<=5001;++j)
        ans=max(ans,f[i][j]-f[i-r][j]-f[i][j-r]+f[i-r][j-r]);
    printf("%d",ans);
    return 0;
}