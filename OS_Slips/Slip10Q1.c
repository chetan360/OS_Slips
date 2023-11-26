#include <stdio.h>

int LRU(int time[], int fsize) {
	int min=time[0], pos=0;
	for(int i=1; i<fsize; i++) {
		if(time[i] < min) {
			min = time[i];
			pos = i;
		}
	}
	
	return pos;
}

int main() {
	int rs[100], time[20], frame[20];
	int n, fsize, flag1, flag2, pf=0, hit=0;
	
	printf("How many pages : ");
	scanf("%d", &n);
	
	printf("Enter reference string : ");
	for(int i=0; i<n; i++) {
		scanf("%d", &rs[i]);
	}
	
	printf("How many frames : ");
	scanf("%d", &fsize);
	for(int i=0; i<fsize; i++) {
		frame[i] = -1;
		time[i] = 0;
	}
	
	for(int i=0; i<n; i++) {
		flag1 = flag2 = 0;
		for(int j=0; j<fsize; j++) {
			if(frame[j] == rs[i]) {
				hit++;
				time[j] = i+1;
				flag1 = flag2 = 1;
				break;
			}
		}
		
		if(flag1 == 0) {
			for(int j=0; j<fsize; j++) {
				//check frame is empty
				if(frame[j] == -1) {
					frame[j] = rs[i];
					pf++;
					flag2 = 1;
					time[j] = i+1;
					break;
				}
			}
		}
		
		if(flag2 == 0) {
			//find least reselently used position 
			int pos = LRU(time, fsize);
			frame[pos] = rs[i];
			pf++;
			time[pos] = i+1;
		}
		printf("\n");
		
		for(int j=0; j<fsize; j++) {
			printf("%d\t", frame[j]);
		}
	}
	
	printf("\nno. of page faults = %d\n", pf);
	printf("no. of page hits = %d\n", hit);
	
	return 0;
}

