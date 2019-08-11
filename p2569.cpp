#include<bits/stdc++.h>
using namespace std;
int n,m,w,f[2005][2005],ap,bp,as,bs,h,t,q[2005],ans;
int main(){
    scanf("%d%d%d",&n,&m,&w);
    memset(f,128,sizeof f);
    for (int i=1;i<=n;++i){
        scanf("%d%d%d%d",&ap,&bp,&as,&bs);
        for (int j=0;j<=as;++j) f[i][j]=-1*j*ap;
        for (int j=0;j<=m;++j) f[i][j]=max(f[i][j],f[i-1][j]);
        if (i<=w) continue;
        h=1; t=0;
        for (int j=0;j<=m;++j){
            while (h<=t && q[h]<j-as) h++;
            while (h<=t && f[i-w-1][q[t]]+q[t]*ap<=f[i-w-1][j]+j*ap) t--;
            q[++t]=j;
            f[i][j]=max(f[i][j],f[i-w-1][q[h]]+q[h]*ap-j*ap);
        }
        h=1; t=0;
        for (int j=m;j>=0;--j){
            while (h<=t && q[h]>j+bs) h++;
            while (h<=t && f[i-w-1][q[t]]+q[t]*bp<=f[i-w-1][j]+j*bp) t--;
            q[++t]=j;
            f[i][j]=max(f[i][j],f[i-w-1][q[h]]+q[h]*bp-j*bp);
        }
    }
    for (int j=0;j<=m;++j) ans=max(ans,f[n][j]);
    printf("%d",ans);
    return 0;
}