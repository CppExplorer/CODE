#include<bits/stdc++.h>
using namespace std;
int i;
char s[25],in[25],out[25],t[25],ti[25],to[25],t2[25];
int main(){
    scanf("%s",s);
    if (s[0]=='1' || s[0]=='0'){
        int n=s[0]-48,j,cnt=1,io,jo;
        bool f,f2;
        scanf("%s%s",in,out);
        int l=strlen(in),lo=strlen(out);
        for (i=0;i<l;++i) if (in[i]>='0' && in[i]<='9') break;
        for (j=0;j<l;++j) if (in[j]=='.') break;
        if (i<j){
            f=1;
            for (int k=0;k<i;++k) t[k]=in[k];
            for (int k=j,x=0;k<l;++k) ti[x++]=in[k];
        }else{
            f=0;
            for (int k=0;k<j;++k) t[k]=in[k];
            for (int k=j,x=0;k<i;++k) ti[x++]=in[k];
        }
        for (i=0;i<lo;++i) if (out[i]>='0' && out[i]<='9') break;
        for (j=0;j<lo;++j) if (out[j]=='.') break;
        if (i<j){
            f2=1;
            for (int k=0;k<i;++k) t2[k]=out[k];
            for (int k=j,x=0;k<lo;++k) to[x++]=out[k];
        }else{
            f2=0;
            for (int k=0;k<j;++k) t2[k]=out[k];
            for (int k=j,x=0;k<i;++k) to[x++]=out[k];
        }
        while (scanf("%s%s",in,out)!=EOF) cnt++;
        for (int k=1;k<=cnt;++k){
            if (f) printf("%s%d%s ",t,n,ti);
                else printf("%s%s%d ",t,ti,n);
            if (f2) printf("%s%d%s\n",t2,n,to);
                else printf("%s%s%d\n",t2,to,n);
            n++;
        }
    }else{
        scanf("%s",to);
        int l=strlen(s),j;
        for (i=0;i<l;++i) if (s[i]>='0' && s[i]<='9') break;
        for (j=0;j<l;++j) if (s[j]=='.') break;
        int k=i,n=0,cnt=0;
        while (s[k]>='0' && s[k]<='9'){
            n=n*10+s[k]-48;
            k++;
        }
        while (scanf("%s%s",in,out)!=EOF) cnt++;
        if (i<j){
            for (int k=0;k<i;++k) t[k]=s[k];
            for (int k=j,x=0;k<l;++k) ti[x++]=s[k];
            for (int k=1;k<=cnt;++k){
                printf("%s%d%s %s%d.%s\n",t,n,ti,t,n,to);
                n++;
            }
        }else{
            for (int k=0;k<j;++k) t[k]=s[k];
            for (int k=j,x=0;k<i;++k) ti[x++]=s[k];
            for (int k=1;k<=cnt;++k){
                printf("%s%s%d %s.%s%d\n",t,ti,n,t,to,n);
                n++;
            }
        }
    }
    return 0;
}