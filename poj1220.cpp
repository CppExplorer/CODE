#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
char s1[1005];
int a[1005],b[1005],c[1005],d[5005],t,in,out;
int main(){
    scanf("%d",&t);
    while (t--){
        memset(a,0,sizeof a);
        memset(b,0,sizeof b);
        memset(c,0,sizeof c);
        memset(d,0,sizeof d);
        scanf("%d%d%s",&in,&out,s1);
        printf("%d %s\n",in,s1);
        int n=strlen(s1);
        for (int i=0;i<n;++i) a[n-i]=s1[i]-(s1[i]<58?48:s1[i]<91?55:61);
        a[0]=n; b[0]=1; b[1]=1;
        for (int i=1;i<=a[0];++i){
            for (int j=1;j<=b[0];++j) c[j]=a[i]*b[j];
            c[0]=b[0]+3;
            for (int j=1;j<=b[0]+3;++j){
                c[j+1]+=c[j]/10;
                c[j]%=10;
            }
            while (!c[c[0]] && c[0]>1) c[0]--;
            //for (int j=c[0];j;--j) printf("%d",c[j]);
            //printf("\n");
            n=max(d[0],c[0]);
            for (int j=1;j<=n;++j) d[j]+=c[j];
            d[0]=n+2;
            for (int j=1;j<=d[0];++j){
                d[j+1]+=d[j]/10;
                d[j]%=10;
            }
            while (!d[d[0]] && d[0]>1) d[0]--;
            //for (int j=d[0];j;--j) printf("%d",d[j]);
            //printf("\n");
            for (int j=1;j<=b[0];++j) b[j]*=in;
            b[0]+=3;
            for (int j=1;j<=b[0];++j){
                b[j+1]+=b[j]/10;
                b[j]%=10;
            }
            while (!b[b[0]] && b[0]>1) b[0]--;
            //for (int j=b[0];j;--j) printf("%d",b[j]);
            //printf("\n");
        }
        memset(b,0,sizeof b);
        memset(a,0,sizeof a);
        //for (int j=d[0];j;--j) printf("%d",d[j]);
        //printf("\n\n");
        int num=0; n=0; a[0]=d[0]; a[1]=1;
        while (a[0]>1 || a[1]!=0){
            for (int j=d[0];j;--j){
                num=num*10+d[j];
                a[j]=num/out;
                num%=out;
            }
            b[++b[0]]=num; num=0;
            while (!a[a[0]] && a[0]>1) a[0]--;
            for (int j=a[0];j>=0;--j) d[j]=a[j];
        }
        //for (int j=b[0];j;--j) printf("%d",b[j]);
        //printf("\n");
        printf("%d ",out);
        for (int j=b[0];j;--j) printf("%c",b[j]+(b[j]<10?48:b[j]<36?55:61));
        printf("\n\n");
    }
    return 0;
}