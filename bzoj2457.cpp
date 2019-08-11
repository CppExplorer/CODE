#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,cnt,now=INT_MAX,l[N],r[N],ans;
bool flag=1;
struct number{
    int id,val;
}a[N];

bool cmp(number x,number y){
    if (x.val==y.val) return x.id<y.id;
    return x.val<y.val;
}

int main(){
    scanf("%d",&n);
    for (int i=1;i<=n;++i){
        scanf("%d",&a[i].val);
        a[i].id=i;
    }
    sort(a+1,a+1+n,cmp);
    for (int i=1;i<=n;++i)
        if (i==1 || a[i].val!=a[i-1].val){
            l[cnt]=a[i-1].id;
            r[++cnt]=a[i].id;
        }
    l[cnt]=a[n].id;
    for (int i=1;i<=cnt;++i){
        if (!flag){
            if (now>l[i]) now=r[i];
            else now=l[i],flag=1;
        }else{
            if (now<r[i]) now=l[i];
            else now=r[i],flag=0,ans++;
        }
    }
    printf("%d",ans);
    return 0;
}