#include<cstdio>
#include<algorithm>
using namespace std;
const int N=20;
int n,w,c[N],ans=0x7f7f7f7f,cab[N];
bool f[N];

bool cmp(int x,int y){
	return x>y;
}

void dfs(int num,int cnt){
	if (cnt>=ans) return;
	if (num==n+1){
		ans=min(ans,cnt);
		return;
	}
	for (int i=1;i<=cnt;++i)
		if (cab[i]+c[num]<=w){
			cab[i]+=c[num];
			dfs(num+1,cnt);
			cab[i]-=c[num];
		}
	cab[cnt+1]=c[num];
	dfs(num+1,cnt+1);
	cab[cnt+1]=0;
}

int main(){
	scanf("%d%d",&n,&w);
	for (int i=1;i<=n;++i) scanf("%d",&c[i]);
	sort(c+1,c+1+n,cmp);
	dfs(0,0);
	printf("%d",ans);
	return 0;
}