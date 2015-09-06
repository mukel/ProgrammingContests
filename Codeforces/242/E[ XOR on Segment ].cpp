#include <cstdio>

const int
	MAXN = 1 << 17;

int N, Q;
int vals[MAXN];
int lo, hi;

int main()
{
	scanf( "%d", &N );
	for (int i = 1; i <= N; i++)
		scanf( "%d", &vals[i] );

	scanf( "%d", &Q );
	
	while (Q--)
	{
		int op;
		scanf( "%d", &op );

		if(op == 1)
		{
			scanf( "%d %d", &lo, &hi );
			
			long long sum = 0;
			
			int tmp = 0, count = 0;
			
			for(int i = lo; i <= hi; ++i)
			{
				++count;
				if (count == 2000)
				{
					sum += tmp;
					count = 0;
					tmp = 0;
				}
				tmp += vals[i];
			}
			
			sum += tmp;
				
			printf( "%I64d\n", sum );
		}
		else
		{
			int x;
			scanf( "%d %d %d", &lo, &hi, &x );
			
			for(int i = lo; i <= hi; ++i)
				vals[i] ^= x;
		}
	}
	
	return 0;
}
