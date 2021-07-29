#pragma once

#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <functional>
#include <cmath>
#include <set>
using namespace std;

namespace bj {

	//좋다
	int P1253()
	{
		int numCount;
		cin >> numCount;//(1 ≤ N ≤ 2,000)

		unordered_map<int, pair<int, bool>> map;// key / count

		int identityCount = 0;//덧셈에 대한 항등원, 0
		for (size_t i = 0; i < numCount; ++i)
		{
			int num;
			cin >> num;//(|Ai| ≤ 1,000,000,000, Ai는 정수)

			if (num == 0)
			{
				++identityCount;
				continue;
			}
			++map[num].first;
		}

		int answer = 0;

		for (auto iter = map.begin(); iter != map.cend(); ++iter)
		{
			for (auto jter = map.begin(); jter != map.cend(); ++jter)
			{
				if (iter == jter)
					continue;

				auto findIter = map.find((*iter).first - (*jter).first);
				if (findIter != map.cend() && findIter != iter)
				{
					//ex) 4 = 2 + 2, 10 = 5 + 5
					if (findIter == jter && (*jter).second.first == 1)
						continue;

					(*iter).second.second = true;
					answer += (*iter).second.first;
					break;
				}
			}
		}

		//항등원이 존재할 경우
		if (identityCount > 0)
		{
			for (auto iter = map.begin(); iter != map.cend(); ++iter)
			{
				if ((*iter).second.second)
					continue;

				if ((*iter).second.first > 1)
					answer += (*iter).second.first;
			}

			bool condition = false;

			for (auto iter = map.begin(); iter != map.cend() && !condition; ++iter)
			{
				for (auto jter = map.begin(); jter != map.cend(); ++jter)
				{
					if (iter == jter)
						continue;

					auto findIter = map.find(-(*iter).first);
					if (findIter != map.cend() && findIter != iter)
					{
						condition = true;
					}
				}
			}

			//항등원 자체가 좋은 수일 경우
			if (identityCount > 2 || condition)
			{
				answer += identityCount;
			}
		}
		cout << answer;

		return 0;
	}

	//memory exceeded
	//직사각형 색칠하기 https://www.acmicpc.net/problem/1186
	/*2차원 평면에 축에 평행한 직사각형 N개가 있다.이 중 K개를 칠할 것이다.
	색칠한 면적 중 보이는 것의 최댓값을 구하는 프로그램을 작성하시오.*/
	int P1186()
	{
		int N, K;
		cin >> N >> K;
		vector<vector<int>> plane(20000 + 1, vector<int>(20000 + 1, 0));//좌표는 절댓값이 10,000보다 작거나 같은 정수

		int xMax = numeric_limits<int>::min(), yMax = numeric_limits<int>::min();
		int xMin = numeric_limits<int>::max(), yMin = numeric_limits<int>::max();

		for (size_t i = 1; i <= N; ++i)
		{
			int x1, y1, x2, y2;
			cin >> x1 >> y1 >> x2 >> y2;

			xMin = min(xMin, x1 + 10000);
			xMax = max(xMax, x2 + 10000);
			yMin = min(yMin, y1 + 10000);
			yMax = max(yMax, y2 + 10000);

			for (int y = y1 + 10000; y <= y2 + 10000; ++y)
			{
				for (int x = x1 + 10000; x <= x2 + 10000; ++x)
				{
					plane[y][x] = i;
				}
			}
		}

		map<int, int, greater<int>> map;
		for (size_t i = yMin; i <= yMax; i++)
		{
			for (size_t j = xMin; j <= xMax; j++)
			{
				if (plane[i][j] != 0)
					++map[plane[i][j]];
			}
		}

		for (auto i = map.begin(); i != map.end() && K; i++, K--)
		{
			cout << (*i).first << " ";
		}

		return 0;
	}

	//memory exceeded
	//좋은 수 https://www.acmicpc.net/problem/1060
	//문제 이해가 좀 어려웠어
	int P1060()
	{
		int setSize = 0;
		cin >> setSize;

		using pii = pair<int, int>;//key, section count;
		struct piiGreater
		{
			inline bool operator()(const pii& lhs, const pii& rhs) const
			{
				if (lhs.second == rhs.second)
					return lhs.first > rhs.first;
				return lhs.second > rhs.second;
			}
		};

		//pair; key, section count;
		priority_queue<pii, vector<pii>, piiGreater> minHeap;
		//heapSize는 아래에서 결정

		//minHeap.emplace(0, 0);
		//minHeap.emplace(2, 3);
		//minHeap.emplace(3, 3);
		//minHeap.emplace(5, 3);
		//minHeap.emplace(1, 5);



		set<int> set;
		vector<int> sectionSize;
		for (size_t i = 0; i < setSize; i++)
		{
			int s;
			cin >> s;
			set.emplace(s);
			//maxHeap.emplace(0, s);
		}

		vector<int> memory(*set.rbegin() + 1, 0);

		int heapSize;
		cin >> heapSize;
		//while (maxHeap.size() > heapSize)
		//	maxHeap.pop();

		function<int(int, int)> combination;
		struct pair_hash {
			size_t operator () (const pair<int, int>& p) const
			{
				auto h1 = hash<int>{}(p.first);
				auto h2 = hash<int>{}(p.second);

				return h1 ^ h2;
			}
		};
		unordered_map<pair<int, int>, int, pair_hash> combinationMemory;
		combination = [&](int n, int r) -> int
		{
			r = r < (n - r) ? r : (n - r);
			auto pair = make_pair(n, r);

			if (combinationMemory[pair] != 0)
				return combinationMemory[pair];

			if (r == 0 || r == n)
			{
				combinationMemory[pair] = 1;
				return combinationMemory[pair];
			}
			combinationMemory[pair] = combination(n - 1, r - 1) + combination(n - 1, r);

			return combinationMemory[pair];
		};

		set.emplace(0);
		for (auto iter = set.begin(); iter != prev(set.end()); ++iter)
		{
			auto from = *iter + 1;//0
			auto to = *next(iter);//2

			if (to - from <= 0)
				continue;

			sectionSize.emplace_back(to - from);
		}

		for (auto setIter = set.begin(); setIter != prev(set.end()); ++setIter)
		{
			auto currentSectionSize = sectionSize[distance(set.begin(), setIter)];
			for (size_t i = 1; i <= ceil((double)currentSectionSize / 2); ++i)
				memory[*next(setIter) - i] = memory[*setIter + i] = memory[*setIter + i - 1] + combination(currentSectionSize - i, 1);
		}

		for (size_t i = 1; i <= *set.rbegin(); ++i)
			minHeap.emplace(i, memory[i]);

		while (!minHeap.empty() && heapSize--)
		{
			cout << minHeap.top().first << " ";
			minHeap.pop();
		}

		auto from = *set.rbegin();
		while (heapSize-- > 0)
			cout << ++from << " ";

		return 0;
	}

	//기울기가 가장 큰 두점
	//https://www.acmicpc.net/problem/1858
	//모든 점의 x좌표는 다르다고 하자. 또한, 모든 점의 y좌표 역시 다르다고 하자.

	int P1858()
	{
		int coorCount;
		cin >> coorCount;

		struct Point
		{
			Point(int x, int y, int id) : x_(x), y_(y), id_(id) {};

			int x_;
			int y_;
			int id_;
		};

		struct Tangent
		{
			int from_ = -1;
			int to_ = -1;
			int value_ = 0.0;
		};

		vector<Point> coor;
		int id = 1;
		while (coorCount--)
		{
			int x, y;
			cin >> x >> y;
			coor.emplace_back(x, y, id++);
		}

		sort(coor.begin(), coor.end(), [](const Point& lhs, const Point& rhs)
			{
				return lhs.x_ < rhs.x_;
			});


		Tangent desired;
		for (size_t i = 0; i < coor.size() - 1; ++i)
		{
			const auto& from = coor[i];
			const auto& to = coor[i + 1];
			auto tangent = abs((double)(to.y_ - from.y_) / (to.x_ - from.x_));

			if (desired.value_ < tangent)
			{
				desired.value_ = tangent;
				desired.from_ = from.id_;
				desired.to_ = to.id_;

			}
			else if (abs(desired.value_ - tangent) < DBL_EPSILON)
			{
				for (size_t j = 0; j < coor.size() - 1; ++j)
				{
					if (j == i + 1 || j == i)
						continue;

					const auto& to = coor[j];
					auto tangentFromj = abs((double)(to.y_ - from.y_) / (to.x_ - from.x_));
					if (abs(tangent - tangentFromj) < DBL_EPSILON)
					{
						desired.to_ = min(desired.to_, to.id_);
					}
				}
			}
		}

		cout << desired.from_ << " " << desired.to_;

		return 0;
	}

	int P1964()
	{
		int caseSize;
		cin >> caseSize;

		while (caseSize--)
		{
			int applicantCount;
			cin >> applicantCount;

			vector<pair<int, int>> applicants(applicantCount);//paper / interview
			for (auto& applicant : applicants)
				cin >> applicant.first >> applicant.second;

			//서류 등수 순으로 정렬
			sort(applicants.begin(), applicants.end());
			auto interviewRankBound = (*applicants.begin()).second;

			int answer = 1;
			for (auto iter = next(applicants.cbegin()); iter != applicants.cend(); ++iter)
			{
				auto interviewRank = (*iter).second;
				if (interviewRankBound > interviewRank)
				{
					interviewRankBound = interviewRank;
					++answer;
				}
			}

			cout << answer << "\n";
		}

		return 0;
	}

	int P20551()
	{
		int arraySize, questionCount;
		cin >> arraySize >> questionCount;

		vector<int> array(arraySize);
		for (auto& elem : array)
			cin >> elem;

		sort(array.begin(), array.end());

		while (questionCount--)
		{
			int targetNumber;
			cin >> targetNumber;

			auto findIter = lower_bound(array.begin(), array.end(), targetNumber);
			if (findIter == array.end() || *findIter != targetNumber)
				cout << "answer :" << -1 << "\n";
			else
				cout << "answer :" << distance(array.begin(), findIter) << "\n";
		}

		return 0;
	}

	int P16678()
	{
		long long senatorCount;
		cin >> senatorCount;

		multiset<long long> honorScores;
		for (long long i = 0; i < senatorCount; ++i)
		{
			long long honorScore;
			cin >> honorScore;
			honorScores.emplace(honorScore);
		}

		long long answer = 0;
		long long defileCount = 0;

		while (!honorScores.empty())
		{
			auto score = *honorScores.begin();
			honorScores.erase(honorScores.begin());

			if (score > defileCount)
				answer += (score - defileCount++ - 1);
		}

		cout << answer;

		return 0;
	}

	int P1202() { return 0; }

}