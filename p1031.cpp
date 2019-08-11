#include<bits/stdc++.h>
using namespace std;
int n,a[105],avg,ans;
int main(){
    scanf("%d",&n);
    for (int i=1;i<=n;++i){
        scanf("%d",&a[i]);
        avg+=a[i];
    }
    avg/=n;
    for (int i=1;i<n;++i)
    if (a[i]!=avg){
        ans++;
        a[i+1]+=a[i]-avg;
    }
    printf("%d",ans);
    return 0;
}