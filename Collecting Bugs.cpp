#include<cstdio>
using namespace std;
const int N=1005;
int n,s;
double f[N][N];
int main(){
    scanf("%d%d",&n,&s);
    for (int i=n;i>=0;--i)
        for (int j=s;j>=0;--j)
        if ((i!=n) || (j!=s)){
            f[i][j]+=(double)i*j/(n*s-i*j);
            f[i][j]+=(double)(n-i)*j/(n*s-i*j)*(f[i+1][j]+1);
            f[i][j]+=(double)(s-j)*i/(n*s-i*j)*(f[i][j+1]+1);
            f[i][j]+=(double)(n-i)*(s-j)/(n*s-i*j)*(f[i+1][j+1]+1);
        }
    printf("%.4lf",f[0][0]);
    return 0;
}