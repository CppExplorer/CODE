#include<bits/stdc++.h>
using namespace std;
int a[4][4],b[4][4],cnt,ans=9;
int fx[5]={0,1,0,-1,0},fy[5]={0,0,1,0,-1};

bool check(){
    for (int i=1;i<=3;++i)
        for (int j=1;j<=3;++j)
        if (!a[i][j]) return false;
    return true;
}

void click(int x,int y){
    for (int i=0;i<5;++i){
        int tx=x+fx[i],ty=y+fy[i];
        if (tx>0 && tx<=3 && ty>0 && ty<=3)
            a[tx][ty]=1-a[tx][ty];
    }
}

int main(){
    for (int i=1;i<=3;++i)
        for (int j=1;j<=3;++j) scanf("%d",&b[i][j]);
    for (int i=1;i<=3;++i)
        for (int j=1;j<=3;++j) a[i][j]=b[i][j];
    for (int i=0;i<7;++i){
        cnt=0;
        for (int j=1;j<=3;++j)
        if ((i>>(j-1))&1){
            cnt++;
            click(1,j);
        }
        for (int j=1;j<=2;++j)
            for (int k=1;k<=3;++k)
            if (!a[j][k]){
                cnt++;
                click(j+1,k);
            }
        if (check()) ans=min(ans,cnt);
        for (int j=1;j<=3;++j)
            for (int k=1;k<=3;++k)
            a[j][k]=b[j][k];
    }
    printf("%d",ans);
    return 0;
}