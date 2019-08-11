#include<bits/stdc++.h>
using namespace std;
int n,i,top,h[100005],w[100005],s[100005];
int main(){
    scanf("%d",&n);
    while (n!=0){
        for (i=1;i<=n;++i) scanf("%d",&h[i]);
        top=0;
        n++;
        h[n]=-1;
        long long  ans=0;
        for (i=1;i<=n;++i){
            int wide=0;
            while (top>0 && h[i]<h[s[top]]){
                wide=wide+w[top];
                ans=max(ans,(long long)wide*h[s[top]]);
                top--;
            }
            top++;
            s[top]=i;
            w[top]=wide+1;
        }
        printf("%lld\n",ans);
        scanf("%d",&n);
    }
    return 0;
}