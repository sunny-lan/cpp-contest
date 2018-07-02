#include <stdio.h>
#include <math.h>
#include <iostream>
#define PI 3.14159265358979323846
using namespace std;
int main() {
    int t;
    cin>>t;
    for(int tst=1; tst<=t; ++tst) {
        double a;
        cin>>a;

        double l=0,h=PI/4;
        for(int i=0; i<40; ++i) {
            double mid=(l+h)/2;
            double area=sin(PI/2-mid)+cos(PI/2-mid);
            //printf("%.9f %.9f\n",mid/PI,area);
            if(area<a)
                l=mid;
            else
                h=mid;
        }

        double x=sin(l)/2,y=cos(l)/2;
        //printf("%.9lf %.9lf\n",l/PI,sin(PI/2-l)+cos(PI/2-l));

        printf("Case #%d:\n",tst);
        printf("0 0 0.5\n");
        printf("%.8f %.8f 0\n",-x,y);
        printf("%.8f %.8f 0\n",x,y);
    }
}
