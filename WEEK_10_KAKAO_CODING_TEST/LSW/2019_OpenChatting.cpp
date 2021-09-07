// 오픈채팅방

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<string> command;
unordered_map<string, string> uidNick;
vector<string> cur_uidNick;

vector<string> solution(vector<string> record) {
	vector<string> result;

	string tmp = "", uid = "";
	int index;

	cur_uidNick = vector<string>(record.size());

	for (int i = 0; i < record.size(); i++) {
		index = 0;
		for (int j = 0; j <= record[i].size(); j++) {
			if (record[i][j] == ' ' || record[i][j] == '\0') {
				if (index == 0) {
					if(tmp != "Change")
						command.push_back(tmp);
				}
				else if (index == 1) {
					if (tmp != "Change")
						cur_uidNick[i] = tmp;
					if (tmp == "Leave") break;
					if (uidNick.find(tmp) == uidNick.end())
						uidNick.insert(make_pair(tmp, ""));
					uid = tmp;
				}
				else if (index == 2)
					uidNick[uid] = tmp;
				tmp = "";
				index++;
				continue;
			}
			tmp += record[i][j];
		}
	}

	for (int i = 0; i < command.size(); i++) {
		if (command[i] == "Enter") {
			result.push_back(uidNick[cur_uidNick[i]] + "님이 들어왔습니다.");
		}
		else if (command[i] == "Leave") {
			result.push_back(uidNick[cur_uidNick[i]] + "님이 나갔습니다.");
		}
	}

	return result;
}
