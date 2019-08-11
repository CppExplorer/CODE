#include<bits/stdc++.h>
using namespace std;
const int N=10000000;
int n,m,a[N],b[N],l,cnt=1,c[N];
bool flag=0;

void print(){
    for (int i=1;i<l;++i){
        if (i==a[c[l]]){
            printf("("); cnt++;
            if (cnt==76) printf("\n"),cnt=0;
        }
        printf("%d",b[i]); cnt++;
        if (cnt==76) printf("\n"),cnt=0;
    }
    printf(")");
}

int main(){
    scanf("%d%d",&n,&m);
    printf("%d.",n/m);
    int k=n/m; if (k==0) cnt++;
    while (k){
        k/=10; cnt++;
    }
    int x=n%m; a[x]=l+1;
    while (1){
        c[++l]=x; x*=10; b[l]=x/m; x=x%m;
        if (x==0){
            for (int i=1;i<=l;++i){
                printf("%d",b[i]); cnt++;
                if (cnt==76) printf("\n");
            }
            return 0;
        }
        if (flag){
            print();
            return 0;
        }
        if (a[x]) flag=true;
            else a[x]=l+1;
    }
    return 0;
}