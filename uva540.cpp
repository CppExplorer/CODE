#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
int t,n,x,Scenario,id[1000000],cnt[1001];
bool f[1001];
char s[8];
queue<int>q[1001];
int main(){
    scanf("%d",&t);
    while (t){
        Scenario++;
        printf("Scenario #%d\n",Scenario);
        memset(f,0,sizeof f);
        memset(cnt,0,sizeof cnt);
        while (!q[0].empty()) q[0].pop();
        for (int i=1;i<=t;++i){
            scanf("%d",&n);
            for (int j=1;j<=n;++j){
                scanf("%d",&x);
                id[x]=i; 
            }
        }
        scanf("%s",s);
        while (s[0]!='S'){
            switch (s[0]){
                case 'E':
                    scanf("%d",&x);
                    if (!f[id[x]]){
                        while (!q[id[x]].empty()) q[id[x]].pop();
                        f[id[x]]=1; cnt[id[x]]=1;
                        q[id[x]].push(x);
                        q[0].push(x);
                    }else q[id[x]].push(x),cnt[id[x]]++;
                    break;
                case 'D':
                    x=q[0].front();
                    printf("%d\n",q[id[x]].front()); q[id[x]].pop(); cnt[id[x]]--;
                    if (cnt[id[x]]==0){
                        f[id[x]]=0;
                        q[0].pop();
                    }
                    break;
            }
            scanf("%s",s);
        } 
        printf("\n");
        scanf("%d",&t);
    }
    return 0;
}