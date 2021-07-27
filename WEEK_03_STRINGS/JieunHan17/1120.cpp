#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int check(string A, string B)
{
    int len = B.length();
    int cnt = 0;
    for (int i = 0; i < len; i++)
    {
        if (A[i] != B[i])
        {
            cnt++;
        }
    }
    return cnt;
}

string putLetter(string A, string B, int num, bool isFront)
{
    if (isFront)
    {
        for (int i = num - 1; i >= 0; i--)
        {
            A = B[i] + A;
        }
    }
    else
    {
        int len = B.length();
        for (int i = num - 1; i >= 0; i--)
        {
            A += B[len - 1 - i];
        }
    }

    return A;
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string A, B;
    cin >> A >> B;

    int lenA = A.length();
    int lenB = B.length();
    int diff = lenB - lenA;

    int min = 51;
    for (int i = 0; i <= diff; i++)
    {
        string newA;
        newA = putLetter(A, B, i, true);
        newA = putLetter(newA, B, diff - i, false);
        int result = check(newA, B);
        if (result < min)
        {
            min = result;
        }
    }
    printf("%d", min);
    return 0;
}

/*
//실제로 알파벳을 넣어줄 필요가 없음
//어차피 양끝에 넣어주는 것은 동일한 알파벳이므로
#include <stdio.h>
#include <cstring>
char A[51];
char B[51];
int main()
{
	int sum, min;
	min = 51;
	scanf("%s %s", A, B);
	for (int i = 0; i <= strlen(B) - strlen(A); i++)
	{
		sum = 0;
		for (int j = 0; j < strlen(A); j++)
		{
			if (A[j] != B[j+i])
				sum++;
		}
		if (sum < min)
			min = sum;
	}
	printf("%d", min);
}
*/