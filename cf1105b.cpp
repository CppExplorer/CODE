#include<cstdio>
using namespace std;
const int N=2e5+5;
unsigned long long a[26],p[N],f[N];
int n,k,cnt[26];
char s[N];
int main(){
    scanf("%d%d%s",&n,&k,s+1);
    p[0]=1;
    for (int i=1;i<=n;++i){
        f[i]=f[i-1]*131+s[i]-'a';
        p[i]=p[i-1]*131;
    }
    for (int i=0;i<26;++i)
        for (int j=0;j<k;++j)
        a[i]+=i*p[j];
    // for (int i=0;i<26;++i) printf("%lu ",a[i]);
    for (int i=1;i<=n;){
        bool flag=0;
        for (int j=0;j<26;++j)
            if (f[i+k-1]-f[i-1]*p[k]==a[j]) cnt[j]++,i+=k,flag=1;
        if (!flag) i++;
    }
    int ans=0;
    for (int i=0;i<26;++i) if (cnt[i]>ans) ans=cnt[i];
    printf("%d",ans);
    return 0;
}