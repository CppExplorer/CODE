#include<bits/stdc++.h>
#define inf INT_MAX/3
using namespace std;
int n,m,k,i,j,a[255][255],s,t,q,d[255][255],id[255];
struct cost{
    int no,c;
}c[255];

bool cmp(cost x,cost y){
    return x.c<y.c;
}

int main(){
    scanf("%d%d%d",&n,&m,&q);
    for (i=1;i<=n;++i){
        scanf("%d",&c[i].c);
        c[i].no=i;
    }
    sort(c+1,c+1+n,cmp);
    for (i=1;i<=n;++i) id[c[i].no]=i;
    for (i=1;i<=n;++i)
        for (j=1;j<=n;++j) a[i][j]=d[i][j]=inf;
    for (i=1;i<=m;++i){
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        a[id[x]][id[y]]=min(a[id[x]][id[y]],z);
        a[id[y]][id[x]]=min(a[id[y]][id[x]],z);
    }
    for (k=1;k<=n;++k)
        for (i=1;i<=n;++i)
            for (j=1;j<=n;++j)
            if (i!=k && j!=k && i!=j){
                a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
                d[i][j]=min(d[i][j],a[i][j]+max(max(c[i].c,c[j].c),c[k].c));
            }
    for (i=1;i<=q;++i){
        scanf("%d%d",&s,&t);
        printf("%d\n",d[id[s]][id[t]]);
    }
    return 0;
}