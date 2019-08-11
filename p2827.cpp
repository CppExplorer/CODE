#include<bits/stdc++.h>
using namespace std;
int n,m,q,delta,u,v,t,s[100005];
double p;
queue<int>a,b,c;

bool cmp(int x,int y){
    return x>y;
}

int main(){
    scanf("%d%d%d%d%d%d",&n,&m,&q,&u,&v,&t);
    p=(double)u/v;
    for (int i=1;i<=n;++i) scanf("%d",&s[i]);
    sort(s+1,s+1+n,cmp);
    for (int i=1;i<=n;++i) a.push(s[i]);
    for (int i=1;i<=m;++i){
        int xa=-INT_MAX,xb=-INT_MAX,xc=-INT_MAX,x;
        if (!a.empty()) xa=a.front();
        if (!b.empty()) xb=b.front();
        if (!c.empty()) xc=c.front();
        x=xa;
        bool flag=0;
        if (xb>=xc){
            if (xb>x) x=xb,b.pop();
                else a.pop(),flag=1;
        }else{
            if (xc>x) x=xc,c.pop();
                else if (!flag) a.pop();
        }
        x+=delta;
        //printf("%d %d %d %d\n",x,xa+delta,xb+delta,xc+delta);
        if (i%t==0) printf("%d ",x);    
        int y=(int)(p*x),z=x-y;
        delta+=q;
        b.push(y-delta); c.push(z-delta);
    }
    printf("\n");
    for (int i=1;i<=n+m;++i){
        int xa=-INT_MAX,xb=-INT_MAX,xc=-INT_MAX,x;
        if (!a.empty()) xa=a.front();
        if (!b.empty()) xb=b.front();
        if (!c.empty()) xc=c.front();
        x=xa;
        bool flag=0;
        if (xb>=xc){
            if (xb>x) x=xb,b.pop();
                else a.pop(),flag=1;
        }else{
            if (xc>x) x=xc,c.pop();
                else if (!flag) a.pop();
        }
        if (i%t==0) printf("%d ",x+delta);
    }
    return 0;
}