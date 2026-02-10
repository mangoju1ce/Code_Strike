#include<iostream>  
#include<algorithm>

using namespace std;

#define N 1005
#define M 505

/*
luogu P2504 
    求能够连通一个点集的最小边长，使得所有边都小于等于这个长度  
    如果熟悉最小生成树性质的话 就知道 MST的最大边权是这个图所有生成树的最大边权中最小的  
    所以直接求最小生成树即可  
    
    这里我没有想到这一点 用了比较笨的办法， 用并查集逐个验证猴子的跳跃距离能否连通所有点 居然还是过了  

    后面需要复习一下最小生成树的prim,kruskal算法。 
*/

class dsu{
private:
    int fa[N], size[N], n;

public: 
    dsu(int x){
        n = x; 
        for(int i=0; i<n; i++){
            fa[i] = i; 
            size[i] = 1;
        }
    }

    int find(int x){
        if(fa[x] == x){return x;}
        else{
            return fa[x] = find(fa[x]);
        }
    }

    int join(int x, int y){
        x = find(x); y = find(y);  

        if(x == y){
            return size[x];
        }

        if(size[x] < size[y]){swap(x,y);}
        
        fa[y] = x;  

        size[x] += size[y];

        return size[x];
    }
};


int main(void){
    int monkey[M], x[N], y[N], m, n, ans = 0;
    cin>>m; 
    for(int i=0; i<m; i++){
        cin>>monkey[i];
    }
    cin>>n; 
    for(int i=0; i<n; i++){
        cin>>x[i]>>y[i];
    }

    sort(monkey, monkey+m, greater<int>());
    for(ans = 0; ans < m; ans++){
        dsu trees(n);
        int size = 1; 
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                if((x[i]-x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]) <= monkey[ans] * monkey[ans]){
                    size = trees.join(i, j);
                }
            }
        }
        if(size != n){
            break;
        }
    }

    cout<<ans<<endl;



}