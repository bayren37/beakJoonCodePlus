#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;

    vector<vector<string>> infoTable, queryTable;
    vector<string> arr;

    for (int i = 0; i < info.size(); i++) {
        stringstream ss(info[i]);
        string tmp;
        while (getline(ss, tmp, ' ')) 
            arr.push_back(tmp);
        infoTable.push_back(arr);
        arr.clear();
    }

    for (int i = 0; i < query.size(); i++) {
        stringstream ss(query[i]);
        string tmp;
        while (getline(ss, tmp, ' ')) {
            if(tmp != "and")
                arr.push_back(tmp);
        }
        queryTable.push_back(arr);
        arr.clear();
    }

    int count, correct;

    for (int i = 0; i < queryTable.size(); i++) {
        count = 0;
        for (int k = 0; k < infoTable.size(); k++) {
            correct = 0;
            for (int j = 0; j < 4; j++) {
                if (infoTable[k][j] == queryTable[i][j] || queryTable[i][j] == "-")
                    correct++;
            }
            if (stoi(infoTable[k][4]) >= stoi(queryTable[i][4])) {
                correct++;
            }
            if (correct == 5)
                count++;
        }
        answer.push_back(count);
    }


    return answer;
}
