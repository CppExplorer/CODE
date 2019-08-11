#include<cstdio>
#include<cstring>
using namespace std;
int n,m,f[2][301][301],c[301][301],a[3001];
short lstJ[3001][301][301],lstK[3001][301][301];
char ab[3001][301][301];

void write(int x,int A,int B){
    if (!x) return;
    // printf("! %d %d\n",A,B);
    write(x-1,lstJ[x][A][B],lstK[x][A][B]);
    char c1=((int)ab[x][A][B]-'0')/3+'0',c2=(ab[x][A][B]-'0')%3+1+'0';
    printf("%d ",6-(c1-'0'+c2-'0'));
}

int main(){
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;++i)
        for (int j=1;j<=n;++j) scanf("%d",&c[i][j]);
    for (int i=1;i<=m;++i) scanf("%d",&a[i]);
    memset(f,0x3f,sizeof f);
    for (int i=0;i<=m;++i)
        for (int j=1;j<=n;++j)
            for (int k=1;k<=n;++k) ab[i][j][k]='0';
    f[0][1][2]=0; a[0]=3; ab[0][1][2]='4';
    int ans=0x7f7f7f7f,now=1,lst=0;
    for (int i=1;i<=m;++i){
        for (int j=1;j<=n;++j)
            for (int k=1;k<=n;++k) f[now][j][k]=0x3f3f3f3f;
        for (int j=1;j<=n;++j)
            for (int k=1;k<=n;++k){
                char c1=((int)ab[i-1][j][k]-'0')/3+'0',c2=(ab[i-1][j][k]-'0')%3+1+'0';
                // printf("%c %c\n",c1,c2);
                if (j!=a[i] && k!=a[i] && f[lst][j][k]+c[a[i-1]][a[i]]<f[now][j][k]){
                    f[now][j][k]=f[lst][j][k]+c[a[i-1]][a[i]];
                    ab[i][j][k]=((c1-'0')*3+c2-1-'0')+'0';
                    lstJ[i][j][k]=j,lstK[i][j][k]=k;
                }
                if (a[i-1]!=a[i] && k!=a[i] && f[lst][j][k]+c[j][a[i]]<f[now][a[i-1]][k]){
                    f[now][a[i-1]][k]=f[lst][j][k]+c[j][a[i]];
                    ab[i][a[i-1]][k]=((6-(c1-'0'+c2-'0'))*3+c2-1-'0')+'0';
                    // b[i][a[i-1]][k]=6-(b[i-1][j][k]-'0'+d[i-1][j][k]-'0')+'0',d[i][a[i-1]][k]=d[i-1][j][k];
                    lstJ[i][a[i-1]][k]=j,lstK[i][a[i-1]][k]=k;
                }
                if (a[i-1]!=a[i] && j!=a[i] && f[lst][j][k]+c[k][a[i]]<f[now][j][a[i-1]]){
                    f[now][j][a[i-1]]=f[lst][j][k]+c[k][a[i]];
                    ab[i][j][a[i-1]]=((c1-'0')*3+6-(c1-'0'+c2-'0')-1)+'0';
                    // b[i][j][a[i-1]]=b[i-1][j][k],d[i][j][a[i-1]]=6-(b[i-1][j][k]-'0'+d[i-1][j][k]-'0')+'0';
                    lstJ[i][j][a[i-1]]=j,lstK[i][j][a[i-1]]=k;
                }
            }
        now^=1,lst^=1;
    }
    int A,B;
    for (int i=1;i<=n;++i)
        for (int j=1;j<=n;++j)
            if (f[lst][i][j]<ans) ans=f[lst][i][j],A=i,B=j;
    printf("%d\n",ans);
    write(m,A,B);
    return 0;
}