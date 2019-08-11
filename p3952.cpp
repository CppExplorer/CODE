#include<bits/stdc++.h>
using namespace std;
int t,i,j,l,p,top,pp,s[500],ppp;
char o[50],ch,v,s1[5],s2[5],a,b;
bool vis[26];
int main(){
    scanf("%d",&t);
    for (i=1;i<=t;++i){
        bool flag=0,f2=0; 
        p=0; top=0;
        memset(vis,0,sizeof vis);
        scanf("%d",&l);
        if (l%2==1) flag=1;
        scanf("%3s%c",o,&ch);
        if (ch=='^') scanf("%d%c",&pp,&v);
        for (j=1;j<=l;++j){
            scanf("\n%c",&ch);
            a='0'; b='0';
            if (ch=='F'){
                scanf(" %c %s %s",&v,s1,s2);
                if (top==0) f2=0,ppp=0;
                top++;
                s[top]=v-'a';
                if (vis[s[top]]) flag=1;
                vis[s[top]]=1;
                int l1=strlen(s1),l2=strlen(s2),an=0,bn=0;
                if (l1==1){
                    if (s1[0]=='n') a=s1[0],an=111;
                    else an=s1[0]-48;
                }
                else an=10*(s1[0]-48)+s1[1]-48;
                if (l2==1){
                    if (s2[0]=='n') b=s2[0],bn=111;
                    else bn=s2[0]-48;
                }
                else bn=10*(s2[0]-48)+s2[1]-48;
                if (an==bn) continue;
                if (a=='n' || an>bn) f2=1;
                if (b=='n' && !f2){
                    ppp++;
                    p=max(p,ppp);
                }
            }
            else{
                if (top<=0) flag=1;
                vis[s[top]]=0;
                top--; ppp--;
            }
        }
        if (top || flag){
            printf("ERR\n");
            continue;
        }
        if (o[2]=='n'){
            if (pp==p) printf("Yes\n");
            else printf("No\n");
        }
        if (o[2]=='1'){
            if (!p) printf("Yes\n");
            else printf("No\n");
        }
    }
    return 0;
}