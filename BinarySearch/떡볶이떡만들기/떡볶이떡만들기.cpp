#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

int N,M;

int process(vector<int> v);
int slice(vector<int> v, int target);

int main(){
    cin >> N >> M ;

    vector<int> v;
    for(int i=0; i<N; i++){
        int num;
        cin >> num;
        v.push_back(num);
    }
    
    sort(v.begin(),v.end());

    int result = process(v);

    cout << result << endl;
    
}

int process(vector<int> v){
    int left = 0;
    int right = 1e9;
    int target;
    while(left<=right){
        target = (left+right)/2;
        if(slice(v,target) < M){
            right = target-1;
        }
        else {
            left = target+1;
        }
    }

    return target;
}

int slice(vector<int> v, int target){
    int total = 0;
    for(int i=0; i<N; i++){
        if(v[i] > target) total += v[i]-target;
    }
    return total;
}