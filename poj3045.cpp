#include<cstdio>
#include<algorithm>
using namespace std;
int w,n,ans=-2e9;
struct acrobat{
    int w,s,sum;
}a[50005];

bool cmp(acrobat x,acrobat y){
    return x.sum<y.sum;
}

int main(){
    scanf("%d",&n);
    for (int i=1;i<=n;++i){
        scanf("%d%d",&a[i].w,&a[i].s);
        a[i].sum=a[i].w+a[i].s;
    }
    if (n==1){
        printf("%d",-1*a[1].s);
        return 0;
    }
    sort(a+1,a+1+n,cmp);
    w=a[1].w;
    for (int i=2;i<=n;++i){
        ans=max(ans,w-a[i].s);
        w+=a[i].w;
    }
    printf("%d",ans);
    return 0;
}