/*
    P3612 [USACO17JAN] Secret Cow Code S
    先扩充到相应的大小，然后简单分治成前后两部分更新答案即可
*/
#include <iostream>
#include <string>
using namespace std;

string s;
int main(void) {
    long long N;
    cin >> s >> N;

    long long current_size = s.size();
    while(current_size < N) {
        current_size *= 2;
    }

    long long ans = N;
    while(ans > s.size()){
        if(ans > current_size/2){
            if(ans == current_size/2+1) ans = current_size/2;
            else ans = ans - current_size/2 -1;
        } 
        current_size /= 2;
    }

    cout << s[ans-1];
    return 0;
}