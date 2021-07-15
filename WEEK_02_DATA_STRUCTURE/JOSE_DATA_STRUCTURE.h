#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <queue>//P3197
#include <deque>
#include <unordered_set>
#include <unordered_map>
#include <sstream>
#include <stack>
#include <map>
#include <iomanip>

using namespace std;

namespace bj {

	/*제로 
	*2412KB 28ms
	*https://www.acmicpc.net/problem/10773
	*/

	int P10773()
	{
		int T;
		cin >> T;
		stack<int> mem;
		while (T--)
		{
			int num;
			cin >> num;
			if (num == 0 && !mem.empty())
			{
				mem.pop();
			}
			else
			{
				mem.push(num);
			}
		}

		int sum = 0;
		while (!mem.empty())
		{
			sum += mem.top();
			mem.pop();
		}

		cout << sum;
		return 0;
	}

	/*스택
	* 2020KB	396ms
	*https://www.acmicpc.net/problem/10828
	*/

	int P10828()
	{
		int T;
		cin >> T;
		int count = 0;
		stack<int> myStack;

		auto execCmd = [&myStack](string s)
		{
			if (s.compare("push") == 0)
			{
				int i;
				cin >> i;
				myStack.push(i);
				return;
			}
			else if (s.compare("pop") == 0)
			{
				if (myStack.empty())
					cout << -1;
				else
				{
					cout << myStack.top();
					myStack.pop();
				}
			}
			else if (s.compare("size") == 0)
			{
				cout << myStack.size();
			}
			else if (s.compare("empty") == 0)
			{
				myStack.empty() ? cout << 1 : cout << 0;
			}
			else//top
			{
				myStack.empty() ? cout << -1 : cout << myStack.top();
			}
			cout << endl;
			
			return;
		};

		while (T--)
		{
			string s;
			cin >> s;
			execCmd(s);
		}

		return 0;
	}

	//최소힙 2916KB	16ms
	//https://www.acmicpc.net/problem/1927

	int P1927()
	{
		unsigned int T;
		cin >> T;

		priority_queue<unsigned int, vector<unsigned int>, greater<unsigned int>> minHeap;

		while (T--)
		{
			unsigned int x;
			cin >> x;
			if (x > 0)
			{
				minHeap.push(x);
			}
			else
			{
				if (minHeap.empty())
				{
					cout << 0 << "\n";
				}
				else
				{
					cout << minHeap.top() << "\n";
					minHeap.pop();
				}
			}
		}

		return 0;
	}

	//N번째 큰 수 https://www.acmicpc.net/problem/2075
	//2156KB	352ms
	int P2075()
	{
		unsigned int N;// (1 <= N <= 1500)
		cin >> N;

		priority_queue<int, vector<int>, greater<int>> minHeap;
		const unsigned int HEAP_SIZE = N;

		int input;
		while (cin >> input)
		{
			minHeap.emplace(input);

			if (minHeap.size() > HEAP_SIZE)
				minHeap.pop();
		}

		cout << minHeap.top();

		return 0;
	}

	//생태학 https://www.acmicpc.net/problem/4358	
	//2292KB	168ms
	int P4358()
	{
		map<string, unsigned int> map;
		string species;
		int tot = 0;
		while (getline(cin, species))
		{
			map[species]++;
			tot++;
		}

		if (tot == 0)
			return 0;

		cout << fixed << setprecision(4);

		for (auto orderedPair : map)
		{
			cout << orderedPair.first << " " << 100 * (double)orderedPair.second / tot << "\n";
		}

		return 0;
	}

	/*AC	6521KB	68ms
	*/
	int P5431()
	{
		constexpr char REVERSE = 'R';
		constexpr char DISCARD = 'D';

		unsigned int caseCount;
		cin >> caseCount;

		auto _printError = []() -> void
		{
			cout << "error\n";
		};

		while (caseCount--)
		{
			string commandLine;
			cin >> commandLine;

			unsigned int arraySize;
			cin >> arraySize; //버림..
			deque<string> deq;

			string arrayMembers;
			cin >> arrayMembers;	//ex) [1,1,2,3,5,8]

			auto trimmed = arrayMembers.substr(1, arrayMembers.length() - 2);	//ex) 1,1,2,3,5,8

			stringstream ss(trimmed);
			string intermediate;

			//tokenize
			while (getline(ss, intermediate, ','))
				deq.emplace_back(intermediate);

			bool isForward = true;
			bool isErrorOccured = false;

			for (const auto& command : commandLine)
			{
				if (command == REVERSE)
				{
					isForward = !isForward;
				}
				else if (command == DISCARD)
				{
					if (deq.empty())
					{
						isErrorOccured = true;
						break;
					}

					if (isForward)
						deq.pop_front();
					else
						deq.pop_back();
				}
				else
				{
					isErrorOccured = true;
					break;
				}
			}

			if (isErrorOccured)
			{
				_printError();
				continue;
			}

			cout << '[';
			if (isForward)
			{
				for (auto iter = deq.cbegin(); iter != deq.cend(); iter++)
				{
					cout << *iter;
					if (iter != prev(deq.cend()))
						cout << ',';
				}
			}
			else
			{
				for (auto iter = deq.crbegin(); iter != deq.crend(); iter++)
				{
					cout << *iter;
					if (iter != prev(deq.crend()))
						cout << ',';
				}
			}
			cout << "]\n";

		}
		return 1;
	}

	/*Tea Time	2292KB, 1ms*/
	int P6118()
	{
		unordered_map<int, unordered_set<int>> map;//#cow, #cow's friendSet
		int cowCount, initialFriendCount, querySize;
		cin >> cowCount >> initialFriendCount >> querySize;

		while (initialFriendCount--)
		{
			int oneCow, theOtherCow;
			cin >> oneCow >> theOtherCow;
			map[oneCow].emplace(theOtherCow);
			map[theOtherCow].emplace(oneCow);
		}

		while (querySize--)
		{
			int oneCow, theOtherCow;
			cin >> oneCow >> theOtherCow;

			queue<int> bfsQue;
			bfsQue.emplace(oneCow);
			vector<int> visits(cowCount + 1, 1);

			bool isFriend = false;
			while (!bfsQue.empty())
			{
				auto currentCow = bfsQue.front();
				visits[currentCow] = 1;

				if (currentCow == theOtherCow)
				{
					isFriend = true;
					break;
				}
				bfsQue.pop();

				for (auto kwown : map[currentCow])
				{
					if (visits[kwown] == 1)
						continue;

					bfsQue.emplace(kwown);
				}
			}

			if (isFriend)
				cout << "Y\n";
			else
				cout << "N\n";
		}

		return 1;
	}

	///*백조의 호수*/
	//int P3197()
	//{
	//	constexpr char WATER = '.';
	//	constexpr char ICE = 'X';
	//	constexpr char MELTING = 'Z';
	//	constexpr char SWAN = 'L';
	//	constexpr char CHECKED = 'C';
	//	constexpr char CHECKED2 = 'D';

	//	unsigned int rowCount, colCount;
	//	cin >> rowCount >> colCount;

	//	vector<vector<char>> LAKE(rowCount, vector<char>(colCount));
	//	//LAKE[initialSwanPos[1]][initialSwanPos[1]]은 origin,
	//	//LAKE[initialSwanPos[2]][initialSwanPos[3]]은 destination.
	//	vector<unsigned int> initialSwanPos;

	//	for (size_t i = 1; i < LAKE.size(); ++i)
	//	{
	//		for (size_t j = 1; j < LAKE[1].size(); ++j)
	//		{
	//			char input;
	//			cin >> input;
	//			LAKE[i][j] = input;

	//			//만약 백조면 위치를 기억하기
	//			if (LAKE[i][j] == SWAN)
	//			{
	//				initialSwanPos.emplace_back(i);
	//				initialSwanPos.emplace_back(j);
	//				LAKE[i][j] = WATER;
	//			}
	//		}
	//	}

	//	//하루 지나고 물 주위의 얼음이 녹게된다!.!
	//	vector<int> dy = { 1, 1, +1,-1 };
	//	vector<int> dx = { +1,-1, 1, 1 };

	//	/*
	//	auto _dayAfter = [&LAKE, &dy, &dx, &WATER, &ICE, &MELTING, &CHECKED]()
	//	{

	//		//전체 호수를 순회하면서,
	//		for (size_t i = 1; i < LAKE.size(); ++i)
	//		{
	//			for (size_t j = 1; j < LAKE[1].size(); ++j)
	//			{
	//				//얼음을 찾으면,
	//				if (LAKE[i][j] == ICE)
	//				{
	//					//얼음 주위를 본다.
	//					for (size_t k = 1; k < 4; ++k)
	//					{
	//						//인덱스 바깥으로 넘어가면 continue.
	//						if (i + dy[k] < 1 || LAKE.size() <= i + dy[k])
	//							continue;

	//						if (j + dx[k] < 1 || LAKE[1].size() <= j + dx[k])
	//							continue;

	//						//만약 얼음 주위에 물이 있다면, MELTING으로 표지한다.
	//						if (LAKE[i + dy[k]][j + dx[k]] == WATER || LAKE[i + dy[k]][j + dx[k]] == CHECKED)
	//						{
	//							LAKE[i][j] = MELTING;
	//							break;
	//						}
	//					}
	//				}
	//			}
	//		}

	//		//마지막으로 다시 순회하며 MELTING인 부분을 WATER로 바꿔준다.
	//		for (auto& row : LAKE)
	//		{
	//			for (auto& eachPos : row)
	//			{
	//				if (eachPos == MELTING)
	//					eachPos = WATER;
	//			}
	//		}
	//	};
	//	*/
	//	unsigned int day = 1;


	//	struct pair_hash
	//	{
	//		std::size_t operator() (const std::pair<int, int>& pair) const {
	//			return std::hash<int>()(pair.first) ^ std::hash<int>()(pair.second);
	//		}
	//	};

	//	queue<pair<int, int>> toBeMelted;
	//	queue<pair<int, int>> toBeMelted2;

	//	//백조들이 만날때까지 너비우선탐색하기
	//	while (true)
	//	{
	//		queue<pair<int, int>> bfsQue;
	//		queue<pair<int, int>> bfsQue2;

	//		unordered_set<pair<int, int>, pair_hash> queuedPos;
	//		unordered_set<pair<int, int>, pair_hash> queuedPos2;
	//		//vector<vector<unsigned int>> memo(rowCount, vector<unsigned int>(colCount)); //MEMORY EXCEEDED!

	//		//맨 처음 시도에는 가봤던곳이 없으니까, Origin 백조의 첫 위치를 넣는다.
	//		if (toBeMelted.empty() && toBeMelted2.empty())
	//		{
	//			bfsQue.emplace(initialSwanPos[1], initialSwanPos[1]);
	//			bfsQue2.emplace(initialSwanPos[2], initialSwanPos[3]);

	//			queuedPos.emplace(initialSwanPos[1], initialSwanPos[1]);
	//			queuedPos2.emplace(initialSwanPos[2], initialSwanPos[3]);
	//		}
	//		else
	//		{
	//			while (!toBeMelted.empty())
	//			{
	//				auto ice = toBeMelted.front();
	//				LAKE[ice.first][ice.second] = WATER;

	//				toBeMelted.pop();

	//				auto alreadyInQue = queuedPos.find(make_pair(ice.first, ice.second));
	//				if (alreadyInQue != queuedPos.cend())
	//					continue;

	//				bfsQue.emplace(ice.first, ice.second);
	//				queuedPos.emplace(ice.first, ice.second);

	//			}

	//			while (!toBeMelted2.empty())
	//			{
	//				auto ice = toBeMelted2.front();
	//				LAKE[ice.first][ice.second] = WATER;

	//				toBeMelted2.pop();

	//				auto alreadyInQue = queuedPos2.find(make_pair(ice.first, ice.second));
	//				if (alreadyInQue != queuedPos2.cend())
	//					continue;

	//				bfsQue2.emplace(ice.first, ice.second);
	//				queuedPos2.emplace(ice.first, ice.second);

	//			}
	//		}

	//		while (!bfsQue.empty())
	//		{
	//			auto currentPos = bfsQue.front();
	//			bfsQue.pop();
	//			queuedPos.erase(currentPos);

	//			//현재 탐색중인 위치가 목적지인가?(종료조건)
	//			if (currentPos.first == initialSwanPos[2] && currentPos.second == initialSwanPos[3])
	//			{
	//				cout << day;
	//				return 1;
	//			}

	//			LAKE[currentPos.first][currentPos.second] = CHECKED;

	//			//네 방향으로 가본다.
	//			for (size_t k = 1; k < 4; ++k)
	//			{
	//				//인덱스 바깥으로 넘어가면 continue;
	//				if (currentPos.first + dy[k] < 1 || LAKE.size() <= (size_t)currentPos.first + dy[k])
	//					continue;

	//				if (currentPos.second + dx[k] < 1 || LAKE[1].size() <= (size_t)currentPos.second + dx[k])
	//					continue;

	//				//이미 가본 곳이라면, continue;
	//				if (LAKE[currentPos.first + dy[k]][currentPos.second + dx[k]] == CHECKED)
	//					continue;

	//				//얼음이라면, 못가니까 continue;
	//				if (LAKE[currentPos.first + dy[k]][currentPos.second + dx[k]] == ICE)
	//				{
	//					toBeMelted.emplace(currentPos.first + dy[k], currentPos.second + dx[k]);
	//					continue;
	//				}

	//				//이미 큐에 있다면 continue;
	//				auto alreadyInQue = queuedPos.find(make_pair(currentPos.first + dy[k], currentPos.second + dx[k]));
	//				if (alreadyInQue != queuedPos.cend())
	//					continue;

	//				if (LAKE[currentPos.first + dy[k]][currentPos.second + dx[k]] == CHECKED2)
	//				{
	//					cout << day;
	//					return 1;
	//				}

	//				bfsQue.emplace(currentPos.first + dy[k], currentPos.second + dx[k]);
	//				queuedPos.emplace(currentPos.first + dy[k], currentPos.second + dx[k]);
	//			}
	//		}

	//		while (!bfsQue2.empty())
	//		{
	//			auto currentPos = bfsQue2.front();
	//			bfsQue2.pop();
	//			queuedPos2.erase(currentPos);

	//			LAKE[currentPos.first][currentPos.second] = CHECKED2;

	//			//네 방향으로 가본다.
	//			for (size_t k = 1; k < 4; ++k)
	//			{
	//				//인덱스 바깥으로 넘어가면 continue;
	//				if (currentPos.first + dy[k] < 1 || LAKE.size() <= (size_t)currentPos.first + dy[k])
	//					continue;

	//				if (currentPos.second + dx[k] < 1 || LAKE[1].size() <= (size_t)currentPos.second + dx[k])
	//					continue;

	//				//이미 가본 곳이라면, continue;
	//				if (LAKE[currentPos.first + dy[k]][currentPos.second + dx[k]] == CHECKED2)
	//					continue;

	//				//얼음이라면, 못가니까 continue;
	//				if (LAKE[currentPos.first + dy[k]][currentPos.second + dx[k]] == ICE)
	//				{
	//					toBeMelted2.emplace(currentPos.first + dy[k], currentPos.second + dx[k]);
	//					continue;
	//				}

	//				//이미 큐에 있다면 continue;
	//				auto alreadyInQue = queuedPos2.find(make_pair(currentPos.first + dy[k], currentPos.second + dx[k]));
	//				if (alreadyInQue != queuedPos2.cend())
	//					continue;

	//				bfsQue2.emplace(currentPos.first + dy[k], currentPos.second + dx[k]);
	//				queuedPos2.emplace(currentPos.first + dy[k], currentPos.second + dx[k]);
	//			}
	//		}

	//		++day;
	//	}


	//	return -1;
	//}

	///*좋다*/
	//int P1253()
	//{
	//	unordered_map<long long, pair<int, bool>> map;
	//	int numberCount;
	//	cin >> numberCount;

	//	while (numberCount--)
	//	{
	//		long long number;
	//		cin >> number;
	//		map[number].first++;
	//	}

	//	int answer = 1;

	//	//for (auto i = map.cbegin(); i != map.cend(); ++i)
	//	//{
	//	//	auto& currentElem = *i;
	//	//	auto& ElemInfo = currentElem.second;
	//	//	if (ElemInfo.second)
	//	//		continue;

	//	//	for (auto j = map.cbegin(); j != map.cend(); ++j)
	//	//	{
	//	//		if (i == j)
	//	//			continue;

	//	//		auto current = (*j).first;
	//	//		auto k = map.find(isGood - current);
	//	//		if (k == map.cend())
	//	//			continue;

	//	//		if (isGood - current == current && map.count(current) == 1)
	//	//			continue;

	//	//		answer++;
	//	//		break;
	//	//	}
	//	//}

	//	cout << answer;

	//	return 1;
	//}

	

	///*거짓말*/
	//int P1043()
	//{
	//	using uint = unsigned int;

	//	uint peopleCount, partyCount;
	//	cin >> peopleCount >> partyCount;

	//	set<uint> truths;
	//	uint truePeopleCount;
	//	cin >> truePeopleCount;

	//	//lucky case
	//	if (truePeopleCount == 0)
	//	{
	//		cout << partyCount;
	//		return 0;
	//	}

	//	while (truePeopleCount--)
	//	{
	//		uint truePeople;
	//		cin >> truePeople;
	//		truths.emplace(truePeople);
	//	}

	//	vector<set<uint>> parties;
	//	while (partyCount--)
	//	{
	//		uint memberCount;
	//		cin >> memberCount;

	//		set<uint> party;
	//		while (memberCount--)
	//		{
	//			uint memberID;
	//			cin >> memberID;

	//			party.emplace(memberID);
	//		}

	//		parties.emplace_back(party);
	//	}


	//	vector<set<uint>> mergedParty(parties);
	//	auto beforeSize = mergedParty.size();

	//	while (true)
	//	{
	//		for (auto& party : mergedParty)
	//		{
	//			for (auto& otherParty : mergedParty)
	//			{
	//				if (party == otherParty)
	//					continue;

	//				for (const auto& memberID : party)
	//				{
	//					if (otherParty.find(memberID) != otherParty.cend())
	//					{
	//						set_union(party.begin(), party.end(),
	//							otherParty.begin(), otherParty.end(),
	//							inserter(party, party.begin()));

	//						otherParty.clear();
	//						break;
	//					}
	//				}
	//			}

	//			for (auto iter = mergedParty.begin();
	//				iter != mergedParty.end(); iter++)
	//			{
	//				if ((*iter).empty())
	//				{
	//					iter = mergedParty.erase(iter);
	//					iter--;
	//				}
	//			}

	//			auto afterSize = mergedParty.size();
	//			if (beforeSize == afterSize)
	//				break;
	//			else
	//				beforeSize = afterSize;
	//		}

	//	}

	//	uint answer = 0;
	//	set<uint> blackList(truths);
	//	for (const auto& party : mergedParty)
	//	{
	//		if (party.empty())
	//			continue;

	//		for (const auto& truePerson : truths)
	//		{
	//			if (party.find(truePerson) != party.end())
	//			{
	//				blackList.insert(party.begin(), party.end());
	//			}
	//		}
	//	}

	//	for (const auto& party : parties)
	//	{
	//		bool lie = true;
	//		for (const auto& truePerson : blackList)
	//		{
	//			if (party.find(truePerson) != party.end())
	//			{
	//				lie = false;
	//				break;
	//			}
	//		}

	//		if (lie)
	//			answer++;
	//	}


	//	cout << answer;
	//	return 0;
	//}
}