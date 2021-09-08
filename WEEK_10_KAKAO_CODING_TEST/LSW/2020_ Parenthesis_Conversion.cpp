#include <string>
#include <vector>
#include <iostream>

using namespace std;

string isReverse(string p);
string split(string p);

string isReverse(string p) {
    string tmp = p.substr(1, p.size() - 2);
    for (int i = 0; i < tmp.size(); i++) {
        if (tmp[i] == '(')
            tmp[i] = ')';
        else if (tmp[i] == ')')
            tmp[i] = '(';
    }

    
    return tmp;
}

string split(string p) {
    if (p.empty()) return p;

    int count_f = 0, count_r = 0;

    int count = 0;

    string answer;

    bool isForward;

    for (int i = 0; i < p.size(); i++) {
        if (p[i] == '(') {
            count++;
        }
        else {
            count--;
        }


        if (count == 0 && isForward) {
            answer += p.substr(0, i + 1);
            answer += split(p.substr(i + 1));
            return answer;
        }
        else if (count == 0 && !isForward) {
            answer += "(" + split(p.substr(i + 1)) + ")";
            answer += isReverse(p.substr(0, i + 1));
            return answer;
        }

        if (count < 0)
            isForward = false;
        else
            isForward = true;
    }
}

string solution(string p) {
    return split(p);
}

int main(void) {
    vector<string> p = { "(()())()" ,"))()((" ,"()))((()" };

    for (string i : p) {
        cout << solution(i) << '\n';
    }
}
