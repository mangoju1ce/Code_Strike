#include <iostream>
#include <algorithm>
#define max 100005
using namespace std;

int a[max];
int main(void) {
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a, a+n);
    for(int i = 0; i < n-1; i++) {
        cout << a[i] << " ";
    }
    cout << a[n-1];
    return 0;
}