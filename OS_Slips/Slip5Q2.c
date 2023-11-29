#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

void search(char s, char *filename, char *pattern) {
	int fp, i=1, cnt=0, j=0;
	char ch, buff[80], *p;
	
	if((fp = open(filename, O_RDONLY)) == -1) {
		printf("File %s not found.\n\n", filename);
		return;
	}
	
	switch(s) {
		case 'f':
			while(read(fp, &ch, 1) != 0) {
				buff[j] = '\0';
				j=0;
				if(ch == '\n') {
					if(strstr(buff, pattern) != NULL) {
						printf("%d : %s\n\n", i, buff);
						break;
					}
					i++;
				} else {
					buff[j++] = ch;
				}
			}
			break;
		case 'c':
			while(read(fp, &ch, 1) != 0) {
				buff[j] = '\0';
				j=0;
				if(ch == '\n') {
					if(strstr(buff, pattern) != NULL) {
						p = buff;
						while((p = strstr(p, pattern)) != NULL) {
							cnt++;
							p++;
						}
					}
				} else {
					buff[j++] = ch;
				}
			}
			printf("Total no. of Occerence = %d\n\n",cnt);
	}
}

int main() {
	char command[80], t1[20], t2[20], t3[20], t4[20];
	int n;
	
	system("clear");
	
	while(1) {
		printf("myshell$:> ");
		
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
			printf("please enter command in this format(search f/c filename pattern).\n\n");
		}
	}
	
	return 0;
}
