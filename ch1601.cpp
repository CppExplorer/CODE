#include<bits/stdc++.h>
using namespace std;
const int N=1000005;
int n,m,t[N][26],cnt[N],tot=1;
char s[N];

void insert(char s[]){
    int len=strlen(s+1),p=1;
    for (int i=1;i<=len;++i){
        int ch=s[i]-'a';
        if (!t[p][ch]) t[p][ch]=++tot;
        p=t[p][ch];
    }
    cnt[p]++;
}

int search(char s[]){
    int ans=0,len=strlen(s+1),p=1;
    for (int i=1;i<=len;++i){
        p=t[p][s[i]-'a'];
        if (!p) return ans;
        ans+=cnt[p];
    }
    return ans;
}

int main(){
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;++i){
        scanf("%s",s+1);
        insert(s);
    }
    for (int i=1;i<=m;++i){
        scanf("%s",s+1);
        printf("%d\n",search(s));
    }
    return 0;
}