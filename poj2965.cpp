#include<iostream>
#include<cstdio>
using namespace std;
int a[5][5],ans;
char ch;
int main(){
    for (int i=1;i<=4;++i)
        for (int j=1;j<=4;++j){
            cin>>ch;
            if (ch=='+'){
                for (int k=1;k<=4;++k){
                    a[i][k]=1-a[i][k];
                    a[k][j]=1-a[k][j];
                }
                a[i][j]=1-a[i][j];
            }
        }
    for (int i=1;i<=4;++i)
        for (int j=1;j<=4;++j) ans+=a[i][j];
    printf("%d\n",ans);
    for (int i=1;i<=4;++i)
        for (int j=1;j<=4;++j)
        if (a[i][j]) printf("%d %d\n",i,j);
    return 0;
}