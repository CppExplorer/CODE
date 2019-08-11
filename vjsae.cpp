#include<cstdio>
#include<cstring>
using namespace std;
char s[1000005];
int nxt[1000005];
int main(){
    scanf("%s",s+1);
    while (s[1]!='.'){
        int n=strlen(s+1);
        nxt[1]=0;
        for (int i=2,j=0;i<=n;++i){
            while (j>0 && s[i]!=s[j+1]) j=nxt[j];
            if (s[i]==s[j+1]) j++;
            nxt[i]=j;
        }
        if (n%(n-nxt[n])==0) printf("%d\n",n/(n-nxt[n]));
            else printf("1\n");
        scanf("%s",s+1);
    }
    return 0;
}