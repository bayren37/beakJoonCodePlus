#include <string>
#include <vector>

using namespace std;

string first(string new_id)
{
    string result = "";
    int size = new_id.size();
    for (int i = 0; i < size; i++)
    {
        if ('A' <= new_id[i] && new_id[i] <= 'Z')
        {
            result += new_id[i] + ('a' - 'A');
        }
        else
        {
            result += new_id[i];
        }
    }
    return result;
}

string second(string new_id)
{
    string result = "";
    int size = new_id.size();
    for (int i = 0; i < size; i++)
    {
        if ('a' <= new_id[i] && new_id[i] <= 'z' || '0' <= new_id[i] && new_id[i] <= '9' || new_id[i] == '-' || new_id[i] == '_' || new_id[i] == '.')
        {
            result += new_id[i];
        }
        else
        {
            continue;
        }
    }
    return result;
}

string third(string new_id)
{
    string result = "";
    int size = new_id.size();
    for (int i = 0; i < size; i++)
    {
        if (i != size - 1)
        {
            if (new_id[i] == '.' && new_id[i + 1] == '.')
            {
                continue;
            }
            else
            {
                result += new_id[i];
            }
        }
        else
        {
            result += new_id[i];
        }
    }
    return result;
}

string fourth(string new_id)
{
    string result = "";
    int size = new_id.size();
    for (int i = 0; i < size; i++)
    {
        if (i == 0 && new_id[i] == '.' || i == size - 1 && new_id[i] == '.')
        {
            continue;
        }
        else
        {
            result += new_id[i];
        }
    }
    return result;
}

string fifth(string new_id)
{
    string result = "";
    int size = new_id.size();
    if (size == 0)
    {
        result += 'a';
        return result;
    }
    else
    {
        return new_id;
    }
}

string sixth(string new_id)
{
    string result = "";
    int size = new_id.size();
    if (size >= 16)
    {
        for (int i = 0; i < 15; i++)
        {
            if (i == 14 && new_id[i] == '.')
            {
                continue;
            }
            result += new_id[i];
        }
        return result;
    }
    else
    {
        return new_id;
    }
}

string seventh(string new_id)
{
    string result = "";
    int size = new_id.size();
    if (size <= 2)
    {
        for (int i = 0; i < size; i++)
        {
            result += new_id[i];
        }
        for (int i = 0; i < 3 - size; i++)
        {
            result += new_id[size - 1];
        }
        return result;
    }
    else
    {
        return new_id;
    }
}

string solution(string new_id)
{
    string answer = "";
    new_id = first(new_id);
    new_id = second(new_id);
    new_id = third(new_id);
    new_id = fourth(new_id);
    new_id = fifth(new_id);
    new_id = sixth(new_id);
    new_id = seventh(new_id);
    answer = new_id;
    return answer;
}