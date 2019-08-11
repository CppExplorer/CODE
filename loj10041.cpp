#include<cstdio>
#include<vector>
using namespace std;
const int N=2e6,Mod=999991;
int A,B,C;
long long a[N+5];
vector<long long> v[N+1];

bool find(long long x){
    long long t=x%Mod;
    for (int i=0;i<v[t].size();++i) if (v[t][i]==x) return true;
    v[t].push_back(x);
    return false;
}

int main(){
    scanf("%d%d%d",&A,&B,&C);
    a[0]=1; find(1);
    for (int i=1;i<=N;++i){
        a[i]=(A*a[i-1]+a[i-1]%B)%C;
        if (find(a[i])){
            printf("%d",i);
            return 0;
        }
    }
    printf("-1");
    return 0;
}