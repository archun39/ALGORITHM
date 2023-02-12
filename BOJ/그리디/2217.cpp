#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> rope;

bool cmp(int A, int B){
    return A > B;
}
void input(){
    cin >> n;
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        rope.push_back(num);
    }

    
}

int process(){
    int answer = 0;

    sort(rope.begin(), rope.end(), cmp);
    
    int maxValue = 0;
    for(int i = 0; i < n; i++){
        int r = rope[i]; // 현재 로프
        if(r * (i+1) > maxValue) {
            maxValue = r * (i+1);
        }
    }
    return maxValue;

}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    input();
    cout << process();
}