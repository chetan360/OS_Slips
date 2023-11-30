#include <stdio.h>
#include <unistd.h>
#include <sys/resource.h>

int main() {
	pid_t pid = fork();
	
	if(pid == 0) {
		printf("I am child process.\n");
		printf("PID = %d\n", getpid());
		printf("Priority before nice call = %d\n", getpriority(PRIO_PROCESS, 0));
		nice(10);
		printf("Priority after nice call = %d\n", getpriority(PRIO_PROCESS, 0));
	} else if(pid > 0) {
		printf("I am parent process.\n");
		printf("PID = %d\n", getpid());
	} else {
		printf("Forking error.\n");
	}
	
	return 0;
}
