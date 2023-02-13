#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;

int n;
vector <int> v;

void input(){
    cin >> n;

    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        v.push_back(num);
    }
}

void middle(){

    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;
    
    left.push(v[0]);

    cout << v[0] << endl;

    for(int i = 1; i < n; i++){
        int num = v[i];

        if(i % 2 != 0){
            right.push(num);
        }
        else {
            left.push(num);
        }

        if(left.top() > right.top()){
            right.push(left.top());
            left.pop();
            left.push(right.top());
            right.pop();
        }

        cout << left.top() << endl;
    
    }
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    input();
    middle();
}