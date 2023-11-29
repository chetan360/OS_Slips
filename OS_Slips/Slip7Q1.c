#include <stdio.h>

int OPT(int future[], int fsize) {
	int max=future[0], pos=0;
	
	for(int i=0; i<fsize; i++) {
		if(future[i] > max) {
			max = future[i];
			pos = i;
		}
	}
	
	return pos;
}

int main() {
	int rs[100], frame[20], future[20];
	int n, fsize, flag1, flag2, flag3, pf=0, hit=0, pos;
	
	printf("How many pages : ");
	scanf("%d", &n);
	
	printf("Enter reference string : ");
	for(int i=0; i<n; i++) {
		scanf("%d", &rs[i]);
	}
	
	printf("How many frame : ");
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
					frame[j] = rs[i];
					flag2 = 1;
					break;
				}
			}	
		}
		
		if(flag2 == 0) {
			flag3 = 0;
			for(int j=0; j<fsize; j++) {
				future[j] = -1;
				for(int k=i+1; k<n; k++) {
					if(frame[j] == rs[k]) {
						future[j] = k;
						break;
					}
				}
			}
			
			for(int j=0; j<fsize; j++) {
				if(future[j] == -1) {
					pos = j;
					flag3 = 1;
					break;
				}
			}
			
			if(flag3 == 0) {
				pos = OPT(future, fsize);
			}
			pf++;
			frame[pos] = rs[i];
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
