/*
f_i =\sum{(p_{j}*f_{i+j})}+p0*f_0+1
f_0=K_0*f_0+B_0
K_i=\sum (p_{j}*K_{i+j})+p0
B_i=\sum (p_{j}*B_{i+j})+1
注意概率之和为1
*/
#include<cstdio>
#include<cstring>
using namespace std;
const int N=600;
int T,n,k1,k2,k3,a,b,c;
double p[20],K[N],B[N],p0;
int main(){
    scanf("%d",&T);
    while (T--){
        memset(K,0,sizeof K);
        memset(B,0,sizeof B);
        memset(p,0,sizeof p);
        scanf("%d%d%d%d%d%d%d",&n,&k1,&k2,&k3,&a,&b,&c);
        p0=(double)1/k1/k2/k3;
        for (int i=1;i<=k1;++i)
            for (int j=1;j<=k2;++j)
                for (int k=1;k<=k3;++k)
                if ((i!=a) || (j!=b) || (k!=c)) p[i+j+k]+=p0;
        for (int i=n;i>=0;--i){
            for (int j=3;j<=k1+k2+k3;++j){
                K[i]+=p[j]*K[i+j];
                B[i]+=p[j]*B[i+j];
            }
            K[i]+=p0; B[i]+=1;
        }
        printf("%.15lf",B[0]/(1-K[0]));
    }
    return 0;
}