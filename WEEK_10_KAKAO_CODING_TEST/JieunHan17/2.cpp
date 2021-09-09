#include <string>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

vector<string> solution(vector<string> orders, vector<int> course)
{
    vector<string> answer;

    bool alphabet[26] = {
        false,
    };
    for (int i = 0; i < orders.size(); i++)
    {
        for (int j = 0; j < orders[i].length(); j++)
        {
            int index = orders[i][j] - 'A';
            if (!alphabet[index])
            {
                alphabet[index] = true;
            }
        }
    }

    vector<char> usedAlphabet;
    usedAlphabet.reserve(26);
    for (int i = 0; i < 26; i++)
    {
        if (alphabet[i])
        {
            usedAlphabet.push_back(i + 'A');
        }
    }

    for (int i = 0; i < course.size(); i++)
    {
        int numOfMenu = course[i];

        vector<int> temp;
        temp.reserve(26);
        for (int j = 0; j < numOfMenu; j++)
        {
            temp.push_back(0);
        }
        for (int j = 0; j < usedAlphabet.size() - numOfMenu; j++)
        {
            temp.push_back(1);
        }

        vector<pair<int, string> > v_result;
        int maximum = -1;
        do
        {
            string combination = "";
            for (int j = 0; j < temp.size(); j++)
            {
                if (temp[j] == 0)
                {
                    combination += usedAlphabet[j];
                }
            }

            int cnt = 0;
            for (int j = 0; j < orders.size(); j++)
            {
                int flag = 0;
                for (int k = 0; k < orders[j].length(); k++)
                {
                    for (int l = 0; l < combination.size(); l++)
                    {
                        if (orders[j][k] == combination[l])
                        {
                            flag++;
                        }
                    }
                }
                if (flag == combination.length())
                {
                    cnt++;
                }
            }

            if (cnt >= 2)
            {
                v_result.push_back(make_pair(cnt, combination));
                maximum = max(maximum, cnt);
            }
        } while (next_permutation(temp.begin(), temp.end()));

        for (int j = 0; j < v_result.size(); j++)
        {
            if (v_result[j].first == maximum)
            {
                answer.push_back(v_result[j].second);
            }
        }
    }

    sort(answer.begin(), answer.end());

    return answer;
}