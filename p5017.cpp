#include <bits/stdc++.h>
using namespace std;
int n,m,t,a[505],r[4000005],s[4000005],f[4000005],i,j;
int main(){
	scanf("%d%d",&n,&m);
	for (i=1;i<=n;++i){
		scanf("%d",&a[i]);
		r[a[i]]++;
		s[a[i]]+=a[i];
		t=max(t,a[i]);
	}
	for (i=1;i<t+m;++i){
		r[i]+=r[i-1];
		s[i]+=s[i-1];
	}
	for (i=0;i<t+m;++i){
		if(i>=m && r[i]==r[i-m]){
			f[i]=f[i-m];
			continue;
		}
		f[i]=r[i]*i-s[i];
		int begin=i-m*2+1;
		begin=max(begin,0);
		for (j=begin;j<=i-m;++j)
		  f[i]=min(f[i],f[j]+(r[i]-r[j])*i-(s[i]-s[j]));
	}
	int ans=INT_MAX;
	for (i=t;i<t+m;++i)
	  ans=min(ans,f[i]);
	printf("%d",ans);
	return 0;
}