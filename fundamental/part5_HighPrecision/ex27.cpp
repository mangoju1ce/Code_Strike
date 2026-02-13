/*
    P1009 [NOIP 1998 普及组] 阶乘之和
*/
#include <iostream>
#include <cstdlib>
#include <cstring>
#define MAX 100

using namespace std;

int fact[MAX], ans[MAX];
int main(void) {
    int n;
    cin >> n;

    fact[0] = 1;
    ans[0] = 0;
    int size_fact = 1, size_ans = 1;
    for(int i = 1; i <= n; i++) {
        // fac *= i
        int carry = 0;
        for(int j = 0; j < size_fact; j++) {
            fact[j] = fact[j]*i + carry;
            carry = fact[j]/10;
            fact[j] %= 10;
        }
        while(carry) {
            fact[size_fact++] = carry%10;
            carry /= 10;
        }

        // ans += fac
        int j = 0;
        carry = 0;
        while(j < size_fact) {
            int x = fact[j];
            int y = (j<size_ans) ? ans[j] : 0;
            
            ans[j] = (x+y+carry)%10;
            carry = (x+y+carry)/10;
            j++;
        }
        size_ans = size_fact;
        while(carry) {
            ans[size_ans++] = carry;
        }
    }

    for(int i = size_ans-1; i >= 0; i--) cout << ans[i];
    return 0;
}