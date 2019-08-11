#include<cstdio>
#include<cstring>
using namespace std;
const int N=10005;
char a[N],b[N],n;
long long ans=1;
int main(){
	scanf("%s%s",a+1,b+1);
	n=strlen(a+1);
	for (int i=1;i<n;++i)
		for (int j=2;j<=n;++j) if (a[i]==b[j] && a[i+1]==b[j-1]) ans<<=1;
	printf("%lld",ans);
	return 0;
}