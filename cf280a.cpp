#include<bits/stdc++.h>
using namespace std;
int w,h,a;
double ang,ans;
const double pi=acos(-1);
int main(){
    scanf("%d%d%d",&w,&h,&a);
    if (w<h) swap(w,h);
    if (a>90) a=180-a;
    ang=a*pi/180.0;
    double tang=(double)h/w;
    tang=2*atan(tang);
    if (ang<tang){
        double ba=(pi-ang)/2;
        double xx=h/(2*tan(ba));
        double yy=w/(2*tan(ba));
        double x=(double)w/2-xx;
        double y=(double)h/2-yy;
        double s1=(tan(ang)*x*x)/2;
        double s2=(tan(ang)*y*y)/2;
        ans=(double)w*h-2*(s1+s2);
    }else{
        double l=h/sin(ang);
        ans=l*h;
    }
    printf("%.9lf",ans);
    return 0;
}