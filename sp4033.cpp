#include<cstdio>
#include<cstring>
using namespace std;
const int N=1e4+5;
int T,n,t[N*10][10],tot=1,ed[N*10];
char s[N][20];

void insert(int num){
    int len=strlen(s[num]),p=1;
    for (int i=0;i<len;++i){
        int ch=s[num][i]-'0';
        if (!t[p][ch]) t[p][ch]=++tot;
        p=t[p][ch];
    }
    ed[p]=num;
}

bool search(int num){
    int len=strlen(s[num]),p=1;
    for (int i=0;i<len;++i){
        p=t[p][s[num][i]-'0'];
        if (ed[p] && ed[p]!=num) return true;
        if (!p) return false;
    }
    return false;
}

int main(){
    scanf("%d",&T);
    while (T--){
        tot=1; bool flag=0;
        memset(t,0,sizeof t);
        memset(ed,0,sizeof ed);
        scanf("%d",&n);
        for (int i=1;i<=n;++i){
            scanf("%s",s[i]);
            insert(i);
        }
        for (int i=1;i<=n;++i)
            if (search(i)){
                printf("NO\n"); flag=1;
                break;
            }
        if (!flag) printf("YES\n");
    }
    return 0;
}