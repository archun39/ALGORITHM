#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
#define MAX 501
using namespace std;

int map[MAX][MAX];

int dp(int n){

    for(int i = n-2; i >=0 ; i--){
        for(int j = 0; j <= i; j++){
            map[i][j] = map[i][j] + max({map[i+1][j],map[i+1][j+1]});
        }
    }

    return map[0][0];
}

int main(){

    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        for(int j = 0; j <= i; j++){
            int num;
            cin >> num;
            map[i][j] = num;
        }
    } 

    int answer = dp(n);

    cout << answer << endl;
}
