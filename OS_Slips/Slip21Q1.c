#include <stdio.h>
#include <unistd.h>

int main() {
	pid_t pid = fork();
	
	if(pid == 0) {
		printf("I am child process.\n");
		printf("PID = %d\n", getpid());
	} else if(pid > 0) {
		printf("I am parent process.\n");
		printf("PID = %d\n", getpid());
	} else {
		printf("Forking error.\n");
	}
	
	return 0;
}
