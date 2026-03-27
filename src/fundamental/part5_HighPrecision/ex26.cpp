/*
    P1480 A/B Problem（高精度除法Ⅰ）
*/
#include <iostream>
#include <cstring>
#define MAX 5005

using namespace std;
char a[MAX];
int c[MAX];
int main(void) {
    long long b;
    cin >> a >> b;

    int size_c = 0;
    long long sum = 0;
    for(int i = 0; i < strlen(a); i++) {
        sum = sum*10 + a[i]-'0';
        c[size_c++] = sum/b;
        sum %= b;
    }

    int i = 0;
    while(i < size_c && c[i] == 0) i++;
    if(i == size_c) cout << 0;

    while(i < size_c) cout << c[i++];
    
    return 0;
}