#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

const int
	MAXN = 1 << 17,
	MAXV = 101,
	MAXP = 25;
	
const int
	primes[MAXP] =
		{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41,
		43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};

int N, Q;
int vals[MAXN];
int sum[MAXP][MAXN];

int modPow(int a, int d, int mod)
{
	if (d == 0) return 1 % mod;
	if (d == 1) return a % mod;
	long long r = modPow(a, d / 2, mod);
	r = r * r % mod;
	if (d & 1)
		r = r * a % mod;
	return (int)r;
}

struct IO {
	int cur;
	inline char nextChar() { return cur = getc_unlocked(stdin); }
	inline char peekChar() { return cur; }
	inline operator bool() { return (peekChar() != 0); }
	inline static bool isSpace(char c) { return (c < '0' && c); }
	inline bool skipBlanks() { while (isSpace(nextChar())); return peekChar() != 0; }
	IO() : cur(0) {}

	inline IO& operator >> (char & c) { c = nextChar(); return *this; }

	inline IO& operator >> (char * buf) {
		if (skipBlanks()) {
			if (peekChar()) {
				*(buf++) = peekChar();
				while (!isSpace(nextChar())) *(buf++) = peekChar();
			}
			*(buf++) = 0;
		}
		return *this;
	}

	inline IO& operator >> (string & s) {
		if (skipBlanks()) {
			s += peekChar();
			while (!isSpace(nextChar())) s += peekChar();
		}
		return *this;
	}

	inline IO& operator >> (int & n) {
		if (skipBlanks()) {
			int sign = +1;
			if (peekChar() == '-') {
				sign = -1;
				n = nextChar() - '0';
			}
			else
				n = peekChar() - '0';
			while (!isSpace(nextChar())) {
				n *= 10;
				n += peekChar() - '0';
			}
			n *= sign;
		}
		return *this;
	}

	#define cin io
	#define endl ('\n')
} io;

int main()
{	
	ios_base::sync_with_stdio(false);

	cin >> N;
	for (int i = 1; i <= N; ++i)
		cin >> vals[i];
	
	for (int i = 1; i <= N; ++i)
	{
		int x = vals[i];
		for (int j = 0; j < MAXP && x != 1; ++j)
		{
			while (x % primes[j] == 0)
			{
				x /= primes[j];
				sum[j][i]++;
			}
		} 
	}
	
	for (int i = 0; i < MAXP; ++i)
		for (int j = 1; j <= N; ++j)
			sum[i][j] += sum[i][j - 1];
	
	for (cin >> Q; Q--;)
	{
		int lo, hi, mod;
		cin >> lo >> hi >> mod;
		
		if (hi - lo < 80)
		{
			long long ans = 1;
			for (int i = lo; i <= hi; ++i)
			{
				ans *= vals[i];
				if (ans > 10000000000000000LL)
					ans %= mod;
			}
			
			ans %= mod;
			
			cout << ans << "\n";
			continue ;
		}
		
		long long ans = 1;
		for (int i = 0; i < MAXP; ++i)
		{
			int e = sum[i][hi] - sum[i][lo - 1];
			if (e > 0)
				ans = ans * modPow(primes[i], e, mod) % mod;
		}
		
		cout << ans << "\n";
	}

	return 0;
} 
