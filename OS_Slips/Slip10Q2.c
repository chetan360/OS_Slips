#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <fcntl.h>

void list(char c, char *dirname) {
	DIR *dir;
	struct dirent *entry;
	struct stat buff;
	
	if((dir = opendir(dirname)) == NULL) {
		printf("Directory %s not found.\n\n", dirname);
	}
	
	switch(c) {
		case 'f':
			while((entry = readdir(dir)) != NULL) {
				if(strcmp(entry->d_name, ".") == 0 ||
				strcmp(entry->d_name, "..") == 0) {
					continue;
				}
				printf("%s\n", entry->d_name);
			}
			printf("\n");
			break;
		case 'i':
			while((entry = readdir(dir)) != NULL) {
				stat(entry->d_name, &buff);
				if(strcmp(entry->d_name, ".") == 0 ||
				strcmp(entry->d_name, "..") == 0) {
					continue;
				}
				printf("%s : %ld\n", entry->d_name, buff.st_ino);
			}
			printf("\n");
	}
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
			if(strcmp(t1, "list") == 0) {
				list(t2[0], t3);
			} else {
				printf("%s is invalid commnad.\n\n", t1);
			}
		} else {
			printf("please enter command in this form(list f/i dirname).");
		}
	}
	
	return 0;
}

