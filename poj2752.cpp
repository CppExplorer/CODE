#include<cstdio>
#include<cstring>
using namespace std;
const int N=4e5+5;
unsigned long long f1[N],p1[N],f2[N],p2[N];
char s[N];
int main(){
    while (~scanf("%s",s+1)){
        int len=strlen(s+1);
        p1[0]=p2[0]=1;
        for (int i=1;i<=len;++i){
            f1[i]=f1[i-1]*131+s[i];
            f2[i]=f2[i-1]*1331+s[i];
            p1[i]=p1[i-1]*131;
            p2[i]=p2[i-1]*1331;
        }
        for (int i=1;i<=len;++i)
            if (f1[i]==f1[len]-f1[len-i]*p1[i] && f2[i]==f2[len]-f2[len-i]*p2[i]) printf("%d ",i);
        printf("\n");            
    }
    return 0;
}