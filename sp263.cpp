#include<bits/stdc++.h>
using namespace std;
const int N=1000005;
int T,n,nxt[N];
char s[N];
int main(){
    scanf("%d",&T);
    for (int k=1;k<=T;++k){
        memset(nxt,0,sizeof nxt);
        scanf("%d%s",&n,s+1);
        for (int i=2,j=0;i<=n;++i){
            while (j>0 && s[i]!=s[j+1]) j=nxt[j];
            if (s[i]==s[j+1]) j++;
            nxt[i]=j;
        }
        printf("Test case #%d\n",k);
        for (int i=1;i<=n;++i)
            if (i%(i-nxt[i])==0 && i/(i-nxt[i])>1) printf("%d %d\n",i,i/(i-nxt[i]));
        printf("\n");
    }
    return 0;
}