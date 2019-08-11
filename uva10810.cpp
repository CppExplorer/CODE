#include<bits/stdc++.h>
using namespace std;
int n,a[500005],b[500005];
long long ans;

void M(int l,int mid,int r){
    int i=l,j=mid+1;
    for (int k=l;k<=r;++k){
        if (j>r || (i<=mid && a[i]<=a[j])) b[k]=a[i++];
        else b[k]=a[j++],ans+=mid-i+1;
    }
    for (int k=l;k<=r;++k) a[k]=b[k];
}

void mergesort(int l,int r){
    if (l>=r) return;
    int mid=(l+r)>>1;
    mergesort(l,mid);
    mergesort(mid+1,r);
    M(l,mid,r);
}

int main(){
    scanf("%d",&n);
    while (n){
        ans=0;
        for (int i=1;i<=n;++i) scanf("%d",&a[i]);
        mergesort(1,n);
        printf("%lld\n",ans);
        scanf("%d",&n);
    }
    return 0;
}