#include<bits/stdc++.h>
using namespace std;
int n,l,g,w,h;
int main(){
    scanf("%d%d%d",&n,&l,&g);
    for (int i=1;i<=n;++i){
        scanf("%d%d",&w,&h);
        while (w>g || h>g) w>>=1,h>>=1;
        if (w<l || h<l) printf("Too Young\n");
        else{
            if (w!=h) printf("Too Simple\n");
            else printf("Sometimes Naive\n");
        }
    }
    return 0;
}