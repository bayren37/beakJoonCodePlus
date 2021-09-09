#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> splitInfo(string s)
{
    vector<string> result;
    result.reserve(5);
    int startIdx = 0;
    int col = 0;
    int spaceIdx = s.find(" ");
    while (spaceIdx != string::npos)
    {
        result.push_back(s.substr(startIdx, spaceIdx - startIdx));
        startIdx = spaceIdx + 1;
        col++;
        spaceIdx = s.find(" ", startIdx);
    }
    result.push_back(s.substr(startIdx, s.length() - startIdx));
    return result;
}

vector<string> splitQuery(string s)
{
    vector<string> result;
    result.reserve(5);
    int startIdx = 0;
    int spaceIdx = s.find(" ");
    int flag = 0;
    while (spaceIdx != string::npos)
    {
        flag++;
        result.push_back(s.substr(startIdx, spaceIdx - startIdx));
        if (flag < 4)
        {
            startIdx = spaceIdx + 5;
        }
        else
        {
            startIdx = spaceIdx + 1;
        }

        spaceIdx = s.find(" ", startIdx);
    }
    result.push_back(s.substr(startIdx, s.length() - startIdx));
    return result;
}

vector<int> solution(vector<string> info, vector<string> query)
{
    vector<int> answer;
    vector<int> score[3][2][2][2];

    for (int idx = 0; idx < info.size(); idx++)
    {
        vector<string> applicants = splitInfo(info[idx]);

        int index[4];

        for (int i = 0; i < 4; i++)
        {
            if (applicants[i] == "cpp" || applicants[i] == "backend" || applicants[i] == "junior" || applicants[i] == "chicken")
            {
                index[i] = 0;
            }
            else if (applicants[i] == "python")
            {
                index[i] = 2;
            }
            else
            {
                index[i] = 1;
            }
        }
        score[index[0]][index[1]][index[2]][index[3]].push_back(stoi(applicants[4]));
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                for (int l = 0; l < 2; l++)
                {
                    sort(score[i][j][k][l].begin(), score[i][j][k][l].end());
                }
            }
        }
    }

    for (int idx = 0; idx < query.size(); idx++)
    {
        vector<string> eachQuery = splitQuery(query[idx]);

        int startIdx[4];
        int endIdx[4];

        for (int i = 0; i < 4; i++)
        {
            if (eachQuery[i] == "-")
            {
                startIdx[i] = 0;
                if (i == 0)
                {
                    endIdx[i] = 2;
                }
                else
                {
                    endIdx[i] = 1;
                }
            }
            else if (eachQuery[i] == "cpp" || eachQuery[i] == "backend" || eachQuery[i] == "junior" || eachQuery[i] == "chicken")
            {
                startIdx[i] = 0;
                endIdx[i] = 0;
            }
            else if (eachQuery[i] == "python")
            {
                startIdx[i] = 2;
                endIdx[i] = 2;
            }
            else
            {
                startIdx[i] = 1;
                endIdx[i] = 1;
            }
        }

        int cnt = 0;
        for (int i = startIdx[0]; i <= endIdx[0]; i++)
        {
            for (int j = startIdx[1]; j <= endIdx[1]; j++)
            {
                for (int k = startIdx[2]; k <= endIdx[2]; k++)
                {
                    for (int l = startIdx[3]; l <= endIdx[3]; l++)
                    {
                        if (score[i][j][k][l].size() == 0)
                        {
                            continue;
                        }
                        vector<int>::iterator iter = lower_bound(score[i][j][k][l].begin(), score[i][j][k][l].end(), stoi(eachQuery[4]));
                        if (iter == score[i][j][k][l].end())
                        {
                            continue;
                        }
                        cnt += score[i][j][k][l].size() - (iter - score[i][j][k][l].begin());
                    }
                }
            }
        }
        answer.push_back(cnt);
    }

    return answer;
}