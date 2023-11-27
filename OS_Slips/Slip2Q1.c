#include <stdio.h>

int main() {
	int rs[100], frame[20];
	int n, fsize, flag1, flag2, pf=0, hit=0, rr=0;
	
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
				//page is allready in frame
				hit++;//increase no. of hits
				flag1 = flag2 = 1;
				break;
			}
		}
		
		if(flag1 == 0) {
			for(int j=0; j<fsize; j++) {
				//check frame is empty
				if(frame[j] == -1) {
					//then add to frame
					frame[j] = rs[i];
					pf++;
					flag2 = 1;
					break;
				}
			}
			
		}
		
		if(flag2 == 0) {
			frame[rr] = rs[i];//adding at rear end sequentialy
			rr = (rr+1) % fsize;//circular queue indexing for frame arr
			pf++;
		}
		printf("\n");
		
		//printing frames at each iteration
		for(int j=0; j<fsize; j++) {
			printf("%d\t", frame[j]);
		}
	}
	
	printf("\n\nno. of page faults = %d\n", pf);
	printf("no. of page hits = %d\n", hit);
	
	return 0;
}

