#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,m,cnt[105],task;
long long mon;
struct tasks{
    int x,y;
}a[100005],b[100005];

bool cmp(tasks a,tasks b){
    if (a.x==b.x) return a.y>b.y;
    return a.x>b.x;
}

int main(){
    while (scanf("%d%d",&n,&m)!=EOF){
        for (int i=1;i<=n;++i) scanf("%d%d",&a[i].x,&a[i].y);
        for (int i=1;i<=m;++i) scanf("%d%d",&b[i].x,&b[i].y);
        sort(a+1,a+1+n,cmp);
        sort(b+1,b+1+m,cmp);
        int k=1; memset(cnt,0,sizeof cnt); task=mon=0;
        for (int i=1;i<=m;++i){
            while (k<=n && a[k].x>=b[i].x) cnt[a[k++].y]++;
            for (int j=b[i].y;j<=100;++j)
            if (cnt[j]){
                cnt[j]--;
                task++;
                mon+=500*b[i].x+2*b[i].y;
                break;
            }
        }
        printf("%d %lld\n",task,mon);
    }
    return 0;
}