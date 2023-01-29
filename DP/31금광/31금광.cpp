#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 22
using namespace std;

int map[MAX][MAX];

void reset(){
    for(int i = 1; i <= MAX; i++){
        for(int j = 1; j <= MAX; j++){
            map[i][j] = 0;
        }
    }
}

int process(int n, int m){

    for(int col = 2; col <= m; col++){
        for(int row = 1; row <= n; row++){
            
            int t = row - 1 >= 1 ? map[row - 1][col-1] : 0;
            int m = map[row][col-1];
            int b = row + 1 <= n ? map[row + 1][col-1] : 0;

            map[row][col] = map[row][col] + max({t,m,b});
            
        }
    }
    
    int answer = 0;

    for(int i = 1; i <= n; i++){
        answer = max(answer , map[i][m]);
    }

    return answer;
}

int main(){

    int tc;
    cin >> tc;

    while(tc--){

        int n, m;
        cin >> n >> m;

        reset();

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                cin >> map[i][j];
            }
        }

        cout << process(n,m) << endl;

    }
}
