#include<bits/stdc++.h>
using namespace std;
int n,k,h,r,a,b,c[10005];
bool f[10001][10001];
int main(){
    scanf("%d%d%d%d",&n,&k,&h,&r);
    for (int i=1;i<=r;++i){
        scanf("%d%d",&a,&b);
        if (a>b) swap(a,b);
        if (!f[a][b]){
            c[a+1]--; c[b]++;
        }
        f[a][b]=1;
    }
    c[1]+=h;
    for (int i=1;i<=n;++i) c[i]+=c[i-1];
    for (int i=1;i<=n;++i) printf("%d\n",c[i]);
    return 0;
}