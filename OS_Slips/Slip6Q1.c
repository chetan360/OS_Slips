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
	
	printf("Enter no. of frame : ");
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
			}
		}
		
		if(flag1 == 0) {
			for(int j=0; j<fsize; j++) {
				if(frame[j] == -1) {
					frame[j] = rs[i];
					time[j] = i+1;
					flag2 = 1;
					pf++;
					break;
				}
			}
		}
		
		if(flag2 == 0) {
			//find lru pos using min timestamp
			int pos = LRU(time, fsize);
			frame[pos] = rs[i];
			time[pos] = i+1;
			pf++;
		}
		
		for(int j=0; j<fsize; j++) {
			printf("%d\t", frame[j]);
		}
		printf("\n");
	}
	
	printf("\nno. of page faults = %d\n", pf);
	printf("no. of page hits = %d\n", hit);
	
	return 0;
}

