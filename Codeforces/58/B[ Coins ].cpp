#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

const int maxi = 1000000;

vector <int> primes;
bool bprimes[maxi+10];

int Criba(){
	for (int i=2; i*i<maxi; i++)
		if (!bprimes[i])
			for (int j=i*i; j<maxi; j+=i)
				bprimes[j]=true;
	for (int i=2; i<maxi; i++)
		if (!bprimes[i])
			primes.push_back(i);
	return 0;
}

int n, k = 0;

int main(){
	Criba();
	scanf("%d",&n);
	while (n>1){
		printf("%d ",n);
		while ((n%primes[k])!=0) k++;
		n/=primes[k];
	}
	printf("%d",n);
}