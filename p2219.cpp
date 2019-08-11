#include<bits/stdc++.h>
using namespace std;
const int N=1005;
int n,m,A,B,C,D,sum[N][N],ab[N][N],cd[N][N],x[N][N],y[N][N],q[N],h,t,ans=-INT_MAX;
int main(){
    scanf("%d%d%d%d%d%d",&n,&m,&A,&B,&C,&D);
    for (int i=1;i<=n;++i)
        for (int j=1;j<=m;++j){
            scanf("%d",&sum[i][j]);
            sum[i][j]=sum[i][j]+sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
        }
    for (int i=A;i<=n;++i)
        for (int j=B;j<=m;++j)
        ab[i][j]=sum[i][j]-sum[i-A][j]-sum[i][j-B]+sum[i-A][j-B];
    for (int i=C+1;i<n;++i)
        for (int j=D+1;j<m;++j)
        cd[i][j]=sum[i][j]-sum[i-C][j]-sum[i][j-D]+sum[i-C][j-D];
    for (int i=C+1;i<n;++i){
        h=1; t=0;
        for (int j=D+1;j<m;++j){
            while (h<=t && q[h]<j-B+2+D) h++;
            while (h<=t && cd[i][q[t]]>=cd[i][j]) t--;
            q[++t]=j;
            if (j>=B-1) x[i][j+1]=cd[i][q[h]];
        }
    }
    for (int j=B;j<=m;++j){
        h=1; t=0;
        for (int i=C+1;i<n;++i){
            while (h<=t && q[h]<i-A+2+C) h++;
            while (h<=t && x[q[t]][j]>=x[i][j]) t--;
            q[++t]=i;
            if (i>=A-1) y[i+1][j]=x[q[h]][j];
        }
    }
    for (int i=A;i<=n;++i)  
        for (int j=B;j<=m;++j)
        ans=max(ans,ab[i][j]-y[i][j]);
    printf("%d",ans);
    return 0;
}
