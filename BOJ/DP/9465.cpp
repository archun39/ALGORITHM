#include <iostream>
#include <algorithm>
#define endl '\n'
using namespace std;
//실패
int n;
int map[2][100000];
int DP[2][100000];

void init(){
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 100000; j++){
            map[i][j] = 0;
        }
    }
}

void input(){
    cin >> n;
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < n; j++){
            cin >> map[i][j];
        }
    }
}
void printDP(){
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < n; j++){
            cout << DP[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
void process(){
    for(int j = 0; j < n-2; j++){
        for(int i = 0; i < 2; i++){
            if(i == 0){
                DP[i][j+2] = map[i][j] + max(DP[i][j+2],map[i][j+2]);
                DP[i+1][j+1] =  map[i][j] + max(DP[i+1][j+1],map[i+1][j+1]);
                DP[i+1][j+2] =  map[i][j] + max(DP[i+1][j+2],map[i+1][j+2]);
            }
            else {
                DP[i][j+2] =  map[i][j] + max(DP[i][j+2],map[i][j+2]);
                DP[i-1][j+1] = map[i][j] + max(DP[i-1][j+1],map[i-1][j+1]);
                DP[i-1][j+2] = map[i][j] + max(DP[i-1][j+2],map[i-1][j+2]);
            }
            printDP();
        }
    }
    
    
    if(DP[0][n-1] > DP[1][n-1]) cout << DP[0][n-1] << endl;
    else cout << DP[1][n-1] << endl;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        init();
        input();
        process();
    }
}