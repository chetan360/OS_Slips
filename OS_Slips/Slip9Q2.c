#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <fcntl.h>

void count(char c, char *filename) {
	int cCnt=0, wCnt=0, lCnt=0, fp;
	char ch;
	
	if((fp = open(filename, O_RDONLY)) == -1) {
		printf("File %s is not found.\n\n", filename);
	}
	
	while(read(fp, &ch, 1) != 0) {
		if(ch == '\n') {
			wCnt++;
			lCnt++;
		} else if(ch == ' ') {
			wCnt++;
		} else {
			cCnt++;
		}
	}
	
	close(fp);
	
	switch(c) {
		case 'c':
			printf("Total no. of chars = %d\n\n", cCnt);
			break;
		case 'w':
			printf("Total no. of words = %d\n\n", wCnt);
			break;
		case 'l':
			printf("Total no. of lines = %d\n\n", lCnt);
	}
}

int main() {
	char command[80], t1[20], t2[20], t3[20];
	int n;
	
	system("clear");
	
	while(1) {
		printf("myshell:> ");
		fflush(stdin);
		
		fgets(command, 80, stdin);
		n = sscanf(command, "%s %s %s", t1, t2, t3);
		
		if(n == 3) {
			if(strcmp(t1, "count") == 0) {
				count(t2[0], t3);
			} else {
				printf("%s is invalid command.\n\n", t1);
			}
		} else {
			printf("please enter command in this form(count c/w/f filename).");
		}
	}
	
	return 0;
}

