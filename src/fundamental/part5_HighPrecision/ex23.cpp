/*
    P1601 高精度加法
*/
#include <iostream>
#include <cstring>
#define MAX 505

using namespace std;

char a[MAX], b[MAX], c[MAX];
int main(void) {
    cin >> a >> b;

    int i = strlen(a)-1, j = strlen(b)-1, k = max(strlen(a), strlen(b)), carry = 0;
    c[k+1] = '\0';
    while(i >= 0 && j >= 0) {
        int sum = a[i]-'0'+b[j]-'0'+carry;
        carry = sum/10;
        c[k--] = sum%10 + '0';
        i--;
        j--;
    }
    while(i >= 0) {
        int sum = a[i]+carry-'0';
        carry = sum/10;
        c[k--] = sum%10 + '0';
        i--;
    }
    while(j >= 0) {
        int sum = b[j]+carry-'0';
        carry = sum/10;
        c[k--] = sum%10 + '0';
        j--;
    }
    c[k] = carry + '0';
    if(c[0] == '0') printf("%s", c+1);
    else printf("%s", c);
    return 0;
}