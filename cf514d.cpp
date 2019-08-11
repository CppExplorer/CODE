#include <bits/stdc++.h>
using namespace std;
int n,m,k,i,j,a[100005][6],f[100005][6][20],l,r,mid,sum,ans,robot[6];

bool check(int x){
	int t=log(x-i+1)/log(2);
	sum=0;
	for (int j=1;j<=m;++j)
	  sum+=max(f[i][j][t],f[x-(1<<t)+1][j][t]);
	if (sum>k) return false;
	else{
		if (x-i+1>ans){
			ans=x-i+1;
			for (int j=1;j<=m;++j)
			  robot[j]=max(f[i][j][t],f[x-(1<<t)+1][j][t]);
		}
		return true;
	}
}

int main(){
	scanf("%d%d%d",&n,&m,&k);
	for (i=1;i<=n;++i)
	  for (j=1;j<=m;++j) scanf("%d",&a[i][j]);
	for (i=1;i<=n;++i)
	  for (j=1;j<=m;++j) f[i][j][0]=a[i][j];
	int t=log(n)/log(2)+1;
	for (j=1;j<t;++j)
	  for (i=1;i<=n-(1<<j)+1;++i)
	    for (int x=1;x<=m;++x)
	    f[i][x][j]=max(f[i][x][j-1],f[i+(1<<(j-1))][x][j-1]);
	for (i=1;i<=n;++i){
		l=i; r=n;
		while (l<=r){
			mid=(l+r)/2;
			if (check(mid)) l=mid+1;
			  else r=mid-1;
		}
	}
	for (i=1;i<=m;++i)
	  printf("%d ",robot[i]);
	return 0;
}
