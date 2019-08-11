#include<cmath>
#include<cstdio>
using namespace std;
const double pi=3.1415926535898;
double R,r,n;
int main(){
    scanf("%lf%lf",&n,&r);
    double ang=180*(n-2)/(n*2);
    ang=ang*pi/180;
    double x=cos(ang);
    R=x*r/(1-x);
    printf("%.7lf",R);
    return 0;
}