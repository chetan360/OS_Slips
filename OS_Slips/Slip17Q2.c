#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
	int n;
	int tq;
	struct process p[100];
	float avgTat;
	float avgWt;
	int totalTat=0;
	int totalWt=0;
	int idx;
	int btRem[100];
	int mark[100];
	
	//initializing mark with zeros
	memset(mark, 0, sizeof(mark));
	
	printf("Enter no. of process : ");
	scanf("%d", &n);
	
	printf("Enter time quantum : ");
	scanf("%d", &tq);
	
	printf("Enter arival time and burst time of %d processes : \n", n);
	for(int i=0; i<n; i++) {
		printf("AT : ");
		scanf("%d", &p[i].at);
		printf("BT : ");
		scanf("%d", &p[i].bt);
		printf("\n");
		btRem[i] = p[i].bt;
		p[i].pid = i+1;
	}
	
	//sorting by arival time
	qsort(p, n, sizeof(struct process), compare1);
	
	int queue[100];
	int fr = -1, rr = -1;
	queue[++rr] = 0;
	int currTime = 0;
	mark[0] = 1;
	int completed = 0;
	
	printf("Gantt Chart :\n");
	while(completed != n) {
		idx = queue[++fr];
		
		if(btRem[idx] == p[idx].bt) {
			currTime = (currTime > p[idx].at)? currTime : p[idx].at; 
		}
		
		if(btRem[idx] - tq > 0) {
			btRem[idx] -= tq;
			currTime += tq;
			printf("P%d | ", p[idx].pid);		
		} else {
			currTime += btRem[idx];
			btRem[idx] = 0;
			completed++;
			printf("P%d | ", p[idx].pid);
			
			p[idx].ct = currTime;
			p[idx].tat = p[idx].ct - p[idx].at;
			p[idx].wt = p[idx].tat - p[idx].bt;
			
			totalTat += p[idx].tat;
			totalWt += p[idx].wt;
		}
		
		for(int i=1; i<n; i++) {
			if(btRem[i] > 0 && p[i].at <= currTime && mark[i] == 0) {
				queue[++rr] = i;
				mark[i] = 1;
			}
		}
		
		if(btRem[idx] > 0) {
			queue[++rr] = idx;
		}
		
		if(fr == rr) {
			for(int i=1; i<n; i++) {
				if(btRem[i] > 0) {
					queue[++rr] = i;
					mark[i] = 1;
					break;
				}
			}
		}
	} 
	
	avgTat = (float)totalTat / n;
	avgWt = (float)totalWt / n;
	
	//sort by process id
	qsort(p, n, sizeof(struct process), compare2);
	
	printf("\n\nPID\tAT\tBT\tCT\tTAT\tWT\n");
	for(int i=0; i<n; i++) {
		printf("%d\t%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);
	}
	
	printf("\nAvg. TAT = %.2f\n", avgTat);
	printf("Avg. WT = %.2f\n", avgWt);
	
	return 0;	 
}

