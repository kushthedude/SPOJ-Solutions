#include <bits/stdc++.h> 
using namespace std; 

struct process { 
	int bt;  
	int at;  
}; 

void wtt(vector<process> proc,int wt[]) 
{
	int n=proc.size(); 
	int rt[n]; 
	for (int i = 0; i < n; i++) 
		rt[i] = proc[i].bt; 

	int complete = 0, t = 0, minm = INT_MAX; 
	int shortest = 0, finish_time; 
	bool check = false; 

	while (complete != n) 
	{ 
		for (int j = 0; j < n; j++) 
		{ 
			if ((proc[j].at <= t) && (rt[j] < minm) && rt[j] > 0) 
			{ 
				minm = rt[j]; 
				shortest = j; 
				check = true; 
			} 
		} 

		if (check == false) { 
			t++; 
			continue; 
		} 
		rt[shortest]--; 
		minm = rt[shortest]; 
		if (minm == 0) 
			minm = INT_MAX; 
		if (rt[shortest] == 0) { 
			complete++; 
			check = false; 
			finish_time = t + 1; 
			wt[shortest] = finish_time - 
						proc[shortest].bt - 
						proc[shortest].at; 

			if (wt[shortest] < 0) 
				wt[shortest] = 0; 
		} 
		t++; 
	} 
} 

void tatt(vector<process> proc,int wt[], int tat[]) 
{ 
	for (int i = 0; i < proc.size(); i++) 
		tat[i] = proc[i].bt + wt[i]; 
} 
void avg(vector<process> proc) 
{ 
	int n=proc.size();
	int wt[n], tat[n], total_wt = 0, total_tat = 0; 
	
	wtt(proc,wt); 

	tatt(proc,wt, tat); 

	cout << "Processes "
		<< " Burst time "
		<< " Waiting time "
		<< " Turn around time\n"; 

	for (int i = 0; i < n; i++) { 
		total_wt = total_wt + wt[i]; 
		total_tat = total_tat + tat[i]; 
		cout << " " << i << "\t\t"
			<< proc[i].bt << "\t\t " << wt[i] 
			<< "\t\t " << tat[i] << endl; 
	} 

	cout << "\nAverage waiting time ="<< (float)total_wt / (float)n; 
	cout << "\nAverage turn around time = "<< (float)total_tat / (float)n; 
} 

int main() 
{ 
	
        vector<process> proc;
        cout<<"please enter the number of processes"<<endl;
        int n;
        cin>>n;cout<<"please enter the processes arrival time ,burst time"<<endl;
        for(int i=0;i<n;i++)
        {

                process temp;
                cin>>temp.at;
                cin>>temp.bt;
                proc.push_back(temp);
        }

	avg(proc); 
	return 0; 
}
