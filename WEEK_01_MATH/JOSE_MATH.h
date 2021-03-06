#pragma once

#include <iostream>
#include <set>//2609
#include <vector>//9613
#include <cstring>//6588
#include <string>//1676, to_string
#include <iterator>
using namespace std;

namespace bj {

	//최대공약수와 최소공배수
	int P2609()
	{
		//0ms

		/*
		* iterative한 방법
		*
		A의 약수를 1부터 A까지 찾는다.
			찾으면 => set에 추가한다.

		B의 약수를 B부터 1까지 찾는다.
			찾으면 => 위 A의 약수들의 집합에 포함되어 있는지를 본다.
				있다면, 해당 약수는 최대 공약수이고, GCD * LCM = A * B를 이용해 최소공배수 출력

		*/
		unsigned int A, B;
		cin >> A >> B;

		//사실 이경우 unordered_set을 쓰는게 맞다.
		set<unsigned int> divisors;
		for (unsigned int i = 1; i <= A; ++i)
		{
			if (A % i == 0)
				divisors.emplace(i);
		}

		for (unsigned int j = A; j >= 1; --j)
		{
			if (B % j == 0)
			{
				if (divisors.find(j) != divisors.end())
				{
					cout << j;
					cout << endl;
					cout << A * B / j;
					return 0;
				}
			}
		}

		return -1;//있을 수 없는 경우
	}

	//최소공배수
	//이거는 유클리드 호제법으로 풀기
	int P1934()
	{
		//44ms

		/*
		유클리드 호제법
		두 양의 정수 a, b (a > b)에 대하여,
		a == bq + r(0 ≤ r <b)라 하면,
		a, b의 최대공약수는 b, r의 최대공약수와 같다. 즉,

					gcd(a, b) == gcd(b, r)

		r == 0이라면, a, b의 최대공약수는 b가 된다.
		*/

		unsigned int T;
		cin >> T;

		while (T--)
		{
			unsigned int A, B;
			cin >> A >> B;

			const unsigned int multiplied = A * B;

			if (A < B)
				swap(A, B);

			while (true)
			{
				auto r = A % B;
				if (r == 0)
				{
					cout << multiplied / B << endl;
					break;
				}
				else
				{
					A = B;
					B = r;
				}
			}

		}

		return 0;
	}

	int P6588()
	{
		//24ms

		/*
		* 골드바흐의 추측
		*
		* 4보다 큰 모든 짝수는 두 홀수 소수의 합으로 나타낼 수 있다.
		*
		*
		* 에라토스테네스의 체

		  1. 2부터 N까지 모든 정수를 적는다.
		  2. 아직 지우지 않은 수 중 가장 작은 수를 찾는다. 이것을 P라고 하고, 이 수는 소수이다.
		  3. P를 지우고, 아직 지우지 않은 P의 배수를 크기 순서대로 지운다.
		  4. 아직 모든 수를 지우지 않았다면, 다시 2번 단계로 간다.

		*/

		//vector<bool> filter(1000001); vector<bool> !안쓰기!

		constexpr size_t MAX_SIZE = 1000001;
		auto filter = new bool[MAX_SIZE];
		memset(filter, true, MAX_SIZE * sizeof(bool));

		//index를 number로 바로 쓰고싶다. filter[0], filter[1] => continue;
		for (size_t number = 2; number < MAX_SIZE; ++number)
		{
			if (filter[number])
			{
				//cout << number << "\n";
				for (size_t multiplier = 2; multiplier * number < MAX_SIZE; ++multiplier)
					filter[multiplier * number] = false;
			}
		}

		while (true)
		{
			unsigned int testCase;

			cin >> testCase;
			if (testCase < 6)
				break;

			for (size_t number = 2; number < MAX_SIZE; ++number)
			{
				if (filter[number] && filter[testCase - number])
				{
					cout << testCase << " = " << number << " + " << testCase - number << "\n";
					break;
				}
			}
		}

		return 0;
	}

	int P10430()
	{
		int A, B, C;
		std::cin >> A >> B >> C;

		std::cout << (A + B) % C << std::endl;
		std::cout << ((A % C) + (B % C)) % C << std::endl;
		std::cout << (A * B) % C << std::endl;
		std::cout << ((A % C) * (B % C)) % C << std::endl;

		return 0;
	}

	void P1978()
	{
		/*
		* 이전 소수로 판단된 수를 기억하지 않는 버전
		* 소수 판단을 N보다 작은 소수가 아닌 모든 수로 시도해 봄.
		*/
		int T;
		cin >> T;

		auto isPrime = [](const int N)
		{
			if (N == 1)
				return false;

			int div = N - 1;
			while (div != 1)
			{
				if (N % div-- == 0)
					return false;
			}
			return true;
		};

		int count = 0;
		while (T--)
		{
			int n;
			cin >> n;
			if (isPrime(n))
				count++;
		}

		cout << count;
	}

	int P1929()
	{
		/*
		* 이전 소수로 판단된 수를 기억하는 버전
		* 소수 판단을 N보다 작은 소수로 나눠 판단함
		*/

		ios::sync_with_stdio(false);
		cout.tie(nullptr);

		int M, N;
		cin >> M >> N;

		vector<int> primes;
		primes.reserve(1000000);

		for (int i = 2; i <= N; ++i)
		{
			bool isPrime = true;
			for (auto prime : primes)
			{
				if (prime * prime > i)
					break;

				if (i % prime == 0)
				{
					isPrime = false;
					break;
				}
			}

			if (isPrime)
			{
				if (M <= i && i <= N)
					cout << i << "\n";
				primes.push_back(i);
			}
		}

		return 0;
	}

	int P10872()
	{
		int N;
		cin >> N;

		long long ret = 1;
		while (N)
		{
			ret *= N--;
		}
		cout << ret;

		return 0;
	}

	int P1676()
	{
		/*N!에서 뒤에서부터 처음 0이 아닌 숫자가 나올 때까지
		 *0의 개수를 구하는 프로그램을 작성하시오.
		 */

		int N;
		cin >> N;

		int twoCount = 0, fiveCount = 0;
		while (N)
		{
			auto copyN = N;
			while (copyN)
			{
				if (copyN % 2 == 0)//if(!(N & 1))
					twoCount++;
				else
					break;

				copyN /= 2;
			}

			copyN = N--;
			while (copyN)
			{
				if (copyN % 5 == 0)//if(!(N & 1))
					fiveCount++;
				else
					break;

				copyN /= 5;
			}
		}

		cout << min(twoCount, fiveCount);

		return 0;
	}

	int P2004()
	{
		/*
		* nCr = A * 10^k*일떄 k?
		* nCr = n! / r!(n-r)!
		* P1676와 같은 방식으로 접근했으나 Time Exceeded
		*/
		typedef long long ll;

		ll n, r;
		cin >> n >> r;

		auto _div2 = [](const ll factorialParam) -> ll
		{
			ll answer = 0;

			for (ll i = 2; i <= factorialParam; i *= 2)
				answer += factorialParam / i;

			return answer;
		};

		auto _div5 = [](const ll factorialParam) -> ll
		{
			ll answer = 0;

			for (ll i = 5; i <= factorialParam; i *= 5)
				answer += factorialParam / i;

			return answer;
		};

		cout << min(_div2(n) - (_div2(r) + _div2(n - r)),
			_div5(n) - (_div5(r) + _div5(n - r)));

		return 0;
	}

	int P9613()
	{
		/*
			1 ≤ T ≤ 100
			1 < caseSize ≤ 100

			=> 쌍(pair)을 찾는거니까 그냥 이중 for문
		*/
		unsigned int T;
		cin >> T;
		while (T--)
		{
			unsigned int caseSize;
			cin >> caseSize;

			vector<unsigned int> inputs(caseSize);
			for (auto& input : inputs)
				cin >> input;

			unsigned long long answer = 0;

			for (unsigned int i = 0; i < caseSize; ++i)
			{
				for (unsigned int j = i + 1; j < caseSize; ++j)
				{
					unsigned int A = inputs[i], B = inputs[j];

					if (A < B)
						swap(A, B);

					while (true)
					{
						const auto r = A % B;
						if (r == 0)
						{
							answer += B;
							break;
						}
						else
						{
							A = B;
							B = r;
						}
					}
				}
			}

			cout << answer << endl;
		}

		return 0;
	}

	int P17087()
	{
		/*동생 찾기*/
		int brotherCount, crntPos;
		cin >> brotherCount >> crntPos;

		vector<int> brotherPos(brotherCount);

		auto _GCD = [](int A, int B)
		{
			/*
			유클리드 호제법
			두 양의 정수 a, b (a > b)에 대하여,
			a == bq + r(0 ≤ r <b)라 하면,
			a, b의 최대공약수는 b, r의 최대공약수와 같다. 즉,

						gcd(a, b) == gcd(b, r)

			r == 0이라면, a, b의 최대공약수는 b가 된다.
			*/

			if (A < B)
				swap(A, B);

			int R = A % B;
			while (R != 0)
			{
				A = B;
				B = R;
				R = A % B;
			}

			return B;
		};


		for (auto& pos : brotherPos)
		{
			cin >> pos;
			pos -= crntPos;
			if (pos < 0)
				pos = -pos;
		}

		int GCD = brotherPos[0];
		for (size_t i = 1; i < brotherPos.size(); ++i)
			GCD = _GCD(GCD, brotherPos[i]);

		cout << GCD;

		return 0;
	}

	int P1373()
	{
		//44ms
		/*2진수 => 8진수*/

		string binary;
		cin >> binary;

		string reversedAnswer;

		for (auto iter = binary.rbegin(); iter != binary.rend();)
		{
			auto advanced = iter;
			int three = 3;
			while (three-- != 0 && advanced != binary.rend())
			{
				advanced++;
			}

			string subStr(advanced.base(), iter.base());
			//string subStr(iter, advanced);

			int temp = 0;
			int pow2 = 1;
			for (int index = subStr.length() - 1; index >= 0; index--)
			{
				temp += (subStr[index] - '0') * pow2;
				pow2 *= 2;

			}
			reversedAnswer.append(1, (char)(temp + '0'));

			iter = advanced;
		}

		cout << string(reversedAnswer.rbegin(), reversedAnswer.rend());

		return 0;
	}

	int P1212()
	{
		/*8진수 => 2진수*/
		string octal;
		cin >> octal;

		string answer;
		for (auto iter = octal.begin(); iter != octal.end(); ++iter)
		{
			string subStr;
			auto currentDigit = *iter - '0';
			while (currentDigit)
			{
				subStr += (currentDigit % 2 + '0');
				currentDigit /= 2;
			}

			while (subStr.length() < 3)
				subStr += '0';
			answer += string(subStr.rbegin(), subStr.rend());
		}

		if (answer[0] == '0')
			answer.erase(answer.begin());

		if (answer[0] == '0')
			answer.erase(answer.begin());

		cout << answer;

		return 0;
	}

	int P2089()
	{
		/*-2진수*/
		long long decimal;
		cin >> decimal;
		if (decimal == 0)
			cout << 0;

		string answer;
		while (decimal != 0)
		{
			int currentDigit = decimal % -2;
			answer += abs(currentDigit) + '0';
			decimal = (int)ceil((double)decimal / -2.0);
		}

		cout << string(answer.rbegin(), answer.rend());

		return 0;
	}

	int P17103()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(nullptr);
		cout.tie(nullptr);

		//52ms

		/*
		* 골드바흐의 추측
		*
		* 4보다 큰 모든 짝수는 두 홀수 소수의 합으로 나타낼 수 있다.
		*
		*
		* 에라토스테네스의 체

		  1. 2부터 N까지 모든 정수를 적는다.
		  2. 아직 지우지 않은 수 중 가장 작은 수를 찾는다. 이것을 P라고 하고, 이 수는 소수이다.
		  3. P를 지우고, 아직 지우지 않은 P의 배수를 크기 순서대로 지운다.
		  4. 아직 모든 수를 지우지 않았다면, 다시 2번 단계로 간다.

		*/

		//vector<bool> filter(1000001); vector<bool> !안쓰기!

		constexpr size_t MAX_SIZE = 1000001;
		auto filter = new bool[MAX_SIZE];
		memset(filter, true, MAX_SIZE * sizeof(bool));
		filter[0] = filter[1] = false;

		//index를 number로 바로 쓰고싶다. filter[0], filter[1] => continue;
		for (size_t number = 2; number < MAX_SIZE; ++number)
		{
			if (filter[number])
			{
				for (size_t multiplier = 2; multiplier * number < MAX_SIZE; ++multiplier)
					filter[multiplier * number] = false;
			}
		}

		unsigned int caseSize;
		cin >> caseSize;
		vector<int> cases(caseSize);
		for (auto& sample : cases)
			cin >> sample;

		for (auto testCase : cases)
		{
			int count = 0;
			for (size_t number = 2; number < MAX_SIZE && 0 < testCase - number; ++number)
			{
				if (number > (size_t)testCase / 2)
					break;

				if (filter[number] && filter[testCase - number])
					count++;
			}

			cout << count << "\n";
		}

		return 0;
	}
}