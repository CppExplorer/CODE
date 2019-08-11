#include<bits/stdc++.h>
using namespace std;
int n,k,i,j,a[250005],c[500005],f[500005],l,r,ans;
bool b[500005];

bool cmp(int x,int y){
    return x<y;
}

int main(){
    scanf("%d%d",&n,&k);
    for (i=1;i<=k;++i) scanf("%d",&a[i]);
    sort(a+1,a+1+k,cmp);
    for (i=1;i<=n;++i){
        scanf("%d",&c[i]);
        f[i]=INT_MAX;
    }
    for (i=1;i<k;++i){
        if (c[a[i]]>=c[a[i+1]]){
            printf("impossible");
            return 0;
        }
        for (j=a[i]+1;j<a[i+1];++j)
            if (c[j]<=c[a[i]] || c[j]>=c[a[i+1]]) b[j]=1;
    }
    for (i=1;i<a[1];++i) if (c[i]>=c[a[1]]) b[i]=1;
    for (i=a[k]+1;i<=n;++i) if (c[i]<=c[a[k]]) b[i]=1;
    for (i=1;i<=n;++i)
    if (!b[i]){
        l=1; r=n;
        while (l<r){
            int mid=(l+r)/2;
            if (c[i]<=f[mid]) r=mid;
                else l=mid+1;
        }
        f[r]=c[i];
        ans=max(r,ans);
    }
    printf("%d",ans);
    return 0;
}