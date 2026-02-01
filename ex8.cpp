/*
    p1024 一元三次方程
    画图可知三根在[-100,x2],[x2,x1],[x1,100]之间
    其中x2，x1为导函数两根，且x2<x1
    对每个区间二分求解即可
*/
#include <iostream>
#include <cmath>
#define f(x) ((a*x*x*x) + (b*x*x) + (c*x) + d)
using namespace std;

void solve(double, double);
double a, b, c, d;
int main(void) {
    cin >> a >> b >> c >> d;
    double x1 = (-b+sqrt(b*b-3*a*c))/(3*a), x2 = (-b-sqrt(b*b-3*a*c))/(3*a);
    solve(-100.0, x2);
    solve(x2, x1);
    solve(x1, 100.0);
    return 0;
}

void solve(double x, double y){
    if(f(x) == 0){
        printf("%.2f", x);
    }
    if(f(y) == 0) {
        printf("%.2f", y);
    }
    double mid = (x+y)/2;
    if(y-x <= 0.01) {
        printf("%.2f ", mid);
        return;
    }

    if(f(mid)*f(x) < 0) solve(x, mid);
    if(f(mid)*f(y) < 0) solve(mid, y);
}