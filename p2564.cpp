#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,k,h,t,q[N],T,nn,x,l=1,r,ct[65],cnt;
struct node{
    int x,id;
}a[N];

bool cmp(node x,node y){
    return x.x<y.x;
}

bool check(int l){
    memset(ct,0,sizeof ct);
    h=1; t=0; cnt=0;
    for (int i=1;i<=n;++i){
        while (h<=t && a[i].x-a[q[h]].x>l){
            ct[a[q[h]].id]--;
            if (ct[a[q[h++]].id]==0) cnt--;
        }
        q[++t]=i; ct[a[q[t]].id]++;
        if (ct[a[q[t]].id]==1) cnt++;
        if (cnt==k) return true;
    }
    return false;
}

int main(){
    scanf("%d%d",&n,&k);
    for (int i=1;i<=k;++i){
        scanf("%d",&T);
        for (int j=1;j<=T;++j){
            scanf("%d",&x);
            a[++nn].x=x; r=max(r,x);
            a[nn].id=i;
        }
    }
    sort(a+1,a+1+n,cmp);
    //for (int i=1;i<=n;++i) printf("%d ",a[i].x);
    //printf("\n");
    //for (int i=1;i<=n;++i) printf("%d ",a[i].id);
    //printf("\n");
    while (l<r){
        int mid=(l+r)>>1;
        if (check(mid)) r=mid;
            else l=mid+1;
    }
    printf("%d",l);
    return 0;
}