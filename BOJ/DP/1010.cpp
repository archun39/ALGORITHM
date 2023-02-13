#include <iostream>
#include <algorithm>
#define endl '\n'
#define MAX 30 + 1
using namespace std;

int t;
int n,m;
int bridge[MAX][MAX];

void init(){
    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++){
            if(i == 1) bridge[i][j] = j;
            else if(j == 1) bridge[i][j] = i;
            else bridge[i][j] = 0;
        }
    }
}

int process(int n, int m){
    if(bridge[n][m] != 0) return bridge[n][m];
    //cout << n << " : " << m << endl;
    int answer = 0;
    int i = n - 1;
    for(int j = i; j < m; j++){
        answer += process(i,j);
    }
    
    bridge[n][m] = answer ;
    return answer;

}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> t;

    while(t--){

        init();
        cin >> n >> m;

        cout << process(n,m) << endl; 

    }
}