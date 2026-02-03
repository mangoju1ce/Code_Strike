/*
    p1226 快速幂
    方法一：a^b将b写成二进制，每次a自平方，b自除2
    方法二：若b是偶数，a^(b/2) * a^(b/2)，若b是奇数，a^(b/2) * a^(b/2) * a
*/
#include <iostream>

using namespace std;

long long quickPower_modp(int , int);
int a, b, p;
int main(void) {
    cin >> a >> b >> p;
    cout << a << "^" << b << " mod " << p << "=" << quickPower_modp(a, b);
    return 0;
}

/*
long long quickPower_modp(int a, int b) {
    long long base = a, ans = 1;
    while(b){
        if(b%2){
            ans = (ans*base)%p;
        }
        b /= 2;
        base = (base*base)%p;
    }
    return ans%p;
}
    */
long long quickPower_modp(int a, int b) {
    if(b == 0) return 1;
    long long t = quickPower_modp(a, b/2);
    if(b%2) return (t*t) % p * a % p;
    else return (t*t) % p;
}