#include<bits/stdc++.h>
using namespace std;
int m,n,a[100005],i,f[100005][50];

void RMQ(){
    memset(f,0x7f,sizeof f);
    for (int i=1;i<=m;++i) f[i][0]=a[i];
    int t=log(m)/log(2)+1;
    for (int j=1;j<t;++j)
        for (int i=1;i<=m-(1<<j)+1;++i)
        f[i][j]=min(f[i][j-1],f[i+(1<<(j-1))][j-1]);
}

int ask(int l,int r){
    int k=log(r-l+1)/log(2);
    return min(f[l][k],f[r-(1<<k)+1][k]);
}

int main(){
    scanf("%d%d",&m,&n);
    for (i=1;i<=m;++i) scanf("%d",&a[i]);
    RMQ();
    for (i=1;i<=n;++i){
        int l,r;
        scanf("%d%d",&l,&r);
        printf("%d ",ask(l,r));
    }
    return 0;
}