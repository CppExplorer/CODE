#include<cstdio>
#include<queue>
#include<vector>
using namespace std;
const int N=1005,tx[4]={0,0,-1,1},ty[4]={1,-1,0,0};
int n,m,p,s[10],cnt[10];
bool vis[N][N];
char str[N],a[N][N];
struct Map{
    int x,y;
};

bool check(int x,int y,int color){
    if (x<1 || x>n || y<1 || y>m || (a[x][y]-'0'!=color && a[x][y]!='.') || vis[x][y]) return false;
    return true;
}

queue<Map> q[10];
vector<Map> v;
int main(){
    scanf("%d%d%d",&n,&m,&p);
    for (int i=1;i<=p;++i) scanf("%d",&s[i]);
    for (int i=1;i<=n;++i){
        scanf("%s",str+1);
        for (int j=1;j<=m;++j){
            a[i][j]=str[j];
            if (str[j]>='0' && str[j]<='9') q[str[j]-'0'].push((Map){i,j}),vis[i][j]=1;
        }
    }
    for (int i=1;;){
        v.clear();
        for (int t=1;t<=s[i];++t){
            bool flag=0;
            while (!q[i].empty()){
                int x=q[i].front().x,y=q[i].front().y; q[i].pop();
                // printf("%d %d %d\n",i,x,y);
                for (int k=0;k<4;++k){
                    int xx=x+tx[k],yy=y+ty[k];
                    if (check(xx,yy,i)){
                        a[xx][yy]=i+'0'; flag=1;
                        vis[xx][yy]=1;
                        v.push_back((Map){xx,yy});
                    }
                }
            }
            if (!flag) break;
            for (int j=0;j<v.size();++j) q[i].push(v[j]);
        }
        bool bol=0;
        for (int j=1;j<=p;++j) if (!q[j].empty()){bol=1; break;}
        if (!bol) break;
        i++; if (i>p) i=1;
    }
    // printf("\n");
    // for (int i=1;i<=n;++i){
    //     for (int j=1;j<=m;++j) printf("%c",a[i][j]);
    //     printf("\n");
    // }
    for (int i=1;i<=n;++i)
        for (int j=1;j<=m;++j) if (a[i][j]>='0' && a[i][j]<='9') cnt[a[i][j]-'0']++;
    for (int i=1;i<=p;++i) printf("%d ",cnt[i]);
    return 0;
}
/*
戚里绸缪意转深
洋洋流水自天心
牛羊满地无人识
逼入西山一片阴
无人能识李将军
敌国风流属使君
啦客自怜天下士

戚洋牛逼无敌啦
*/