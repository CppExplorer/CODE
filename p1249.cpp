#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=10005;
int n,m,a[N],ans[N],c[N],sum;
bool f[N];

void multiply(int x){
    memset(c,0,sizeof c);
    ans[0]+=5;
    for (int i=1;i<=ans[0];++i){
        ans[i]=ans[i]*x+c[i];
        c[i+1]+=ans[i]/10;
        ans[i]%=10;
    }
    while (!ans[ans[0]] && ans[0]>1) ans[0]--;
}

int main(){
    scanf("%d",&n);
    for (int i=2;i<=(n>>1)+1;++i){
        sum+=i; f[i]=1;
        if (sum>n) {f[sum-n]=0; break;}
    }
    for (int i=1;i<=n;++i) if (f[i]) a[++m]=i;
    for (int i=1;i<=m;++i) printf("%d ",a[i]);
    printf("\n");
    ans[0]=ans[1]=1;
    for (int i=1;i<=m;++i) multiply(a[i]);
    for (int i=ans[0];i;--i) printf("%d",ans[i]);
    return 0;
}