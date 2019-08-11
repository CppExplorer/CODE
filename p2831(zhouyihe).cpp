#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<string>
#include<cstdlib>
#include<vector>
#include<queue>
#include<set>
#define forup(i,a,b)  for(int i=a;i<=b;i++)
#define fordown(i,a,b) for(int i=a;i>=b;i--)
#define pb push_back
#define maxn 100005
#define INF 1000000007
#define eps 0.0000001
using namespace std;
int q[30][30];
int n,m;
int a[maxn];
double bird[maxn][2];
bool vis[maxn];
int ans;
void work(int x,int y,double &a,double &b)
{double y1=bird[x][1],y2=bird[y][1];
double A1=bird[x][0]*bird[x][0],A2=bird[y][0]*bird[y][0];
double B1=bird[x][0],B2=bird[y][0];
   y2=y2*A1/A2,B2=B2*A1/A2;
   b=(y1-y2)/(B1-B2);
   a=(y1-b*B1)/A1;
}
bool  pd(double a,double b,int num)
{  double y=bird[num][1],x=bird[num][0];
  if(abs(y-(a*(x*x)+b*x))<=eps)  return true;
  else return false;
}

void dfs(int x,int step)
{   if(x==n+1) { if(step<ans)  ans=step; return;}
 if(vis[x]==1)  {dfs(x+1,step); return;}
  if(step+1>ans)  return ;
  vis[x]=1;
  int flag=0;
      forup(i,x+1,n)
      if(vis[i]==0&&abs(bird[x][0]-bird[i][0])>eps)
        {double a,b;work(x,i,a,b);
          if(a<0.00)
          { flag=1;
          int cnt=0;
             forup(j,i,n)  
               if(vis[j]==0&&pd(a,b,j)==true){  vis[j]=1;cnt++;q[step][cnt]=j;}
             dfs(x+1,step+1);
             forup(j,1,cnt)  vis[q[step][j]]=0;
           }
        }
    if(flag==0)  dfs(x+1,step+1);
    vis[x]=0;
}

int main()
{  
//freopen("angrybirds.in","r",stdin);
 //freopen("angrybirds.out","w",stdout);
   int T;cin>>T;
    while(T--)
    {      cin>>n>>m;ans=INF;
       forup(i,1,n)       {   scanf("%lf",&bird[i][0]);scanf("%lf",&bird[i][1]);}
       memset(vis,0,sizeof(vis));
      dfs(1,0);
     printf("%d\n",ans);
    }
    return 0;
}
