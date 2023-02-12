#include <iostream>
#include <algorithm>
#include <vector>
#define endl '\n'
using namespace std;

int n, k;
vector<int> v;
vector<int> c(300000);

void input(){
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        int num;
        cin >> num;
        v.push_back(num);
    }
}

int process(){
    vector<int> tmp;
    for(int i = 1; i < n; i++){
        int num = v[i] - v[i-1];
        tmp.push_back(num);
    }
    sort(tmp.begin(),tmp.end());

    int answer = 0;
    for(int i = 0; i < n-k; i++){
        answer += tmp[i];
    }

    return answer;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    input();
    cout << process();

}