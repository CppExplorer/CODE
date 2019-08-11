#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,pos[N],p[N];
long long ans[N];
struct arr{
    int id,val,prev,next;
}a[N];

bool cmp(arr x,arr y){
    return x.val<y.val;
}

int main(){
    scanf("%d",&n);
    for (int i=1;i<=n;++i){
        scanf("%d",&a[i].val);
        a[i].id=i;
    }
    sort(a+1,a+1+n,cmp);
    for (int i=1;i<=n;++i){
        pos[a[i].id]=i;
        a[i].prev=i-1; a[i].next=i+1;
    }
    for (int i=n;i>=2;--i){
        int j=pos[i],pre=a[j].prev,nxt=a[j].next;
        if (!pre) ans[i]=abs((long long)a[j].val-a[nxt].val),p[i]=a[nxt].id;
        else if (nxt==n+1) ans[i]=abs((long long)a[j].val-a[pre].val),p[i]=a[pre].id;
        else{
            long long v1=abs((long long)a[j].val-a[pre].val),v2=abs((long long)a[j].val-a[nxt].val);
            if (v2<v1) ans[i]=v2,p[i]=a[nxt].id;
                else ans[i]=v1,p[i]=a[pre].id;
        }
        a[nxt].prev=pre; a[pre].next=nxt;
    }
    for (int i=2;i<=n;++i) printf("%lld %d\n",ans[i],p[i]);
    return 0;
}