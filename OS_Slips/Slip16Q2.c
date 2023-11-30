#include <stdio.h>
#include <string.h>

struct process {
	int prio, pid, at, bt, ct, tat, wt;
};

int main() {
	struct process p[100];
	int n, mark[100];
	memset(mark, 0, sizeof(mark));
	int tTat=0, tWt=0;
	float aTat, aWt;
	
	printf("How many process : ");
	scanf("%d", &n);
	
	printf("Enter AT and BT of %d process :\n", n);
	for(int i=0; i<n; i++) {
		printf("AT : ");
		scanf("%d", &p[i].at);
		printf("BT : ");
		scanf("%d", &p[i].bt);
		printf("\n");
		p[i].pid = i+1;
	}
	
	int currTime=0, completed=0;
	
	printf("Glantt Chart :\n");
	
	while(completed != n) {
		int idx = -1;
		
		for(int i=0; i<n; i++) {
			if(p[i].at <= currTime && mark[i] == 0) {
				idx = i;
			}
		}
		
		if(idx != -1) {
			printf("P%d | ", p[idx].pid);
			p[idx].ct = currTime + p[idx].bt;
			p[idx].tat = p[idx].ct - p[idx].at;
			p[idx].wt = p[idx].tat - p[idx].bt;
			
			tTat += p[idx].tat;
			tWt += p[idx].wt;
			mark[idx] = 1;
			
			currTime = p[idx].ct;
			completed++;
		} else {
			currTime++;
		}
	}
	
	aTat = (float)tTat/n;
	aWt = (float)tWt/n;
	
	printf("\n\nPID\tAT\tBT\tCT\tTAT\tWT\n\n");
	for(int i=0; i<n; i++) {
		printf("%d\t%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);
	}
	
	printf("\nAverage TAT = %.2f", aTat);
	printf("\nAverage WT = %.2f\n", aWt);
	
	return 0;
}

