#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int g_var1 = 0;
pthread_mutex_t mutex1;

void *inc_gv()
{
	int i,j;
	for (i=0;i<10;i++)
	{
		pthread_mutex_lock(&mutex1);
		g_var1++;
		for (j=0;j<5000000;j++);
		printf(" %d", g_var1);
		fflush(stdout);
		pthread_mutex_unlock(&mutex1);
	}
}


int main()
{
	pthread_t TA, TB;
	int TAret, TBret;
	int MUTret = pthread_mutex_init(&mutex1, NULL);
	
	TAret = pthread_create(&TA, NULL, inc_gv, NULL);
	TBret = pthread_create(&TB, NULL, inc_gv, NULL);

	pthread_join(TA, NULL);
	pthread_join(TB, NULL);
	printf("\n pthread2 completed \n");
	return 0;
}
