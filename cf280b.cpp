#include<bits/stdc++.h>
using namespace std;
int n,x,i,top,s[100005],ans;
int main(){
    scanf("%d",&n);
    for (i=1;i<=n;++i){
        scanf("%d",&x);
        while (top && x>=s[top]){
            ans=max(ans,x^s[top]);
            top--;
        }
        if (top) ans=max(ans,x^s[top]);
        top++; s[top]=x;
    }
    printf("%d",ans);
    return 0;
}