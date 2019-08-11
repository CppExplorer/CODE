#include<bits/stdc++.h>
using namespace std;
int n,m,b[50],e[50],tb[50],te[50],i,ans=INT_MAX,ta[50][3],a[50][3],l,cnt;

void dfs(int x,int y){
    if (tb[x]==y) return;
    for (int i=x-1;i>=1;--i) dfs(i,6-(tb[x]+y));
    //printf("move %d from %c to %c\n",x,char(b[x]-1+'A'),char(y-1+'A'));
    cnt++; ta[cnt][0]=x; ta[cnt][1]=tb[x]; ta[cnt][2]=y;
    tb[x]=y;
}

int main(){
    scanf("%d",&n);
    for (i=1;i<=3;++i){
        scanf("%d",&m);
        for (int j=1,x;j<=m;++j){
            scanf("%d",&x);
            b[x]=i;
        }
    }
    for (i=1;i<=3;++i){
        scanf("%d",&m);
        for (int j=1,x;j<=m;++j){
            scanf("%d",&x);
            e[x]=i;
        }
    }
    srand(20031022);
    for (int k=1;k<=500;++k){
        cnt=0;
        for (i=1;i<=n;++i){
            tb[i]=b[i];
            te[i]=e[i];
        }
        for (i=n;i>=1;--i) 
            if (rand()%(n-i+2)==0) dfs(i,6-(tb[i]+te[i]));
            else dfs(i,te[i]);
        for (i=n;i>=1;--i) dfs(i,te[i]);
        if (cnt<ans){
            ans=cnt;
            for (i=1;i<=cnt;++i){
                a[i][0]=ta[i][0];
                a[i][1]=ta[i][1];
                a[i][2]=ta[i][2];
            }
        }
    }
    for (i=1;i<=ans;++i) printf("move %d from %c to %c\n",a[i][0],char(a[i][1]-1+'A'),char(a[i][2]-1+'A'));
    printf("%d\n",ans);
    return 0;
}