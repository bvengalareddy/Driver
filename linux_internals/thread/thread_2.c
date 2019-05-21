#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
int g=10;

void *thread_fun1(void *p)
{
	printf("%s\n",__func__);

	g++;
	printf("g=%d\n",g);
	sleep(1);
	++g;
	printf("g=%d\n",g);
	sleep(2);
	g++;
	printf("g=%d\n",g);
	printf("g=%d\n",g);
	sleep(3);

	printf("g=%d\n",g);

	return 0;

}

void *thread_fun2(void *p)
{
	printf("%s\n",__func__);

	g--;
	printf("g=%d\n",g);
	sleep(3);
	--g;
	printf("g=%d\n",g);
	sleep(3);

	g++;

	printf("g=%d\n",g);

	return 0;

}

int main()
{
	pthread_t t1,t2;

	printf("before thread\n");

	pthread_create(&t1,NULL,thread_fun1,NULL);
	pthread_create(&t2,NULL,thread_fun2,NULL);
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);

	printf("after thread\n");

	exit(0);

}

