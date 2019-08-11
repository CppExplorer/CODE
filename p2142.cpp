#include<bits/stdc++.h>
using namespace std;
int a[100002],b[100002],c[100002],n,i;
char s1[100002],s2[100002];
int main(){
    scanf("%s%s",s1+1,s2+1);
    int l1=strlen(s1+1),l2=strlen(s2+1);
    if (l1<l2 || (l1==l2 && s1[1]<s2[1])){
        printf("-");
        n=l2; 
        reverse(s1+1,s1+1+l1);
        for (i=l2;i>=1;--i)
            a[i]=s2[i]-48;
        for (i=l1;i>=1;--i)
            b[l2-i+1]=s1[i]-48;
    }else{
        n=l1;
        reverse(s2+1,s2+1+l2);
        for (i=l1;i>=1;--i)
            a[i]=s1[i]-48;
        for (i=l2;i>=1;--i)
            b[l1-i+1]=s2[i]-48;
    }
    //for (i=1;i<=n;++i) printf("%d",a[i]);
    //printf("\n");
    //for (i=1;i<=n;++i) printf("%d",b[i]);
    //printf("\n");
    for (i=n;i>=1;--i){
        if (a[i]>=b[i]) c[i]=a[i]-b[i];
        else{
            int j=i-1;
            while (!a[j]) j--;
            a[j]--;
            for (int k=j+1;k<i;++k) a[k]+=9;
            //for (int j=1;j<=n;++j) printf("%d",a[j]);
            //printf("\n");
            c[i]=a[i]+10-b[i];
        }
    }
    for (i=1;i<=n;++i) if (c[i]) break;
    for (int j=i;j<=n;++j) printf("%d",c[j]);
    return 0;
}