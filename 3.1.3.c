
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <signal.h>

int main(void)
{
void sigquit_handler(int sig);
char s[200];

if(signal(SIGQUIT,sigquit_handler)==SIG_ERR){
perror("signal");
exit(1);
}

printf("Enter a string:\n");

if(fgets(s,200,stdin)==NULL)
perror("gets");

else
printf("You entered:%s\n",s);

return 0;
}

void sigquit_handler(int sig)
{
printf("This is a special signal handler for sigquit!\n");
}
