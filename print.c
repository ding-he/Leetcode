#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/times.h>

#define MAX(X, Y) (((X) > (Y)) ? (X) : (Y))

void sleepms(int millisecond)
{
	struct timeval delay;
	delay.tv_sec = 0;
	delay.tv_usec = millisecond * 1000;
	select(0, NULL, NULL, NULL, &delay);
}

void increase(int *num)
{
	++*num;
}

void decrease(int *num)
{
	--*num;
}

void do_iteration(int begin, int end)
{
	void (*next)(int *);
	int i;
	const int bufsize = 512;
	char format[bufsize];
	int iter;
	int iter_count;

	if (begin <= end) {
		next = increase;
	} else {
		next = decrease;
	}

	iter = MAX(begin, end);
	iter_count = 0;
	while (iter != 0) {
		iter /= 10;
		++iter_count;
	}
	iter = MAX(begin, end);

	snprintf(format, sizeof(format), "current iteration is %%%dd/%%%dd\r", iter_count, iter_count);
	for (i = begin; i != end; next(&i)) {
		printf(format, i, iter);
		fflush(stdout);
		sleepms(1);
	}
	printf("\n");
}

int main(int argc, char *argv[])
{
	const int const_iter = 100;
	int iter;
	int i;

	if (argc == 2) {
		iter = atoi(argv[1]);
	}
	if (iter <= 0) {
		iter = const_iter;
	}

	do_iteration(0, iter);
	do_iteration(iter, -1);

	printf("exit\n");
}
