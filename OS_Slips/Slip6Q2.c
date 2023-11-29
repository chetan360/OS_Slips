#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>

void search(char c, char *filename, char *pattern) {
	char buff[80], *p, ch;
	int fp, i=1, j=0;
	
	if((fp = open(filename, O_RDONLY)) == -1) {
		printf("File %s not found.\n\n", filename);
	}
	
	switch(c) {
		case 'f':
			while(read(fp, &ch, 1) != 0) {
				if(ch == '\n') {
					buff[j] = '\0';
					j=0;
					if(strstr(buff, pattern) != NULL) {
						printf("%s\n\n", buff);
						break;
					}
				} else {
					buff[j] = ch;
					j++;
				}
			}
			break;
		case 'a':
			while(read(fp, &ch, 1) != 0) {
				if(ch == '\n') {
					buff[j] = '\0';
					j=0;
					if(strstr(buff, pattern) != NULL) {
						printf("%d : %s\n", i, buff);
						i++;
					}
				} else {
					buff[j] = ch;
					j++;
				}
			}
			printf("\n");
	}
}

int main() {
	char command[80], t1[20], t2[20], t3[20], t4[20];
	int n;
	
	system("clear");
	
	while(1) {
		printf("myshell:> ");
		fflush(stdin);
		
		fgets(command, 80, stdin);
		n = sscanf(command, "%s %s %s %s", t1, t2, t3, t4);
		
		if(n == 4) {
			if(strcmp(t1, "search") == 0) {
				search(t2[0], t3, t4);
			} else {
				printf("%s is invalid command.\n\n", t1);
			}
		} else {
			printf("please enter command in this form(search f/a filename pattern).\n\n");
		}
	}

	return 0;
}

