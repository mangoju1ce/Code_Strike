/*
    P5707 【深基2.例12】上学迟到
*/
#include <iostream>

using namespace std;

int main(void) {
    int s, v;
    cin >> s >> v;

    int minute = s/v+10;
    if(s % v != 0) minute++;

    int h = 7-minute/60, m = 60-minute % 60;
    if(m == 60) {
        m = 0;
        h += 1;
    }
    if(h < 0) h += 24;

    if(h >= 10 && m >= 10) cout << h << ":" << m;
    if(h >= 10 && m < 10) cout << h << ":0" << m;
    if(h < 10 && m >= 10) cout << "0" << h << ":" << m;
    if(h < 10 && m < 10) cout << "0" << h << ":0" << m;
    return 0;
}