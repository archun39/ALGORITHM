#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    
    int idx = 1;
    int tmp = 0;
    while(true){
        tmp += idx;
        if(tmp >= n) break;
        idx++;
        
    }

    //몇번째에 있는지
    int k = n - (tmp - idx + 1) ;

    if(idx % 2 == 0){
        cout << 1 + k << "/" << idx - k << endl;
    }
    else {
        cout << idx - k << "/" << 1 + k << endl;
    }
    

}