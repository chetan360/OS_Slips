#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
	pid_t pid = fork();
	
	if(pid == 0) {
		printf("I am Child Process :\n");
		printf("Parent PID = %d\n", getppid());
		printf("Child PID = %d\n", getpid());
		sleep(5);
		printf("I am child and I am orphan now.\n");
	} else if(pid > 0) {
		printf("I am Parent Process :\n");
		printf("Parent PID = %d\n", getpid());
		printf("Child PID = %d\n", pid);
		printf("Parent is terminnating.\n");
	} else {
		printf("Forking error.\n");
	}
	
	return 0;
}
