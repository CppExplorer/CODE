#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
int top1,m,top2,num,cntn,cnts;
char s[105],ch[105],st2[105];
double x,st1[105],a[105];

int ord(char ch){
    if (ch=='(' || ch==')') return 0;
    if (ch=='+' || ch=='-') return 1;
    if (ch=='*' || ch=='/') return 2;
    if (ch=='^') return 3;
    return -1;
}

int main(){
    gets(s+1);
    int n=strlen(s+1);
    for (int i=1;i<=n;){
        double x=0; bool flag=0;
        if (s[i]=='.') flag=1,i++;
        int j=i;
        if (s[i]>='0' && s[i]<='9'){
            for (;s[i]>='0' && s[i]<='9';++i) x=x*10+(s[i]^48);
            if (!flag) a[++num]=x;
                else a[num]+=x/pow(10,i-j);
        }
        if ((s[i]<'0' || s[i]>'9') && s[i]!='.') ch[++m]=s[i++];
    }//读入OK
    // for (int i=1;i<=num;++i) printf("%.2lf ",a[i]); printf("\n");
    // for (int i=1;i<=m;++i) printf("%c ",ch[i]); printf("\n");
    ch[++m]='|';
    int i=1,j=1;
    while (i<=num || j<=m){
        if (ch[j]=='('){
            st2[++top2]='('; j++;
            continue;
        }
        if (cntn<=cnts) st1[++top1]=a[i++],cntn++;
        // printf("%.3lf %c %d %d\n",st1[top1],ch[j],cntn,cnts);
        bool flag=0;
        while (ord(ch[j])<=ord(st2[top2]) && top2){
            // printf("%c %c ",ch[j],st2[top2]);
            switch (st2[top2]){
            case '^':
                st1[top1-1]=pow(st1[top1-1],st1[top1]); top1--;
                break;
            case '*':
                st1[top1-1]=st1[top1-1]*st1[top1]; top1--;
                break;
            case '/':
                st1[top1-1]=st1[top1-1]/st1[top1]; top1--;
                break;
            case '+':
                st1[top1-1]=st1[top1-1]+st1[top1]; top1--;
                break;
            case '-':
                st1[top1-1]=st1[top1-1]-st1[top1]; top1--;
                break;
            case '(':
                if (ch[j]==')') flag=1;
                break;
            }
            // printf("%.3lf\n",st1[top1]);
            top2--; if (flag) break;
        }
        if (ch[j]!=')') st2[++top2]=ch[j],cnts++; j++;
    }
    printf("%.3lf",st1[1]);
    return 0;
}