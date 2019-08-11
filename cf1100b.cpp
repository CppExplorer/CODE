#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int N=1e5+5;
int n,m,cnt=0x7f7f7f7f,f[N];
vector<int> v[N];
int main(){
    scanf("%d%d",&n,&m);
    for (int i=1,x;i<=m;++i){
        scanf("%d",&x);
        v[x].push_back(i);
    }
    for (int i=1;i<=n;++i){
        int len=v[i].size();
        cnt=min(cnt,len);
    }
    for (int i=0;i<cnt;++i){
        int pos=0;
        for (int j=1;j<=n;++j) pos=max(pos,v[j][i]);
        f[pos]=1;
    }
    for (int i=1;i<=m;++i) printf("%d",f[i]);
    return 0;
}