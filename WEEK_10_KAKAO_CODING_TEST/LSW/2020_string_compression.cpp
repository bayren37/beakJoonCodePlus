// 문자열 압축

#include <string>
#include <iostream>

using namespace std;

string word;

int check(int size) {
    int count = 1;
    string answer = "";
    string tmp = word.substr(0, size);
    for (int i = size; i <= word.size(); i += size) {
        if (tmp == word.substr(i, size)) {
            count++;
        }
        else if (count == 1) {
            answer += tmp;
            tmp = word.substr(i, size);
        }
        else if (count >= 2) {
            answer += to_string(count) + tmp;
            count = 1;
            tmp = word.substr(i, size);
        }

        if (i + size > word.size()) {
            answer += count == 1 ? "" : to_string(count) + tmp;
            for (int j = i; j < word.size(); j++)
                answer += word[j];
            break;
        }

    }

    return answer.size();
}

int solution(string s) {
    int MIN;
    word = s;
    int size = word.size() / 2;
    
    size == 0 ? MIN = 1 : MIN = 1000;

    for (int i = 1; i <= size; i++) {
        MIN = min(MIN, check(i));
    }

    return MIN;
}
