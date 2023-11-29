#include <stdio.h>

int MRU(int time[], int fsize) {
	int max=time[0], pos=0;
	for(int j=1; j<fsize; j++) {
		if(time[j] > max) {
			max = time[j];
			pos = j;
		}			
	}
	
	return pos;
}

int main() {
	int rs[100], frame[20], time[20];
	int n, fsize, flag1, flag2, pf=0, hit=0, pos;
	
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
		time[0];
	}
	
	for(int i=0; i<n; i++) {
		flag1 = flag2 = 0;
		for(int j=0; j<fsize; j++) {
			if(frame[j] == rs[i]) {
				hit++;
				flag1 = flag2 = 1;
				time[j] = i+1;
				break;
			}
		}
		
		if(flag1 == 0) {
			for(int j=0; j<fsize; j++) {
				if(frame[j] == -1) {
					pf++;
					flag2 = 1;
					time[j] = i+1;
					frame[j] = rs[i];
					break;
				}
			}	
		}
		
		if(flag2 == 0) {
			pos = MRU(time, fsize);
			frame[pos] = rs[i];
			time[pos] = i+1;
			pf++;
		}
		printf("\n");
		
		for(int j=0; j<fsize; j++) {
			printf("%d\t", frame[j]);
		}
	}
	
	printf("\n\nNo. of page faults = %d\n", pf);
	printf("No. of page hits = %d\n", hit);
	
	return 0;
}

