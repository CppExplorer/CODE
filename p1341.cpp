#include<bits/stdc++.h>
using namespace std;
int n,i,ans[150],d[150],b,cnt,a[150][150],m;
char s[3];

void dfs(int x){
    for (int i=65;i<=122;++i)
    if (a[x][i]){
        a[x][i]--; a[i][x]--;
        dfs(i);
    }
    m++; ans[m]=x;
}

int main(){
    scanf("%d",&n);
    for (i=1;i<=n;++i){
        scanf("%s",s);
        a[s[0]][s[1]]++;
        a[s[1]][s[0]]++;
        d[s[0]]++; d[s[1]]++;
    }
    for (i=122;i>=65;--i)
    if (d[i]%2==1){
        b=i;
        cnt++;
    }
    if (cnt && cnt!=2){
        printf("No Solution");
        return 0;
    }
    if (b==0) for (i=65;i<=122;++i) if (d[i]){b=i; break;}
    dfs(b);
    if (m!=n+1){
        printf("No Solution");
        return 0;
    }
    for (i=m;i>=1;--i) printf("%c",ans[i]);
    return 0;
}