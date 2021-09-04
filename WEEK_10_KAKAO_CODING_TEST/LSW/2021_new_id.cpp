// 신규 아이디 추천

#include <cstring>
#include <iostream>

using namespace std;


string step_1(string answer) {
	string tmp="";
	for (int i = 0; i < answer.size(); i++) {
		if (answer[i] == '-' || answer[i] == '_' || answer[i] == '.' || isalnum(answer[i])) {
			if (isupper(answer[i]))
				tmp += tolower(answer[i]);
			else
				tmp += answer[i];
		}
	}
	answer = tmp;
	return answer;
}

string step_2(string answer) {
	string tmp = "";
	for (int i = 0; i < answer.size()-1; i++) {
		if (!(answer[i] == '.' && answer[i + 1] == '.'))
			tmp += answer[i];
	}
	if (*answer.rbegin() != '.') tmp += *answer.rbegin();

	answer = tmp;
	return answer;
}

string step_3(string answer) {
	string tmp = "";
	if (answer.empty()) return tmp;
	answer[0] == '.' ?
		tmp += answer.substr(1, answer.size() - 2) :
		tmp += answer.substr(0, answer.size() - 1);
	if (*answer.rbegin() != '.') tmp += *answer.rbegin();

	answer = tmp;
	return answer;
}

string step_4(string answer) {
	if (answer.size() >= 16) {
		answer = answer.substr(0, 15);
		if (*answer.rbegin() == '.')
			answer.resize(14);
	}
	else if (answer.size() <= 2) {
		if (answer.empty()) answer = 'a';
		char tmp = *answer.rbegin();
		while (answer.size() != 3) {
			answer += tmp;
		}
	}
	return answer;
}

string solution(string new_id) {
	return step_4(step_3(step_2(step_1(new_id))));
}
