#include<cstdio>
#include<queue>
#include<vector>
using namespace std;
int n,m,sx,sy,k;
char s[105],Map[105][105];
bool f[105][105],vis[105][105];
queue<pair<int,int> > q;
vector<pair<int,int> > v;
int main(){
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;++i){
        scanf("%s",s+1);
        for (int j=1;j<=m;++j){
            Map[i][j]=s[j];
            if (s[j]=='*') sx=i,sy=j;
        }
    }
    scanf("%d",&k);
    q.push(make_pair(sx,sy));
    for (int i=1;i<=k;++i){
        scanf("%s",s+1);
        v.clear();
        for (;!q.empty();q.pop()) v.push_back(q.front()),vis[q.front().first][q.front().second]=0;
        for (int t=0;t<v.size();++t){
            int x=v[t].first,y=v[t].second;
            switch (s[1]){
            case 'E':
                for (int j=y+1;j<=m;++j){
                    if (Map[x][j]=='X') break;
                    if (!vis[x][j]) q.push(make_pair(x,j)),vis[x][j]=1;
                }
                break;
            case 'S':
                for (int j=x+1;j<=n;++j){
                    if (Map[j][y]=='X') break;
                    if (!vis[j][y]) q.push(make_pair(j,y)),vis[j][y]=1;
                }
                break;
            case 'W':
                for (int j=y-1;j;--j){
                    if (Map[x][j]=='X') break;
                    if (!vis[x][j]) q.push(make_pair(x,j)),vis[x][j]=1;
                }
                break;
            case 'N':
                for (int j=x-1;j;--j){
                    if (Map[j][y]=='X') break;
                    if (!vis[j][y]) q.push(make_pair(j,y)),vis[j][y]=1;
                }
                break;
            }
        }
    }
    while (!q.empty()){
        int x=q.front().first,y=q.front().second; q.pop();
        f[x][y]=1;
    }
    for (int i=1;i<=n;++i){
        for (int j=1;j<=m;++j) printf("%c",f[i][j]?'*':(Map[i][j]=='*'?'.':Map[i][j]));
        printf("\n");
    }
    return 0;
}