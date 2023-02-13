#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
typedef long long ll;
using namespace std;

int n,m;
vector<int> A;
vector<int> ans;


void input(){
    cin >> n;
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        A.push_back(num);
    }

    sort(A.begin(), A.end());

    cin >> m;
    for(int i = 0; i < m; i++){
        int num;
        cin >> num;
        ans.push_back(num);
    }
}

bool findNum(int num){
    int left = 0;
    int right = n-1;
    int mid;
    while(left <= right){
        mid = (left + right) / 2;
        
        if(A[mid] == num) return true;
        else if(A[mid] < num){
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }

    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    input();
    for(int i = 0; i < m; i++){
        cout << findNum(ans[i]) << endl;
    }
}