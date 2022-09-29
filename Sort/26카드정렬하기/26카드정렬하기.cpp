#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> v;

void sortV(int n,int idx);
void printVector();

int main(){
    int N;
    cin >> N;
    for(int i=0; i<N; i++){
        int num;
        cin >> num;
        v.push_back(num);
    }

    sort(v.begin(),v.end());

    int idx = 0;
    int answer = 0;
    while(idx<v.size()-1){
        int x1 = v[idx];
        int x2 = v[idx+1];
        idx+=2;
        int x3 = x1 + x2;
        answer += x3;
        sortV(x3,idx);
    }

    cout << answer << endl;

}
void printVector(){
    for(int i=0; i<v.size(); i++){
        cout << v[i] << " ";
    }
    cout  << endl;
}
void sortV(int n, int idx){
    bool insertv = false;
    for(int i=idx; i<v.size(); i++){
        if(v[i] >= n) {
            v.insert(v.begin()+i,n);
            insertv = true;
            break;
        }
    }
    if(insertv == false) v.push_back(n);
}