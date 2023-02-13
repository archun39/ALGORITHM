#include <iostream>
#include <algorithm>
#include <vector>

#define endl '\n'
using namespace std;

int main(){

    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    //n 짝수
    int n, h;
    cin >> n >> h;
    
    //높이 / 길이
    
    vector<int> top(h+1, 0);
    vector<int> bottom(h+1, 0);
    vector<int> result(h+1, 0);

    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        if(i%2 == 0) bottom[num]++;
        else top[num]++;
    }

    int minV = 1e9;
    int minC = 1;

    for(int i = h-1; i >=1; i--){
        bottom[i] += bottom[i+1];
    }
   
    for(int i = h-1; i >= 1; i--){
        top[i] += top[i+1];
    }
    
    for(int i = 1; i <= h; i++){

        result[i] = top[h-i+1] + bottom[i];
        if(minV > result[i]){
            minC = 1;
            minV = result[i];
        }
        else if(minV == result[i]) minC++;
    }
    
    cout << minV << " " << minC << endl;
}

//이분탐색 + 누적합