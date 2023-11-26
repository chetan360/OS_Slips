#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>

void typeline(char *s, char *filename) {
	int fp, i=0, n=0;
	char ch;
	
	//open file
	if((fp = open(filename, O_RDONLY)) == -1) {
		printf("File %s is not found.\n", filename);
	}
	
	if(strcmp(s, "-a") == 0) {
		while(read(fp, &ch, 1) != 0) {
			printf("%c", ch);
		}
		printf("\n\n");
		
		//close file
		close(fp);
		return;
	}
	
	n = atoi(s);
	if(n > 0) {
		//count no. of lines in i
		while(read(fp, &ch, 1) != 0) {
			if(ch == '\n') {
				i++;
			}
			//i becomes n then stop
			if(i == n) {
				break;
			}
			printf("%c", ch);
		}
		printf("\n\n");
		
		//close file
		close(fp);
		return;
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
			if(strcmp(t1, "typeline") == 0) {
				typeline(t2, t3);
			} else {
				printf("%s is invalid command.\n\n", t1);
			}
		} else {
			printf("please enter command in this form.(typeline +n/-a filename)\n\n");
		}
	}

	return 0;
}

