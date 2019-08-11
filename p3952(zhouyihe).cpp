#include<bits/stdc++.h>
using namespace std;
#define forup(i,a,b) for(int i=(a);i<=(b);i++)
#define fordown(i,a,b)  for(int i=(a);i>=(b);i--)
#define pb push_back
#define INF 1000000005
typedef long long  ll;
int n,m;
int T;
int vis[1005];
char s[10005];
char I[1005],X[1005],Y[1005];
int fuza;
void clearall()
{ forup(i,0,26)  vis[i]=0;
 // while(!p.empty()) p.pop();
  //while(!q.empty()) q.pop();
}
int  main()
{
 cin>>T;
 while(T--)
 {cin>>n;scanf("%s",s+1);
  int flag=1;
  int len=strlen(s+1);
  //bool is_O1=1;
  fuza=0;//观察复杂度 
  forup(i,1,len) if(s[i]=='^') 
  {i++;//is_O1=0;
   while(s[i]>='0'&&s[i]<='9') {fuza=fuza*10+s[i]-'0';i++;}
   break;
  }
   stack<int> q;
   stack<int> p;
   int cheng0=0;
   stack<int> cheng;
   int cmax=0;int step=0; 
   int shiji=0;
   forup(i,1,n)
   {scanf("%s",s+1);//观察是什么语句 
     if(s[1]=='F')
    {step++;scanf("%s",I+1);//观察循环变量的名词 
     vis[I[1]-'a']++;
     if(vis[I[1]-'a']>1) flag=0;
     q.push(I[1]-'a');
	 scanf("%s",X+1);//观察第一个循环参数 
      int x=INF; 
	  if(X[1]>='0'&&X[1]<='9')
	  {int k=1;x=0; while(X[k]>='0'&&X[k]<='9') {x=x*10+X[k]-'0';k++;}
	  }
	  int y=INF;
	  scanf("%s",Y+1);//观察第2个循环参数 
     if(Y[1]>='0'&&Y[1]<='9')
	  {y=0;int k=1; while(Y[k]>='0'&&Y[k]<='9') {y=y*10+Y[k]-'0';k++;} 
	  }
     if(y==INF&&x!=INF)//说明增加循环层次 
     {if(cheng0==0) shiji++;
	  cmax=max(cmax,shiji);
	  p.push(1);cheng.push(0);
	 }
	 else if(x>y)//说明根本不进入这里面 
	  {p.push(0);cheng0++;cheng.push(1);}
	 else 
	 {p.push(0);cheng.push(0); }
   }
    else//弹出一层循环 
     {if(!q.empty())
      {int  tmp=q.top(); q.pop();
       vis[tmp]--;
       step--;
	   if(cheng0==0) shiji=shiji-p.top(); 
	   p.pop();
	   cheng0=cheng0-cheng.top();cheng.pop();
	  }
	  else flag=0;
	 }
    }
   if(flag==0||step!=0) {printf("ERR\n");}
   else if(fuza==cmax) printf("Yes\n");
   else       printf("No\n");
   clearall();
 }	
return 0;	
}

