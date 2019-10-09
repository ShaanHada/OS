#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<string.h>


void handler(int sig_no)
{
	printf("We are handling: %d\n", sig_no);
}

int main()
{
	int i=0;
	struct sigaction sig_act, sig_act1;

	memset(&sig_act, 0, sizeof (struct sigaction));
	sig_act.sa_handler = handler;
	//sig_act.sa_mask = 3; Will do it little later
	sigaction(SIGINT, &sig_act, (void *)0);
	sigaction(SIGQUIT, &sig_act1, (void *)0);

	while(1)
	{
		printf("%d\n", i++);
		sleep(1);
	}
	return 0;
}
