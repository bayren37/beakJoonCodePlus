#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;

int timeToSec(string time)
{
    int len = time.length();
    int result = 0;
    int startIdx = 0;
    for (int i = 0; i < len; i++)
    {
        if (time[i] == ':')
        {
            result += stoi(time.substr(startIdx, i - startIdx));
            result *= 60;
            startIdx = i + 1;
        }
    }
    result += stoi(time.substr(startIdx, len - startIdx));
    return result;
}

string secToTime(int sec)
{
    string result = "";
    int hour = sec / 3600;
    sec %= 3600;
    if (hour < 10)
    {
        result += '0';
        result += (hour + '0');
    }
    else
    {
        result += (hour / 10 + '0');
        result += (hour % 10 + '0');
    }
    result += ':';

    int min = sec / 60;
    sec %= 60;
    if (min < 10)
    {
        result += '0';
        result += (min + '0');
    }
    else
    {
        result += (min / 10 + '0');
        result += (min % 10 + '0');
    }
    result += ':';

    if (sec < 10)
    {
        result += '0';
        result += (sec + '0');
    }
    else
    {
        result += (sec / 10 + '0');
        result += (sec % 10 + '0');
    }

    return result;
}

string solution(string play_time, string adv_time, vector<string> logs)
{
    string answer = "";
    int play_time_sec = timeToSec(play_time);
    int adv_time_sec = timeToSec(adv_time);
    
    int numOfPlay[play_time_sec];
    fill(numOfPlay, numOfPlay + play_time_sec, 0);
    
    for (int i = 0; i < logs.size(); i++)
    {
        int start = timeToSec(logs[i].substr(0, 8));
        int end = timeToSec(logs[i].substr(9, 8));
        for (int j = start; j < end; j++)
        {
            numOfPlay[j]++;
        }
    }
    
    long long sum = 0;
    queue<long long> q;
    for (int i = 0; i < adv_time_sec; i++)
    {
        sum += numOfPlay[i];
        q.push(numOfPlay[i]);
    }
    
    long long maximum = sum;
    int answer_sec = 0;
    for (int i = adv_time_sec; i < play_time_sec; i++)
    {
        sum += numOfPlay[i];
        q.push(numOfPlay[i]);
        sum -= q.front();
        q.pop();
        if (sum > maximum)
        {
            maximum = sum;
            answer_sec = i - adv_time_sec + 1;
        }
    }
    
    answer = secToTime(answer_sec);
    return answer;
}