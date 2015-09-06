#include <stdio.h>

char s[1005];
int c = 0;

int main(){
	scanf("%s",s);
	for (int i=0; s[i]; i++){
		if (c==0){
			if (s[i]==&#39;h&#39;){
				c++;
				continue;
			}
		}
		if (c==1){
			if (s[i]==&#39;e&#39;){
				c++;
				continue;
			}
		}
		if (c==2){
			if (s[i]==&#39;l&#39;){
				c++;
				continue;
			}
		}
		if (c==3){
			if (s[i]==&#39;l&#39;){
				c++;
				continue;
			}
		}
		if (c==4){
			if (s[i]==&#39;o&#39;){
				c++;
				continue;
			}
		}
	}
	if (c==5) printf("YES");
	else printf("NO");
}