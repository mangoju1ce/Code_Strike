/*
    p1010 幂次方
*/
#include <iostream>
#include <cmath>
using namespace std;

void solve(int x) {
    bool first = true;
    while(x) {
        int t = (int)log2(x);

        //不是第一个，先输出+
        if(!first) cout << "+";
        if(t == 0) cout << "2(0)";
        else if(t == 1) cout << "2";
        else {
            cout << "2(";
            solve(t);
            cout << ")";
        }

        x -= (int)pow(2, t);
        first = false;
    }
}

int main(void) {
    int n;
    cin >> n;
    solve(n);
    return 0;
}