#include<cstdio>
#include<cstring>
using namespace std;
int a[6],n;
int main(){
    while (scanf("%d",&n) && n!=0){
    memset(a,0,sizeof a);
    for (int i=1;i<=n;++i) scanf("%d",&a[i]);
    unsigned int f[a[1]+1][a[2]+1][a[3]+1][a[4]+1][a[5]+1];
    memset(f,0,sizeof f);
    f[0][0][0][0][0]=1;
    for (int i=0;i<=a[1];++i)
        for (int j=0;j<=a[2];++j)
            for (int k=0;k<=a[3];++k)
                for (int l=0;l<=a[4];++l)
                    for (int m=0;m<=a[5];++m){
                        unsigned int t=f[i][j][k][l][m];
                        if (i<a[1]) f[i+1][j][k][l][m]+=t;
                        if (j<a[2] && i>j) f[i][j+1][k][l][m]+=t;
                        if (k<a[3] && j>k) f[i][j][k+1][l][m]+=t;
                        if (l<a[4] && k>l) f[i][j][k][l+1][m]+=t;
                        if (m<a[5] && l>m) f[i][j][k][l][m+1]+=t;
                    }
        printf("%u\n",f[a[1]][a[2]][a[3]][a[4]][a[5]]);
    }
    return 0;
}