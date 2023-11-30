#include <stdio.h>

int main() {
	int  rs[100], frame[20];
	int n, fsize, rr=0, flag1, flag2, pf=0, hit=0;

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
	}
	
	for(int i=0; i<n; i++) {
		flag1 = flag2 = 0;
		for(int j=0; j<fsize; j++) {
			if(frame[j] == rs[i]) {
				hit++;
				flag1 = flag2 = 1;
				break;
			}
		}
		
		if(flag1 == 0) {
			for(int j=0; j<fsize; j++) {
				if(frame[j] == -1) {
					pf++;
					flag2 = 1;
					frame[j] = rs[i];
					break;
				}
			}
		}
		
		if(flag2 == 0) {
			frame[rr] = rs[i];
			rr = (rr+1) % fsize;
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

