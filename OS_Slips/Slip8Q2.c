#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <fcntl.h>

void search(char c, char *filename, char *pattern) {
	char buff[80], ch, *p;
	int fp, i=1, j=0, cnt=0;
	
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
						printf("%d : %s\n", i, buff);
						break;
					}
					i++;
				} else {
					buff[j] = ch;
					j++;
				}
			}
			printf("\n");
			break;
		case 'c':
			while(read(fp, &ch, 1) != 0) {
				if(ch == '\n') {
					buff[j] = '\0';
					j=0;
					if(strstr(buff, pattern) != NULL) {
						p = buff;
						while((p = strstr(p, pattern)) != NULL) {
							cnt++;
							p++;
						}
					}
				} else {
					buff[j] = ch;
					j++;
				}
			}
			printf("No. of occerences = %d\n\n", cnt);
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
				printf("%s is invalid command.", t1);
			}
		} else {
			printf("please enter command in this form(search f/c pattern).\n\n");
		}
	}
	
	return 0;
}

