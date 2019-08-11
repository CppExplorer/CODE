#include<bits/stdc++.h>
using namespace std;
int n,m,i,a[200005],b[600005],c[600005],s[200005],z[200005],t[600005],cnt,ct,ans=1,ms,mz;

int query(int x){
    int l=1,r=ct;
    while (l<r){
        int mid=(l+r)>>1;
        if (t[mid]>=x) r=mid;
            else l=mid+1;
    }
    return l;
}

int main(){
    scanf("%d",&n);
    for (i=1;i<=n;++i){
        scanf("%d",&a[i]);
        cnt++; b[cnt]=a[i];
    }
    scanf("%d",&m);
    for (i=1;i<=m;++i){
        scanf("%d",&s[i]);
        cnt++; b[cnt]=s[i];
    }
    for (i=1;i<=m;++i){
        scanf("%d",&z[i]);
        cnt++; b[cnt]=z[i];
    }
    sort(b+1,b+1+cnt);
    for (i=1;i<=cnt;++i)
        if (b[i]!=b[i-1]){
            ct++; t[ct]=b[i];
        }
    for (i=1;i<=n;++i) c[query(a[i])]++;
    for (i=1;i<=m;++i){
        int x=c[query(s[i])],y=c[query(z[i])];
        if (x>ms || (x==ms && y>mz)){
            ans=i;
            ms=x; mz=y;
        }
    }
    printf("%d",ans);
    return 0;
}