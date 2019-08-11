#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll T,n,m,k,i,lr;
ll a[500005],b[500005],c[500005];

void merger(ll l,ll mid,ll r) {
	int i=l,j=mid+1;
	for (int k=l; k<=r; ++k)
		if (j>r || (i<=mid && b[i]<=b[j])) {
			c[k]=b[i];
			i++;
		} else {
			c[k]=b[j];
			j++;
		}
}

ll calc(ll l,ll r) {
	if (r>n) r=n;
	int t=min(m,(r-l+1)/2);
	for (int i=lr+1; i<=r; ++i) b[i]=a[i];
	sort(b+lr+1,b+r+1);
	merger(l,lr,r);
	ll res=0,i;
	for (i=0; i<t; ++i)
		res+=(c[r-i]-c[l+i])*(c[r-i]-c[l+i]);
	return res;
}

int main() {
	scanf("%lld",&T);
	while (T--) {
		ll ans=0;
		scanf("%lld%lld%lld",&n,&m,&k);
		for (i=1; i<=n; ++i) scanf("%d",&a[i]);
		ll l=1,r=1;
		b[1]=a[1];
		lr=1;
		while (l<=n) {
			int p=1;
			while (p) {
				ll num=calc(l,r+p);
				if (num<=k) {
					lr=r=min(r+p,n);
					for (i=l; i<=r; ++i) b[i]=c[i];
					if (r==n) break;
					p*=2;
				} else p/=2;
			}
			l=r+1;
			ans++;
		}
		printf("%lld\n",ans);
	}
	return 0;
}