#include<bits/stdc++.h>
using namespace std;
int n,m,i,a,b,f[2005],e[2005],ans;
bool flag[2005];
char ch;

int father(int x){
    if (f[x]==x) return x;
    else return f[x]=father(f[x]);
}

int main(){
    scanf("%d%d",&n,&m);
    for (i=1;i<=n;++i) f[i]=i;
    for (i=1;i<=m;++i){
        scanf("\n%c %d%d",&ch,&a,&b);
        if (ch=='F'){
            int x=father(a),y=father(b);
            if (x!=y) f[x]=y;
        }else{
            if (!e[a]) e[a]=b;
            else{
                int x=father(e[a]),y=father(b);
                f[x]=y;
            }
            if (!e[b]) e[b]=a;
            else{
                int x=father(e[b]),y=father(a);
                f[x]=y;
            }
        }
    }
    for (i=1;i<=n;++i){
        int x=father(i);
        flag[x]=1;
    }
    for (i=1;i<=n;++i) if (flag[i]) ans++;
    printf("%d",ans);
    return 0;
}