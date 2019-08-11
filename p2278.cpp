#include<bits/stdc++.h>
using namespace std;
int n,i;
long long t;
struct heap{
    int no,st,lt,val; 
};
bool operator <(const heap &a,const heap &b){
    return a.val<b.val || (a.val==b.val && a.st>b.st);
}
heap x;
priority_queue<heap>h;
int main(){
    n=1;
    while (scanf("%d%d%d%d",&x.no,&x.st,&x.lt,&x.val)!=EOF){
        while (!h.empty() && t+h.top().lt<=x.st){
            heap y=h.top();
            h.pop();
            printf("%d %lld\n",y.no,t+y.lt);
            t+=y.lt;
        }
        if (!h.empty()){
            heap y=h.top();
            h.pop();
            y.lt=y.lt-x.st+t;
            h.push(y);
        }
        h.push(x);
        t=x.st;
    }
    while (!h.empty()){
        heap y=h.top();
        h.pop();
        t+=y.lt;
        printf("%d %lld\n",y.no,t);
    }
    return 0;
}