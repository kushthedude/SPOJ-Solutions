#include<bits/stdc++.h> 
using namespace std; 
void wtt(vector<int> proc,int wt[], int quantum) 
{ 
	int n=proc.size();
	int rem[n]; 
	for (int i = 0 ; i < n ; i++) 
		rem[i] = proc[i]; 

	int t = 0; 
	while (true) 
	{ 
		bool done=true; 
		for (int i=0;i<n;i++) 
		{ 
			if(rem[i]>0) 
			{ 
				done = false;
				if (rem[i] > quantum) 
				{
					t+=quantum; 
					rem[i]-=quantum;
				} 
				else
				{ 
					t=t+rem[i]; 
					wt[i]=t-proc[i]; 
					rem[i]=0; 
				} 
			} 
		} 
		if (done == true) 
		break; 
	} 
} 
void tatt(vector<int> proc, int wt[], int tat[]) 
{ 
	for (int i = 0; i < proc.size() ; i++) 
		tat[i] = proc[i] + wt[i]; 
} 

void avgTime(vector<int> &proc,int quantum) 
{ 
	int n=proc.size();
	int wt[n], tat[n], total_wt = 0, total_tat = 0; 
	wtt(proc,wt, quantum); 
	tatt(proc,wt, tat); 
	cout << "Processes "<< " Burst time "
		<< " Waiting time " << " Turn around time\n"; 

	for (int i=0; i<n; i++) 
	{ 
		total_wt = total_wt + wt[i]; 
		total_tat = total_tat + tat[i]; 
		cout << " " << i+1 << "\t\t" << proc[i] <<"\t "
			<< wt[i] <<"\t\t " << tat[i] <<endl; 
	} 

	cout << "Average waiting time = "
		<< (float)total_wt / (float)n; 
	cout << "\nAverage turn around time = "
		<< (float)total_tat / (float)n; 
} 
int main() 
{
	cout<<"please enter the number of processes"<<endl;int n;cin>>n;
	cout<<"please enter the burtst time of processes"<<endl;
	vector<int> proc; 
	for(int i=0;i<n;i++){int temp;cin>>temp;proc.push_back(temp);}
 	cout<<"enter the quantum"<<endl;
	int quantum;
	cin>>quantum; 
	avgTime(proc,quantum); 
	return 0; 
} 

