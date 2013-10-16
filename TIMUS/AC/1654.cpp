/*
Alfonso2 Peterssen(mukel)
Team: UH++
Timus Online Judge
1654. Cipher Message
*/
#include <cstdio>

const int MAXN = 200005;

char S[MAXN];

int main()
{
	scanf( "%s", &S );
	
	int pos = 0;
	for (int i = 0; S[i]; i++)
	{
		S[pos++] = S[i];
		while (pos > 1 && S[pos - 1] == S[pos - 2])
			pos -= 2;
	}
	
	S[pos++] = '\0';
	
	printf( "%s\n", S );

	return 0;
}
