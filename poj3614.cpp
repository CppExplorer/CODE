#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,ans;
struct cow{
    int min,max;
}a[2505];
struct suncream{
    int val,cnt;
}b[2505];

bool cmp1(cow x,cow y){
    return x.min>y.min;
}

bool cmp2(suncream x,suncream y){
    return x.val>y.val;
}

int main(){
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;++i) scanf("%d%d",&a[i].min,&a[i].max);
    for (int i=1;i<=m;++i) scanf("%d%d",&b[i].val,&b[i].cnt);
    sort(a+1,a+1+n,cmp1);
    sort(b+1,b+1+m,cmp2);
    for (int i=1;i<=n;++i)
        for (int j=1;j<=m;++j)
            if (b[j].val>=a[i].min && b[j].val<=a[i].max && b[j].cnt){
                b[j].cnt--;ans++;break;
            }
    printf("%d",ans);
    return 0;
}