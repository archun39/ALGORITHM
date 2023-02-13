#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;

void input(){
    cin >> n;
}

int process(){

    //5
    int idxFive;
    for(int i = 1; i <= 1000; i++){
        int tmp = i * 5;
        if(tmp > n) {
            idxFive = i - 1;
            break;
        }
        else if(tmp == n) return i;
    }


    //3
    int idxThree = 0;
    while(idxFive >= 0){
        int sugar = n - (idxFive * 5);
        if(sugar % 3 == 0){
            idxThree = sugar / 3;
            return idxThree + idxFive;
        }
        idxFive -= 1;
    }

    return -1;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    input();
    cout << process();
}