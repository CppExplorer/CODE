#include<bits/stdc++.h>
using namespace std;
int n,a[6][6],i,j,k,ans,cnt;
int fx[5]={0,1,0,-1,0},fy[5]={0,0,1,0,-1};
char s[6][6];

void click(int x,int y){
    for (int i=0;i<5;++i){
        int tx=x+fx[i],ty=y+fy[i];
        if (tx>0 && tx<=5 && ty>0 && ty<=5)
            a[tx][ty]=1-a[tx][ty];
    }
}

bool check(){
    for (int i=1;i<=5;++i)
        for (int j=1;j<=5;++j)
        if (!a[i][j]) return false;
    return true;
}

int main(){
    scanf("%d",&n);
    while (n--){
        ans=25;
        for (i=1;i<=5;++i)
            for (j=1;j<=5;++j) cin>>s[i][j];
        for (i=1;i<=5;++i)
            for (j=1;j<=5;++j) a[i][j]=s[i][j]-'0';
        for (i=0;i<32;++i){
            cnt=0;
            for (j=1;j<=5;++j)
            if (((i>>(j-1))&1)!=0){
                cnt++;
                click(1,j);
            }
            for (j=1;j<=4;++j)
                for (k=1;k<=5;++k)
                if (!a[j][k]){
                    cnt++;
                    click(j+1,k);
                }
            if (check()) ans=min(ans,cnt);
            for (j=1;j<=5;++j)
                for (k=1;k<=5;++k)
                a[j][k]=s[j][k]-'0';
        }
        if (ans>6) printf("-1\n");
            else printf("%d\n",ans);
    }
    return 0;
}
