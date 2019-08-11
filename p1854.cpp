#include<cstdio>
#include<cstring>
using namespace std;
int n,m,a[105][105],f[105][105],lstI[105][105],lstJ[105][105];

void print(int n,int m){
	if (!n) return;
	print(lstI[n][m],lstJ[n][m]);
	printf("%d ",m);
}

int main(){
	//freopen("a.in","r",stdin);
	//freopen("a.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;++i)
		for (int j=1;j<=m;++j)
		scanf("%d",&a[i][j]);
	memset(f,-0x3f,sizeof f);
	f[0][0]=0;
	for (int i=1;i<=n;++i)
		for (int j=1;j<=m;++j)
			for (int k=0;k<j;++k){
				if (f[i-1][k]+a[i][j]>f[i][j]) f[i][j]=f[i-1][k]+a[i][j],lstI[i][j]=i-1,lstJ[i][j]=k;
				//printf("%d %d %d %d %d\n",i,j,f[i][j],f[i-1][k],a[i][j]);
			}
	int ans=-0x7f7f7f7f,x=n,y;
	for (int j=1;j<=m;++j) if (f[n][j]>ans) ans=f[n][j],y=j;
	printf("%d\n",ans);
	print(x,y);
}
