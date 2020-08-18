#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
const int N=1e5;
int T,n;
double f[N+5];
vector<int> p[N+5];
int main(){
    scanf("%d",&T);
    for (int i=1;i<=N;++i)
        for (int j=1;j<=N/i;++j) p[i*j].push_back(i);
    for (int i=2;i<=N;++i){
        for (int j=0;j<p[i].size()-1;++j) f[i]+=1/(double)(p[i].size()-1)*f[p[i][j]];
        f[i]+=p[i].size()/(double)(p[i].size()-1);
    }
    for (int c=1;c<=T;++c){
        scanf("%d",&n);
        printf("Case %d: %.7lf\n",c,f[n]);
    }
    return 0;
}