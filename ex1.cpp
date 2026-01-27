#include<iostream>
#define MANA_COST 10
#define MANA_RCV 4
#define DIST_JUMP 60
#define DIST_RUN 17
using namespace std; 


/*  luogu P1095
    一个dp问题的变体。首先分析一下问题。

    由题可知，每个状态下可以选择三个行为：1.休息回蓝 2.闪烁 3.跑步 

    实际上可以归约成两个行为： 1.休息到蓝量足够，立即闪烁 2. 跑步

    接下来我犯了一个错误！！

    错误的思路是： 
        用dp数组记录每个时间可以到达的最大位移。 在每个时间点t， 在当前的*最大位移*处进行上述两个行动， 更新未来的最大位移。 然后t往后推移，直到时间用完或到达终点。
    
    错误的原因是：
        在时间点t+1到达最大位移时， 时间点t不一定处于t的最大位移。
        也就是说，不能单纯用贪心决策行动。

    错误样例：
        m = 0， s = 120， t = 8；
    正确的路线应该是：回蓝、闪烁、回蓝、闪烁，只需要7s 
    根据上述错误思路得到的路线是: 跑步到t = 4s， 此时再回蓝跳跃，需要8s到终点。
    贪心算法会错误决策的原因是， 只考虑前4s跑步的话， t=4时候位移x=68， 位移大于 回蓝+闪烁，t=4时x=60的方案。但是后者会给后续的跳跃攒下两点蓝量。在长线上拥有更好的表现。

    其实给足够的时间，行动1的速度快于行动2！ 但是短期内，行动2速度有可能更快。
    分析一下可以知道，最优解的模式可以归约成：
        进行n次行动1（回蓝闪烁）， 最后在蓝量不够，靠近终点时用m次跑步收尾 
    (因为跑步不影响蓝量,总是可以把最优解的跑步放到最后, 不影响给定时间下的最大位移)

    关键点在于低魔力下的决策,需要平衡跑步的短期收益和回蓝闪烁的长期收益， 要找到一个最佳的放弃闪烁，跑步冲刺到终点的timing。
    这时候的dp需要记录两个路线，一个是只采用行动1，到当前时间time的最大位移 记为 jump  
                              第二个是在最后一次闪烁之后，只采用行动2的最大位移 记为 run 
                              如果run < jump 说明当前run的路径太早放弃闪烁，应该从jump的路径开始放弃闪烁，跑步冲刺。下次更新run的时候在jump的基础上递增。

        


*/

int main(void){
    int m=0, s=0, t=0;
    cin>>m>>s>>t;
    /*
        time --> current time
        run --> maximum distance after giving up jumping
        jump --> maximum distance if always trying to jump 
    */
    int jump = 0, run = 0, time = 0;  


    for(; time < t; time ++){
        if(jump >= s || run >= s){  // arrived at time 
            cout<<"Yes\n"<<time;
            return 0;
        }
        if(jump > run){
            run = jump + DIST_RUN;  // run from last jump( reset the time of giving up jumping )
        }
        else{
            run += DIST_RUN;   // keep the original time of giving up jumping 
        }

        if(m >= MANA_COST){
            m -= MANA_COST;
            jump += DIST_JUMP;
        }
        else{
            m += MANA_RCV;
        }
    }
    if(jump >= s || run >= s){
        cout<<"Yes\n"<<t;
    }
    else{
        cout<<"No\n"<<max(run, jump);
    }
}