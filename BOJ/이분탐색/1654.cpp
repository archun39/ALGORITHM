#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;

vector<long long int> lan;

pair<long long int,long long int> checkNum(long long int length){
    int cnt = 0;

    for(int i = 0; i < lan.size(); i++){
        int tmp = lan[i]/length;
        cnt += tmp;
    }
    pair<int,int> result = {cnt, length};
    return result;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int k, n;
    cin >> k >> n;

    for(int i = 0; i < k; i++){
        int tmp;
        cin >> tmp;
        lan.push_back(tmp);
    }

    sort(lan.begin(), lan.end());

    long long int left = 1;
    long long int right = lan[k-1]+1;
    long long int MAX = 0;
    long long int mid;
    while(left <= right){
        //cout << " / " << left << " : " << right << endl;
        mid = (left+right) / 2;
        
        pair<long long int,long long int> tmp = checkNum(mid);
        //cout << mid << " " << tmp.first << endl;
        //너무 크게 자른 경우 : 갯수 부족 
        if(tmp.first < n){
            
            right = mid - 1;
        }
        else{
            
            left = mid + 1;
            if(tmp.second > MAX){
                
                MAX = tmp.second;

                //cout << "MAX : " << MAX << endl;
            }
        }
    }

    cout << MAX << endl;

    return 0;
       
}