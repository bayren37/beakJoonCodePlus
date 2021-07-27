#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

namespace bj {

	//단어 맞추기
	int P9081()
	{
		int caseSize;
		cin >> caseSize;

		while (caseSize--)
		{
			string sample;
			cin >> sample;

			string lastWord = sample;
			sort(lastWord.rbegin(), lastWord.rend());
			if (lastWord != sample)
				next_permutation(sample.begin(), sample.end());


			cout << sample << "\n";
		}

		return 0;
	}

	//2292KB	44ms
	int P9177()
	{
		int caseSize;
		cin >> caseSize;

		int caseNumber = 0;
		while (caseSize--)
		{
			string A, B, C;
			cin >> A >> B >> C;

			A.push_back('#'); B.push_back('#');
			queue<pair<string::iterator, string::iterator>> que;
			que.emplace(A.begin(), B.begin());

			vector<vector<int>> memory(A.length(), vector<int>(B.length()));
			bool isPossible = false;

			while (!que.empty())
			{
				auto AIter = que.front().first;
				auto BIter = que.front().second;
				que.pop();

				auto AIndex = distance(A.begin(), AIter);
				auto BIndex = distance(B.begin(), BIter);

				if (AIndex + BIndex == C.length())
				{
					isPossible = true;
					break;
				}

				if (memory[AIndex][BIndex])
					continue;

				bool condition1 = C[AIndex + BIndex] == *AIter;
				bool condition2 = C[AIndex + BIndex] == *BIter;

				memory[AIndex][BIndex] = true;

				if (condition1)
					que.emplace(AIter + 1, BIter);

				if (condition2)
					que.emplace(AIter, BIter + 1);
			}

			cout << "Data set " << ++caseNumber << ": ";
			isPossible ? cout << "yes\n" : cout << "no\n";
		}

		return 0;
	}

	//애너그램
	//2024KB	24ms
	int P6443()
	{
		int caseSize;
		cin >> caseSize;

		while (caseSize--)
		{
			string sample;
			cin >> sample;

			sort(sample.begin(), sample.end());

			do
			{
				cout << sample << "\n";
			} while (next_permutation(sample.begin(), sample.end()));
		}

		return 0;
	}

	//acattgagtc
	//<a/c/<>t>gagtc
	int P2306()
	{
		string sample;
		cin >> sample;

		vector<vector<int>> memory(sample.length(), vector<int>(sample.length()));

		//_KOInize();

		//i : substr의 length
		for (size_t substrLength = 1; substrLength < sample.length(); substrLength++)
		{
			//j : substr의 start Index
			for (size_t startIndex = 0; substrLength + startIndex < sample.length(); startIndex++)
			{
				if ((sample[startIndex] == 'a' && sample[substrLength + startIndex] == 't') || (sample[startIndex] == 'g' && sample[substrLength + startIndex] == 'c'))
					memory[startIndex][substrLength + startIndex] = memory[startIndex + 1][substrLength + startIndex - 1] + 2;

				for (int k = startIndex; k < substrLength + startIndex; k++)
				{
					int concat = memory[startIndex][k] + memory[k + 1][substrLength + startIndex];
					memory[startIndex][substrLength + startIndex] = max(memory[startIndex][substrLength + startIndex], concat);
				}
			}
		}

		//처음 끝
		cout << memory[0][sample.length() - 1];
		return 0;
	}

	int P16228()
	{
		const auto MIN = "<";
		const auto MAX = ">";
		const auto PLUS = "+";
		const auto MINUS = "-";
		const auto OPEN = "(";
		const auto CLOSE = ")";

		vector<string> operations = { MIN , MAX, PLUS, MINUS, OPEN, CLOSE };

		string expression;
		cin >> expression;

		stack<string> myStack;
		queue<string> PostfixNotation;

		

		for (auto iter = expression.begin(); iter != expression.end(); ++iter)
		{

		}
		return 0;
	}


	int P1652()
	{
		int roomSize;
		cin >> roomSize;

		constexpr char BAGGAGE = 'X';

		vector<vector<char>> room(roomSize + 2, vector<char>(roomSize + 2, BAGGAGE));

		for (size_t i = 1; i < room.size() - 1; i++)
		{
			for (size_t j = 1; j < room[0].size() - 1; j++)
				cin >> room[i][j];
		}

		int bedSpaceRowCount = 0;
		int bedSpaceColCount = 0;

		for (size_t i = 1; i < room.size(); i++)
		{
			int lastBaggageRowIndex = 0;
			int lastBaggageColIndex = 0;

			for (size_t j = 1; j < room[0].size(); j++)
			{
				if (room[i][j] == BAGGAGE)
				{
					if (j - lastBaggageColIndex > 2)
						++bedSpaceRowCount;

					lastBaggageColIndex = j;
				}

				if (room[j][i] == BAGGAGE)
				{
					if (j - lastBaggageRowIndex > 2)
						++bedSpaceColCount;

					lastBaggageRowIndex = j;
				}
			}
		}

		cout << bedSpaceRowCount << " " << bedSpaceColCount;

		return 0;
	}

	int P1013()
	{
		int caseSize;
		cin >> caseSize;
		while (caseSize--)
		{
			string sample;
			cin >> sample;

			for (auto iter = sample.begin(); iter != sample.end(); ++iter)
			{
				if (*iter == '0')
				{
					auto nextIter = next(iter);
					if (*nextIter == '0' && iter != sample.begin())
					{
						auto prevIter = prev(iter);
						if (*prevIter == '1')
						{
							sample.replace(prevIter, next(nextIter), "@");
							iter = sample.begin();
						}

					}
					else
					{
						sample.replace(iter, next(nextIter), "@");
						iter = sample.begin();
					}
				}
			}
		}

		return 0;
	}

	int P1316()
	{
		int caseSize;
		cin >> caseSize;

		int count = 0;
		while (caseSize--)
		{
			string sample;
			cin >> sample;

			sample.erase(unique(sample.begin(), sample.end()), sample.end());

			unordered_map<char, int> map;
			bool isGroup = true;
			for (size_t i = 0; i < sample.size(); i++)
			{
				if (map[sample[i]] == 0)
					map[sample[i]]++;
				else
					isGroup = false;
			}

			if (isGroup)
				++count;
		}

		cout << count;

		return 0;
	}
}