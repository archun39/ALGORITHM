#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;

int n;
vector<int> numbers;
int add,sub,mul,divi;
int idx = 1;
int maximum = -1e9;
int minimum = 1e9;

void dfs(int idx,int now);


int main(){
    cin >> n;
    for(int idx = 0; idx<n; idx++){
        int x;
        cin >> x;
        numbers.push_back(x);
    }
    cin >> add >> sub >> mul >> divi;
    dfs(idx,numbers[0]);
    cout << maximum << endl;
    cout << minimum << endl;

}

void dfs(int idx,int now){
    if(idx == n) {
        if(now > maximum) maximum = now;
        if(now < minimum) minimum = now;
    }
    else {
          if (add > 0) {
            add -= 1;
            dfs(idx + 1, now + numbers[idx]);
            add += 1;
        }
        if (sub > 0) {
            sub -= 1;
            dfs(idx + 1, now - numbers[idx]);
            sub += 1;
        }
        if (mul > 0) {
            mul -= 1;
            dfs(idx + 1, now * numbers[idx]);
            mul += 1;
        }
        if (divi > 0) {
            divi -= 1;
            dfs(idx + 1, now / numbers[idx]);
            divi += 1;
        }
    }


}