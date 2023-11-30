#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct process {
	int pid, at, bt, ct, tat, wt; 
};

int compare1(const void *a, const void *b) {
	return ((struct process *)a)->at - ((struct process *)b)->at;
}

int compare2(const void *a, const void *b) {
	return ((struct process *)a)->pid - ((struct process *)b)->pid;
}

int main() {
	int n, tq, idx;
	struct process p[100];
	int tTat=0, tWt=0;
	float aTat, aWt;
	int bRem[100], mark[100];
	memset(mark, 0, sizeof(mark));
	
	printf("How many process : ");
	scanf("%d", &n);
	
	printf("Enter time quantum : ");
	scanf("%d", &tq);
	
	printf("Enter arrival time and Burst time of %d processes :\n", n);
	for(int i=0; i<n; i++) {
		printf("AT: ");
		scanf("%d", &p[i].at);
		printf("BT: ");
		scanf("%d", &p[i].bt);
		printf("\n");
		p[i].pid = i+1;
		bRem[i] = p[i].bt;
	}
	
	qsort(p, n, sizeof(struct process), compare1);
	
	int queue[100];
	int fr=-1, rr=-1;
	queue[++rr] = 0;
	int currTime=0;
	mark[0] = 1;
	int completed = 0;
	
	printf("Gantt Chart :\n");
	while(completed != n) {
		idx = queue[++fr];
		
		if(bRem[idx] == p[idx].bt) {
			currTime = (currTime > p[idx].at)? currTime: p[idx].at;
		}
		
		if(bRem[idx] - tq > 0) {
			bRem[idx] -= tq;
			currTime += tq;
			printf("P%d | ", p[idx].pid);	
		} else {
			currTime += bRem[idx];
			bRem[idx] = 0;
			completed++;
			printf("P%d | ", p[idx].pid);
			
			p[idx].ct = currTime;
			p[idx].tat = p[idx].ct - p[idx].at;
			p[idx].wt = p[idx].tat - p[idx].bt;
			
			tTat += p[idx].tat;
			tWt += p[idx].wt;
		}
		
		for(int i=1; i<n; i++) {
			if(bRem[i] > 0 && p[i].at <= currTime && mark[i] == 0) {
				queue[++rr] = i;
				mark[i] = 1;
			}
		}
		
		if(bRem[idx] > 0) {
			queue[++rr] = idx;
		}
		
		if(fr == rr) {
			for(int i=1; i<n; i++) {
				if(bRem[i] > 0) {
					queue[++rr] = i;
					mark[i] = 1;
					break;
				}
			}	
		}
	}
	
	aTat = (float)tTat/n;
	aWt = (float)tWt/n;
	
	qsort(p, n, sizeof(struct process), compare2);
	
	printf("\n\nPID\tAT\tBT\tCT\tTAT\tWT\n\n");
	for(int i=0; i<n; i++) {
		printf("%d\t%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);
	}

	printf("\nAvrage TAT = %.2f", aTat);
	printf("\nAvrage WT = %.2f\n", aWt);

	return 0;
}

