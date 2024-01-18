
#include <stdio.h>
/* Fibonacci sequence using dynamic programming */

#define	MAXN	100	/* largest n or m */

long fib(int n)
{
    int i;                  /* counter */
	long long back1=1, back2=0;	/* last two values of f[n] */
	long long next;		/* placeholder for sum */

	if (n == 0) return (0);

        for (i=2; i<n; i++) {
		back2 = next;
		back1 = back2;
		next = back1+back2;
	}

        return(back1+back2);
}


int main()
{
	int i;
        for (i=0; i<MAXN; i=i+5){
                printf("fib(%d) = %ld\n",i, fib(i));
        }

	return 0;
}

