#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;


bool searchPart(vector<int> ownerV, int target);


int main(){
    int N;
    cin >> N;
    vector<int> ownerV;
    vector<int> clientV;
    //부품받아오기
    for(int i=0; i<N; i++){
        int num;
        cin >> num;
        ownerV.push_back(num);
    }

    sort(ownerV.begin(),ownerV.end());

    int M;
    cin >> M;
    //요청 부품
    for(int i=0; i<M; i++){
        int num;
        cin >> num;
        bool found = searchPart(ownerV,num);
        if(found) cout << "yes" << " ";
        else cout << "no" << " ";
    }

    cout << endl;

    

}

bool searchPart(vector<int> ownerV, int target){
    int left = 0;
    int right = ownerV.size();
    int mid = ownerV.size()/2;
        while(left <= right) {
            if(ownerV[mid] == target){
                return true;
            }
            else if(ownerV[mid] > target){
                right = mid-1;
                mid = (right+left)/2;
                
            }
            else if(ownerV[mid] < target){
                left = mid+1;
                mid = (right+left)/2;
            }
        }

        return false;
}
