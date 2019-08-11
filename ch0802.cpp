#include<bits/stdc++.h>
using namespace std;
int a[15][100],h[15],t[15],hp,ans;
char ch;
bool flag=1,f[15][100];

bool check(int i){
    for (int j=t[i];j>h[i];--j)
        if (a[i][j]!=a[i][j-1] || a[i][j]==13 || !f[i][j]) return false;
    if (!f[i][h[i]]) return false;
    return true;
}

int main(){
    for (int i=1;i<=13;++i)
        for (int j=4;j;--j){
            cin>>ch;
            if (ch==' ') cin>>ch;
            if (ch>='2' && ch<='9') a[i][j]=ch-'0';
            if (ch=='0') a[i][j]=10;
            if (ch=='J') a[i][j]=11;
            if (ch=='Q') a[i][j]=12;
            if (ch=='K') a[i][j]=13;
            if (ch=='A') a[i][j]=1;
        }
    for (int i=1;i<=13;++i) h[i]=1,t[i]=4;
    int now;
    while (hp<4){
        if (flag){
            now=a[13][t[13]]; t[13]--;
            flag=0;
        }
        t[now]++; a[now][t[now]]=now; f[now][t[now]]=1;
        int last=now;
        now=a[now][h[now]]; h[last]++;
        if (now==13){
            hp++; flag=1;
            /*printf("\n");
            for (int i=1;i<=12;++i){
                for (int j=t[i];j>=h[i];--j){
                    if (a[i][j]<10 && a[i][j]>1) printf("%d ",a[i][j]);
                    if (a[i][j]==10) printf("0 ");
                    if (a[i][j]==1) printf("A ");
                    if (a[i][j]==11) printf("J ");
                    if (a[i][j]==12) printf("Q ");
                    if (a[i][j]==13) printf("K ");
                }
                printf("\n");
            }*/
        }
    }
    for (int i=1;i<=12;++i) if (check(i)) ans++;
    printf("%d",ans);
    return 0;
}