#include <iostream>
#include <cmath>

using namespace std;

void SearchPrime(int a, int b)
{
	bool* prime = new bool[b+1];
	fill_n(prime, b + 1, 0);
	prime[0] = true;
	prime[1] = true;
	for (int i = 2; i*i <=b ; i++)
	{
		if (prime[i]) continue;
		for (int j = i * 2; j <= b; j+=i)
			prime[j] = true;
	}

	for (int i = a; i <= b; i++)
	{
		if (prime[i] == false)
			cout << i << "\n";
	}
	delete[] prime;
}

int main() {
	int M, N;
	cin >> M >> N;
	SearchPrime(M, N);
}
