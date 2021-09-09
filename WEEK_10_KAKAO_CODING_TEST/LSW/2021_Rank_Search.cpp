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

#include <cstdio>
#include <map>
#include <algorithm>
//참고 풀이

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer(query.size(),0);
    map<string, vector<int>> arr;

    for (int i = 0; i < info.size(); i++) {
        string token;
        stringstream ss(info[i]);
        vector<vector<string>> str(4, vector<string>(2, "-"));

        int index = 0, score = 0;

        while (ss >> token) {
            if (index < 4)
                str[index++][0] = token;
            else
                score = stoi(token);
        }

        for (int i = 0; i < 2; i++) {
            string t1, t2, t3, t4;
            t1 = str[0][i];
            for (int j = 0; j < 2; j++) {
                t2 = str[1][j];
                for (int k = 0; k < 2; k++) {
                    t3 = str[2][k];
                    for (int l = 0; l < 2; l++) {
                        t4 = str[3][l];
                        arr[t1 + t2 + t3 + t4].push_back(score);
                    }
                }
            }
        }
    }

    for (auto itr = arr.begin(); itr != arr.end(); itr++) {
        sort(itr->second.begin(), itr->second.end());
    }
    
    for (int i = 0; i < query.size(); i++) {
        string str = "", token;
        stringstream ss(query[i]);
        int index = 0, score = 0;

        while (ss >> token) {
            if (token == "and")
                continue;

            if(index++ < 4)
                str += token;
            else
                score = stoi(token);
        }

        auto itr = lower_bound(arr[str].begin(), arr[str].end(), score);

        answer[i] = arr[str].size() - (itr - arr[str].begin());
    }

    return answer;
}

int main(void) {
    for (int i : solution({ "java backend junior pizza 150",
                           "python frontend senior chicken 210",
                           "python frontend senior chicken 150",
                           "cpp backend senior pizza 260",
                           "java backend junior chicken 80",
                           "python backend senior chicken 50" },
        { "java and backend and junior and pizza 100",
         "python and frontend and senior and chicken 200",
         "cpp and - and senior and pizza 250",
         "- and backend and senior and - 150",
         "- and - and - and chicken 100",
         "- and - and - and - 150" }))
        printf("%d ",i);
}
