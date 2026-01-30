/*
    p1051, 简单判断
*/
#include <iostream>
#include <string>
using namespace std;

int main(void) {
    int n;
    cin >> n;

    string theGuy;
    int personalHigh = 0, total = 0;
    for(int i = 0; i < n; i++){
        string name, isCadre, isWest;
        int finalScore, evalutionScore, paperNum;
        cin >> name >> finalScore >> evalutionScore >> isCadre >> isWest >> paperNum;

        int personalPrize = 0, personalPrizeNum = 0;
        if(finalScore > 80 && paperNum >= 1) {
            personalPrize += 8000;
            personalPrizeNum += 1;
            total += 8000;
        }
        if(finalScore > 85 && evalutionScore > 80){
            personalPrize += 4000;
            personalPrizeNum += 1;
            total += 4000;
        }
        if(finalScore > 90) {
            personalPrize += 2000;
            personalPrizeNum += 1;
            total += 2000;
        }
        if(finalScore > 85 && isWest == "Y") {
            personalPrize += 1000;
            personalPrizeNum += 1;
            total += 1000;
        }
        if(evalutionScore > 80 && isCadre == "Y") {
            personalPrize += 850;
            personalPrizeNum += 1;
            total += 850;
        }

        if(personalPrize > personalHigh) {
            personalHigh = personalPrize;
            theGuy = name;
        }
    }

    cout << theGuy << endl << personalHigh << endl << total;
    return 0;
}