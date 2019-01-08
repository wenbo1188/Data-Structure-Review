#include <stdio.h>

#define MAX 100010
long long a = 0;
long long b = 0;
long long c = 0;
long long d = 0;

int main() {
	long long p,n;
	char s[MAX] = {0};
    scanf("%d", &n);
    scanf("%s", s);
	for(int i = 0;i < n;++i)
    {
		scanf("%d", &p);
		if (s[i]=='h')
        {
            a += p;
        }
		if (s[i]=='a')
        {
            b = a < b + p ? a : b + p;
        }
		if (s[i]=='r')
        {
            c = b < c + p ? b : c + p;
        }
		if (s[i]=='d')
        {
            d = c < d + p ? c : d + p;
	    }
    }

	printf("%lld\n", d);
    return 0;
}