/*
    P1303 A*B Problem

    先不管进位，对于结果数组c的元素c[i+j-1]，考虑如何得到，再最后进行进位的处理
*/
#include <iostream>
#include <cstring>
#define MAX 2005

using namespace std;
char s1[MAX], s2[MAX];
int a[MAX], b[MAX], c[MAX+MAX];
int main(void) {
    cin >> s1 >> s2;
    
    for(int i = 1; i <= strlen(s1); i++) a[i] = s1[strlen(s1)-i]-'0';
    for(int i = 1; i <= strlen(s2); i++) b[i] = s2[strlen(s2)-i]-'0';

    for(int i = 1; i <= strlen(s1); i++) {
        for(int j = 1; j <= strlen(s2); j++) {
            c[i+j-1] += a[i]*b[j];
        }
    }

    for(int i = 1; i <= strlen(s1)+strlen(s2)-1; i++) {
        c[i+1] += c[i]/10;
        c[i] = c[i]%10;
    }

    int i = strlen(s1)+strlen(s2);
    while(c[i] == 0) i--;
    while(i >= 1) cout << c[i--];
    return 0;
}