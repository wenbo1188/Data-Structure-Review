#include <stdio.h>
const int MOD =	998244353;
char s[200100];

int main(){
	int n;
    scanf("%d", &n);
	scanf("%s", s + 1);
	int l = 0, r = 0;
	while(s[1] == s[1 + l]) l++;
	while(s[n] == s[n - r]) r++;
	printf("%d\n", s[1] == s[n] ? (l + 1ll) * (r + 1ll) % MOD : l + r + 1);
	return 0;
}