#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>
#include <stack>
#define endl '\n'
using namespace std;
string solution(string p) {
    if (p == "") {
        return "";
    }
    string u = "";
    string v = "";
    int count = 0;
    u += p[0];
    if (p[0] == '(') count++;
    if (p[0] == ')') count--;
    int index = 1;
    for (int i = 1; i < p.size(); i++) {
        // u 에 균형잡힌 괄호 문자열 넣기 (제일 작은)
        if (p[i] == '(') {
            count++;
        }
        if (p[i] == ')') {
            count--;
        }
        u += p[i];
        if (count == 0) {
            index = i + 1;
//            if (i == p.size() - 1) {
//                index = i + 1;
//            }
//            else {
//                index = i ;
//            }
            break;
        }

    }
    for (int i = index; i < p.size(); i++) {
        // v 에 남은 괄호 문자열 넣기 (얘도 균형잡힌 괄호 문자열이긴 할거야)
        v += p[i];
    }
    count = 0;
    bool correct_string = true;
    for (int i = 0; i < u.size(); i++) {
        // u 가 올바른 괄호 문자열인지 확인
        if (count < 0) {
            correct_string = false;
            break;
        }
        if (u[i] == '(') {
            count++;
        }
        if (u[i] == ')') {
            count--;
        }
    }
    string tmp = "";
    if (correct_string) {
        u += solution(v);
        tmp += u;
    }
    else {
        tmp += "(";
        tmp += solution(v);
        tmp += ")";
        for (int i = 1; i < u.size() - 1; i++) {
            if (u[i] == '(') {
                tmp += ")";
            }
            if (u[i] == ')') {
                tmp += "(";
            }
        }
    }

    return tmp;
}