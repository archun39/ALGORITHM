#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

struct Student{
    string name;
    int kor;
    int eng;
    int math;

    bool operator < (const Student &rhs) const{
        if(this->kor == rhs.kor){
            if(this->eng == rhs.eng){
                if(this->math == rhs.math){
                    return this->name < rhs.name;
                }
                else{
                    return this->math > rhs.math;
                }
            }
            else{
                return this->eng < rhs.eng;
            }
        }
        else{
            return this->kor > rhs.kor;
        }
    }
};

int n;
vector<Student> v;

int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        Student s;
        cin >> s.name >> s.kor >> s.eng >> s.math;
        v.push_back(s);
    }

    sort(v.begin(), v.end());

    for(int i=0; i<n; i++){
        cout << v[i].name << '\n';
    }
}