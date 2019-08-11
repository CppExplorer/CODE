#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
const int N=1e6+5;
int a[N];
unsigned long long f[N],p[N];
char s[N];
int main(){
    while (scanf("%s",s+1) && s[1]!='.'){
        int len=strlen(s+1),num=0,n=len;
        p[0]=1;
        for (int i=1;i<=len;++i){
            f[i]=f[i-1]*131+s[i];
            p[i]=p[i-1]*131;
        }
        for (int i=1;i<=n;++i)
            if (n%i==0) a[++num]=i;
        for (int i=1;i<=num;++i)
            if (f[len-a[i]]==f[len]-f[a[i]]*p[len-a[i]]){
                printf("%d\n",len/a[i]);
                break;
            }
    }
    return 0;
}