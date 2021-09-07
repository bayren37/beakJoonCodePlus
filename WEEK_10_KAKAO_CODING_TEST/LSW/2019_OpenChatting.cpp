// 오픈채팅방

#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>

using namespace std;

vector<string> command;
unordered_map<string, string> uidNick;
vector<string> cur_uidNick;

vector<string> solution1(vector<string> record) {
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


// 참고 풀이
enum ActionType {
	NONE = 0,
	ENTER,
	LEAVE,
	CHANGE,
};

vector<string> split(string input, char delimiter) {
	vector<string> ret;
	stringstream ss(input);
	string tmp;

	while (getline(ss, tmp, delimiter))
		ret.push_back(tmp);
	
	return ret;
}

void ParseRecord(string record, ActionType& actionType, string& uid, string& nickName) {
	const vector<string>& parsed = split(record, ' ');

	if (parsed[0] == "Enter") {
		actionType = ENTER;
		uid = parsed[1];
		nickName = parsed[2];
	}
	else if (parsed[0] == "Leave") {
		actionType = LEAVE;
		uid = parsed[1];
	}
	else if (parsed[0] == "Change") {
		actionType = CHANGE;
		uid = parsed[1];
		nickName = parsed[2];
	}
}

vector<string> solution2(vector<string> record) {
	vector<string> result;

	unordered_map<string, string> idMap;
	vector<pair<string,ActionType>> record2;

	for (const string& record : record) {
		ActionType actionType = NONE;
		string uid, nickName;
		ParseRecord(record, actionType, uid, nickName);

		if (actionType == NONE)
			continue;

		switch (actionType)
		{
			case ENTER: {
				idMap[uid] = nickName;
				record2.push_back(make_pair(uid, ENTER));
			} break;
			case LEAVE: {
				record2.push_back(make_pair(uid, LEAVE));
			} break;
			case CHANGE: {
				idMap[uid] = nickName;
			} break;
		}
	}

	for (const pair<string, ActionType>& record : record2) {
		string	res = idMap[record.first] + "님이 ";
		res += (record.second == ENTER) ? "들어왔습니다." : "나갔습니다.";

		result.push_back(res);
	}

	return result;
}
