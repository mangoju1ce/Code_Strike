/*
    P1208 [USACO1.3] 混合牛奶 Mixing Milk
*/
#include <iostream>
#include <algorithm>
#define MAX 5005

using namespace std;

struct Node {
    int price;
    int num;
};
bool cmp(Node x, Node y) {
    return x.price < y.price;
}

Node nodes[MAX];
int main(void) {
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < m; i++) {
        cin >> nodes[i].price >> nodes[i].num;
    }

    sort(nodes, nodes+m, cmp);
    int ans = 0, i = 0;
    while(1) {
        if(n > nodes[i].num){
            ans += nodes[i].price * nodes[i].num;
            n -= nodes[i].num;
        } else {
            ans += nodes[i].price * n;
            break;
        }
        i++;
    }

    cout << ans;
    return 0;
}