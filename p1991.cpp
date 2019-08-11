#include<bits/stdc++.h>
using namespace std;
int s,p,m,i,j,x[505],y[505],f[505],cnt;
double ans;
struct road{
    int x,y;
    double z;
}a[250005];

double dis(int x1,int y1,int x2,int y2){
    return sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
}

bool cmp(road a,road b){
    return a.z<b.z;
}

int father(int x){
    if (f[x]==x) return x;
    else return f[x]=father(f[x]);
}

int main(){
    scanf("%d%d",&s,&p);
    for (i=1;i<=p;++i) scanf("%d%d",&x[i],&y[i]);
    for (i=1;i<=p;++i)
        for (j=1;j<=p;++j)
        if (i!=j){
            m++;
            a[m].x=i; a[m].y=j;
            a[m].z=dis(x[i],y[i],x[j],y[j]);
        }
    for (i=1;i<=p;++i) f[i]=i;
    sort(a+1,a+1+m,cmp);
    for (i=1;i<=m;++i){
        int u=father(a[i].x),v=father(a[i].y);
        if (u!=v){
            f[u]=v;
            if (a[i].z>ans) ans=a[i].z;
            cnt++;
            if (cnt==p-1-(s-1)){
                printf("%.2lf",ans);
                return 0;
            }
        }
    }
    return 0;
}