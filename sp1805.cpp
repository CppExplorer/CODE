#include<cstdio>
using namespace std;
const int N=1e5+5;
int n,a[N],s[N],top,w[N];
long long ans;
int main(){
    scanf("%d",&n);
    while (n){
        for (int i=1;i<=n;++i) scanf("%d",&a[i]);
        top=ans=0; a[n+1]=-2e9;
        for (int i=1;i<=n+1;++i){
            int width=0;
            while (top && a[s[top]]>=a[i]){
                width+=w[top];
                if ((long long)width*a[s[top]]>ans) ans=(long long)width*a[s[top]];
                top--;
            }
            s[++top]=i; w[top]=width+1;
        }
        printf("%lld\n",ans);
        scanf("%d",&n);
    }
    return 0;
}