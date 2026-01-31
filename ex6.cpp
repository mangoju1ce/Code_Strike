#include<iostream>  
#include<vector>

using namespace std;

/* 
    luogu P3958 
    承接ex5 另一道用到并查集的题目  
    并查集在涉及“连通性检查”的时候是很有用的工具 因为图的连通性本质上是点集的划分，也就是集合  

    要注意数据溢出的问题 
        即使a,b 都是合法的int
        但 a + b, a-b 可能会溢出 要开longlong


*/


class DSU{
private:
    vector<int> fa, sz;

public:
    DSU(int n){
        fa.resize(n, 0);
        sz.resize(n, 1);
        for(int i=0; i<n; i++){
            fa[i] = i;
        }
    }

    int find(int x){
        if(fa[x] == x){return x;}
        else{
            return fa[x] = find(fa[x]);
        }
    }

    bool join(int x, int y){  // reserve node 0 for bottom , node 1 for top
        x = find(x); y = find(y);
        if(x == y){
            return false;
        }
        else{
            if(sz[x] < sz[y]){
                swap(x, y);
            }
            fa[y] = x;
            sz[x] += sz[y];
            return true;
        }
    }
};

struct Point{
    long long x, y, z;
};

long long sqr_dist(Point u, Point v){
    return (u.x - v.x)*(u.x - v.x) + (u.y - v.y)*(u.y - v.y) + (u.z - v.z)*(u.z - v.z);
}


int main(void){
    int query; 
    cin>>query;
    for(int q=0;q<query;q++){
        int n;
        long long h, r ;
        bool flag = false, ans = false;
        cin>>n>>h>>r; 
        vector<Point> holes(n+2); 
        DSU dsu(n+2); //+2 for bot and top
        for(int i=2;i<n+2;i++){
            cin>>holes[i].x>>holes[i].y>>holes[i].z; 
            if(flag){continue;} // top bot already reachable
            if(holes[i].z <= r){
                dsu.join(i, 0);
            }
            if(abs(holes[i].z-h)<=r){
                dsu.join(i,1);
            }
            for(int j=2; j<i; j++){
                if(sqr_dist(holes[j], holes[i]) <= 4LL * r * r){
                    dsu.join(j, i);
                }
            }
            if(dsu.find(0) == dsu.find(1)){
                flag = true; ans = true;        // found path to the top
            }
        }
        if(ans){cout<<"Yes\n";}
        else{cout<<"No\n";}
    }

}