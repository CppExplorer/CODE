#include<cstdio>
#include<cstring>
using namespace std;
const int N=1e5,Mod=1e9+9;//做题时要看清模数，别打错了QAQ
int T,n,p[N+5],jc[N+5];
bool vis[N+5];

int qpow(int x,int k){
    int ans=1;
    for (;k;k>>=1){
        if (k&1) ans=1LL*ans*x%Mod;
        x=1LL*x*x%Mod;
    }
    return ans;
}

int main(){
    jc[0]=1;
    for (int i=1;i<=N;++i) jc[i]=1LL*jc[i-1]*i%Mod;
    scanf("%d",&T);
    while (T--){
		scanf("%d",&n);
		for (int i=1;i<=n;i++) scanf("%d",&p[i]);
		memset(vis,0,sizeof vis);
		int ans=1,cnt=0;
		for (int i=1;i<=n;i++) {
			if (vis[i]) continue;
			int len=1;
			vis[i]=1;
			for (int j=p[i];j!=i;j=p[j]) vis[j]=1,len++;
			cnt++;
			ans=1LL*ans*(len==1?1:qpow(len,len-2))%Mod;
			ans=1LL*ans*qpow(jc[len-1],Mod-2)%Mod;
		}
		ans=1LL*ans*jc[n-cnt]%Mod;
		printf("%d\n",ans);
	}
    return 0;
}