#include<bits/stdc++.h>
#define INF 0x3fffffff
using namespace std;
int n,m,i,j,t[205],a[205][205],q;

void Floyd(int k){
    for (int i=0;i<n;++i)
        for (int j=0;j<n;++j)
        if (i!=k && j!=k && i!=j)
            if (a[i][k]+a[k][j]<a[i][j]) 
                a[i][j]=a[i][k]+a[k][j];
}

int main(){
    scanf("%d%d",&n,&m);
    for (i=0;i<n;++i) scanf("%d",&t[i]);
    for (i=0;i<n;++i)
        for (j=0;j<n;++j) a[i][j]=INF;
    for (i=1;i<=m;++i){
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        a[x][y]=z;
        a[y][x]=z;
    }
    scanf("%d",&q);
    j=0;
    for (i=1;i<=q;++i){
        int x,y,tm;
        scanf("%d%d%d",&x,&y,&tm);
        while (t[j]<=tm && j<n){
            Floyd(j);
            j++;
        }
        if (t[x]>tm || t[y]>tm) printf("-1\n");
        else if (a[x][y]==INF) printf("-1\n");
        else printf("%d\n",a[x][y]);
    }
    return 0;
}