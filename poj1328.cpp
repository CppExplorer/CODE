#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
int n,t;
double d,x,y;
bool f[10005];
struct radar{
    double l,r;
}a[10005];

bool cmp(radar x,radar y){
    if (x.r==y.r) return x.l<y.l;
    return x.r<y.r;
}
int main(){
    scanf("%d%lf",&n,&d);
    while (n!=0 && d!=0){
        t++;
        bool flag=0;
        for (int i=1;i<=n;++i){
            scanf("%lf%lf",&x,&y);
            if (y>d || y<0){
                flag=1;
            }
            if (flag!=1) a[i].l=x-sqrt(d*d-y*y),a[i].r=x+sqrt(d*d-y*y);
        }
        if (flag) printf("Case %d: -1\n",t);
        if (!flag){
            sort(a+1,a+1+n,cmp);
            int ans=0;
            memset(f,0,sizeof f);
            for (int i=1;i<=n;++i)
                if (!f[i]){
                    ans++;
                    f[i]=1;
                    for (int j=i+1;j<=n;++j)
                        if (a[j].l<=a[i].r) f[j]=1;
                }
            printf("Case %d: %d\n",t,ans);
        }
        scanf("%d%lf",&n,&d);
    }
    return 0;
}