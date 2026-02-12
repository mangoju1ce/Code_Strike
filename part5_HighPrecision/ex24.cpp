/*
    P2142 高精度减法

    注意：如何判定结果是否是负数，结果消除前导0
*/
#include <iostream>
#include <string>
#include <cstring>
#define MAX 10090

using namespace std;

char c[MAX];
int main(void) {
    string a, b;
    cin >> a >> b;
    
    int flg = 0;
    if(a.size() < b.size() || (a.size() == b.size() && a < b)) {
        swap(a,b);
        flg = 1;
    }

    int i = a.size()-1, j = b.size()-1, k = i, borrow = 0;
    while(i >= 0) {
        int x = a[i]-borrow, y = j >= 0 ? b[j] : '0';
        if(x < y) {
            x += 10;
            borrow = 1;
        } else borrow = 0;

        c[k--] = x-y+'0';
        i--; 
        j--;
    }

    int pos = 0;
    while (pos < a.size() - 1 && c[pos] == '0') pos++;

    if (flg) cout << '-';
    cout << (c + pos);
    return 0;
}