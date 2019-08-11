#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
const int N=5e4+5;
double d1,c,d2,ans,dis,lp;
int n,f[N];
struct Distance{
    double d,p;
}a[N];

bool cmp(Distance x,Distance y){
    return x.d<y.d;
}

deque<int> q;
int main(){
    scanf("%lf%lf%lf%lf%d",&d1,&c,&d2,&a[0].p,&n);
    dis=c*d2;
    for (int i=1;i<=n;++i){
        scanf("%lf%lf",&a[i].d,&a[i].p);
        if (a[i].d-a[i-1].d>dis){
            printf("No Solution");
            return 0;
        }
    }
    if (d1-a[n].d>dis){
        printf("No Solution");
        return 0;
    }
    sort(a+1,a+1+n,cmp);
    for (int i=n;i>=0;--i){
        for (;!q.empty() && a[q.front()].d-a[i].d>dis;q.pop_front());
        f[i]=q.empty()?n+1:q.front();
        for (;!q.empty() && a[i].p<a[q.back()].p;q.pop_back());
        q.push_back(i);
        // f[i]=q.front();
    }
    // f[n]=0; f[n-1]=n;
    // for (int i=n-2;i;--i) if (f[i]==i) f[i]=a[f[i+1]].p<a[i+1].p?f[i+1]:i+1;
    // for (int i=0;i<=n;++i) printf("%d ",f[i]); printf("\n");
    a[++n].d=d1; ans+=c*a[0].p; lp=a[0].p;
    for (int now=0;now<n;){
        if (a[f[now]].p<=a[now].p){
            ans-=((dis-a[f[now]].d+a[now].d)/d2)*lp;
            ans+=c*a[f[now]].p;
            lp=a[f[now]].p;
            now=f[now];
        }else if (a[n].d-a[now].d<=dis){
            ans-=((dis-a[n].d+a[now].d)/d2)*lp;
            ans+=c*a[n].p;
            lp=a[n].p;
            now=n;
        }else{
            double rest=(dis-a[f[now]].d+a[now].d)/d2;
            ans+=(c-rest)*a[f[now]].p;
            lp=a[f[now]].p;
            now=f[now];
        }
    }
    printf("%.2lf",ans);
    return 0;
}