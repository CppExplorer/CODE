#include<cstdio>
#include<cstring>
using namespace std;
const int N=1000005;
int n,nxt[N],cnt;
char s[N];
int main(){
    scanf("%d",&n);
    while (n){
        memset(nxt,0,sizeof nxt);
        printf("Test case #%d\n",++cnt);
        scanf("%s",s+1);
        nxt[1]=0;
        for (int i=2,j=0;i<=n;++i){
            while (j>0 && s[i]!=s[j+1]) j=nxt[j];
            if (s[i]==s[j+1]) j++;
            nxt[i]=j;
        }
        for (int i=1;i<=n;++i)
            if (i%(i-nxt[i])==0 && i/(i-nxt[i])>1) printf("%d %d\n",i,i/(i-nxt[i])); 
        printf("\n");
        scanf("%d",&n);
    }
    return 0;
}