#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>

void count(char choise, char *filename) {
	int fp, wCnt=0, lCnt=0, cCnt=0;
	char ch;
	
	if((fp = open(filename, O_RDONLY)) == -1) {
		printf("File %s not found.\n\n", filename);
	}
	
	while(read(fp, &ch, 1) != 0) {
		if(ch == ' ') {
			wCnt++; //'space' means word count++
		} else if(ch == '\n') {
			wCnt++; //'\n' means word count++ and line count++
			lCnt++;
		} else {
			cCnt++; // space ,\n not occured means char occured then char count++
		}
	}
	
	close(fp);
	
	switch(choise) {
		case 'c': printf("Total characters = %d\n\n", cCnt);
			break;
		case 'w': printf("Total characters = %d\n\n", wCnt);
			break;
		case 'l': printf("Total characters = %d\n\n", lCnt);
			break; 
	
	}
}

int main() {
	char command[80], t1[20], t2[20], t3[20];
	int n;
	
	system("clear");
	
	
	
	while(1) {
		printf("myshell$:> ");
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
			printf("please enter command in this form.(count c/w/l filename)\n\n");
		}
	}
}
