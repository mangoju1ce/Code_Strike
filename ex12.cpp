#include<iostream>  
#include<vector>
#define N 100005
using namespace std; 

int main(void){
    vector<int> road(N,0), dp(N,0); 
    int len; 
    cin>>len; 
    for(int i=1; i<=len; i++){
        cin>>road[i];
    }

    int last = 0, ans = 0; 
    for(int i = 1; i<=len; i++){
        if(road[i] > last){
            ans += road[i] - last;
        }
        last = road[i];
    }
    cout<<ans;

}