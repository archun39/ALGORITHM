#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string p);
string p;
int main(){

    cin >> p;
    cout << solution(p);

    return 0;
}
string solution(string p) {
    string answer = "";
    
    
    //"("
    int left = 0;
    //")"
    int right = 0;
    string u;
    string v;
    for(int i = 0;i<p.length();i++){
        if(p[i] == '(') left++;
        if(p[i] == ')') right++;
        if(left == right){
            u = p.substr(0,i+1);
            v = p.substr(i+1,p.length()-i);
            break;
        }
    }
    //u가 올바른 괄호 문자열인지 판별
    if (u[0] == '(') {
        if(v != "") v = solution(v);

        answer = u+v;
    }
    else {
        if(v!="") v = solution(v);
        v = "(" + v + ")";
        u = u.substr(1,u.length()-2);
        string tmp = "";
        for(int i= 0;i<u.length();i++){
            if(u[i] == '(') tmp += ")";
            if(u[i] == ')') tmp += "(";
        }
        
        answer = v+tmp;

    }
    
    return answer;
}
