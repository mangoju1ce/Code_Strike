#include<iostream>
#include<algorithm>

#define N 1000005
#define T 1000005

using namespace std; 


struct game{
    int start, end; 
    bool operator < (const game& other)const{
        return end < other.end; 
    }
};

int main(void){
    int n, dp[T];
    game list[N];

    cin>>n; 
    for(int i=0; i<n; i++){
        cin>>list[i].start>>list[i].end;
    }

    sort(list, list + n);

    dp[0] = 0; 
    int time = 0;
    for(int i = 0; i<n; i++){  //  traverse the list of games
        while(list[i].end > time){   // no game could be finish since last dp time
            dp[time+1] = dp[time];
            time++;
        }
        dp[time] = max(dp[time], dp[list[i].start] + 1);  //PS: actually if multiple games have same end time, only the one with latest start time is necessary 
    }

    cout<<dp[time];


}