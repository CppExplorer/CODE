#include<bits/stdc++.h>
using namespace std;
int n,k,q[3000010],i,a[1000005];
int main(){
    scanf("%d%d",&n,&k);
    for (i=1;i<=n;++i) scanf("%d",&a[i]);
    int h=1,t=0;
    for (i=1;i<=n;++i){
        while (h<=t && i-q[h]>=k) h++;
        while (h<=t && a[i]<=a[q[t]]) t--;
        t++;
        q[t]=i;
        if (i>=k) printf("%d ",a[q[h]]);
    }
    printf("\n");
    h=1; t=0;
    for (i=1;i<=n;++i){
        while (h<=t && i-q[h]>=k) h++;
        while (h<=t && a[i]>=a[q[t]]) t--;
        t++;
        q[t]=i;
        if (i>=k) printf("%d ",a[q[h]]);
    }
    return 0;
}