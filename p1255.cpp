#include<bits/stdc++.h>
using namespace std;
int a[5001],b[5001],c[5001],t[5001],n;

void add(){
    int l=max(a[0],b[0]);
        c[0]=a[0]+b[0];
        for (int j=1;j<=l;++j) c[j]=a[j]+b[j];
        for (int j=1;j<=c[0];++j){
            c[j+1]+=c[j]/10;
            c[j]%=10;
        }
        while (!c[c[0]] && c[0]>1) c[0]--;
}

int main(){
    scanf("%d",&n);
    if (n<3){
        if (!n) printf("0");
        if (n==1) printf("1");
        if (n==2) printf("2");
        return 0;
    }
    a[0]=1; a[1]=1;
    b[0]=1; b[1]=2;
    add();
    for (int i=4;i<=n;++i){
        for (int j=b[0];j>=0;--j) t[j]=b[j];
        for (int j=c[0];j>=0;--j) b[j]=c[j];
        for (int j=t[0];j>=0;--j) a[j]=t[j];
        add();
    }
    for (int i=c[0];i;--i) printf("%d",c[i]);
    return 0;
}