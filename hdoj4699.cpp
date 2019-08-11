#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int A[N],B[N],a,b,sum[N],f[N],n,x;
char cmd;
int main(){
    while (scanf("%d",&n)!=EOF){
        f[0]=-INT_MAX; sum[0]=0; a=0; b=0;
        for (int i=1;i<=n;++i){
            scanf("\n%c",&cmd);
            switch (cmd){
                case 'I':
                    scanf("%d",&x);
                    A[++a]=x;
                    sum[a]=sum[a-1]+x;
                    f[a]=max(f[a-1],sum[a]);
                    break;
                case 'D':
                    a--;
                    break;
                case 'L':
                    if (a) B[++b]=A[a--];
                    break;
                case 'R':
                    if (b){
                        A[++a]=B[b];
                        sum[a]=sum[a-1]+B[b--];
                        f[a]=max(f[a-1],sum[a]);
                    }
                    break;
                case 'Q':
                    scanf("%d",&x);
                    printf("%d\n",f[x]);
                    break;
            }
        }
    }
    return 0;
}
