#include <stdio.h>

int frist[100005];

int n, m=0;

int Frist(int k, int i){
	if (i<=(n-1)/2){
		return k-i;
	}
	else
		return k  - (n - (i + 1));
}

int main(){
	scanf("%d",&n);
	for (int i=0; i<n; i++){
		int k; scanf("%d",&k);
		int p = Frist(k,i);
		if (p>0){
		frist[p]++;
		if (frist[p]>m)
			m=frist[p];
		}
	}
	printf("%d",n-m);
}