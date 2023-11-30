#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <dirent.h>
#include <fcntl.h>

void typeline(char *c, char *filename) {
	int fp, i=0, n;
	char ch;
	
	if((fp = open(filename, O_RDONLY)) == -1) {
		printf("File %s is not found.\n\n", filename);
	}
	
	if(strcmp(c, "-a") == 0) {
		while(read(fp, &ch, 1) != 0) {
			if(ch == '\n') {
				i++;
			}
			printf("%c", ch);
		}
		printf("\n");
	}
	
	n = atoi(c);
	if(n > 0) {
		while(read(fp, &ch, 1) != 0) {
			if(ch == '\n') {
				i++;
			} else if(i == n) {
				break;
			}
			printf("%c", ch);
		}
		printf("\n");
	}
	
	close(fp);
	return;
}

int main() {
	char cmd[60], t1[20], t2[20], t3[20];
	int n;

	system("clear");
	
	while(1) {
		printf("myshell:> ");
		fflush(stdin);
		
		fgets(cmd, 60, stdin);
		n = sscanf(cmd, "%s %s %s", t1, t2, t3);
		
		if(n == 3) {
			if(strcmp(t1, "typeline") == 0) {
				typeline(t2, t3);
			} else {
				printf("%s is invalid command.\n\n", t1);
			}
		} else {
			printf("please enter command in this form.(typeline +n/-a filename).\n\n");
		}
	}
		
	return 0;
}

