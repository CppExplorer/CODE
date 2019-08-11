#include<bits/stdc++.h>
using namespace std;
int n,m,i,trie[6000005][26],vis[6000005],tot=1;
bool end[6000005];
char s[55];

void add(char s[]){
    int tmp=1,len=strlen(s);
    for (int i=0;i<len;++i){
        int ch=s[i]-'a';
        if (trie[tmp][ch]==0){
            tot++;
            trie[tmp][ch]=tot;
        }
        tmp=trie[tmp][ch];
    }
    end[tmp]=1;
}

void find(char s[]){
    int len=strlen(s),tmp=1;
    for (int i=0;i<len;++i){
        tmp=trie[tmp][s[i]-'a'];
        if (!tmp){
            printf("WRONG\n");
            return;
        }
    }
    if (!end[tmp]){
        printf("WRONG\n");
        return;
    }
    if (!vis[tmp]){
        printf("OK\n");
        vis[tmp]++;
        return;
    }else printf("REPEAT\n");
}

int main(){
    scanf("%d",&n);
    for (i=1;i<=n;++i){
        scanf("%s",s);
        add(s);
    }
    scanf("%d",&m);
    for (i=1;i<=m;++i){
        scanf("%s",s);
        find(s);
    }
    return 0;
}