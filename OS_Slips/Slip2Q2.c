#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <dirent.h>
#include <sys/types.h>
#include <unistd.h>

void list(char choise, char *dirname) {
	DIR *dir;
	int dirCnt=0;
	
	struct dirent *entry;
	
	if((dir = opendir(dirname)) == NULL) {
		printf("Directory(folder) %s not found.\n\n", dirname);
		return;
	}
	
	switch(choise) {
		case 'f':
			//reading files from given dir
			while((entry = readdir(dir)) != NULL) {
				//skip '.'(curent dir)
				//skip '..'(parent dir)
				if(strcmp(entry->d_name, ".") == 0 ||
				strcmp(entry->d_name, "..") == 0) {
					continue;
				}
				printf("%s\n", entry->d_name);
			}
			printf("\n");
			break;
		case 'n':
			while((entry = readdir(dir)) != NULL) {
				//skip '.'(curent dir)
				//skip '..'(parent dir)
				if(strcmp(entry->d_name, ".") == 0 ||
				strcmp(entry->d_name, "..") == 0) {
					continue;
				}
				dirCnt++;
			}
			printf("no. of entris = %d\n\n", dirCnt);
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
			if(strcmp(t1, "list") == 0) {
				list(t2[0], t3);
			} else {
				printf("%s is invalid command.\n\n", t1);
			}
		} else {
			printf("please enter command in this format.(list f/n dirname)\n\n");
		}
	}

	return 0;
}

