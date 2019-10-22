#include <bits/stdc++.h> 
using namespace std;  


struct process 
{ 
	int at,bt,pr,pno; 
};

 
bool comp(process a,process b) 
{
	return(a.at==b.at?a.pr<b.pr:a.at<b.at);
} 



void findgc(vector<process> proc) 
{ 
	vector<int> wt,tat; 
	int n=proc.size();
	double wavg=0,tavg=0; 
	int service[400];//getting wt 
	service[0]=0; 
	wt.push_back(0);
	for(int i=1;i<n;i++) 
	{ 
		service[i]=proc[i-1].bt+service[i-1]; 
		wt[i]=service[i]-proc[i].at+1; 
		if(wt[i]<0) 
		wt[i]=0; 
	} 
		

	for(int i=0;i<n;i++)//getting tat 
	{ 
		tat.push_back(proc[i].bt+wt[i]); 
	}
	
	
	int stime[400],ctime[400]; 
	stime[0]=1; 
	ctime[0]=stime[0]+tat[0]; 
	for(int i=1;i<n;i++) 
	{ 
		stime[i]=ctime[i-1]; 
		ctime[i]=stime[i]+tat[i]-wt[i]; 
	} 
	
	cout<<"Process_no\tStart_time\tComplete_time\tTurn_Around_Time\tWaiting_Time"<<endl; 
	
	
	for(int i=0;i<n;i++) 
	{ 
		wavg += wt[i]; 
		tavg += tat[i]; 
		
		cout<<proc[i].pno<<"\t\t"<< 
			stime[i]<<"\t\t"<<ctime[i]<<"\t\t"<< 
			tat[i]<<"\t\t\t"<<wt[i]<<endl; 
	} 
	
	
	cout<<"Average waiting time is : "<<wavg/(float)n<<endl;
	cout<<"average turnaround time : "<<tavg/(float)n<<endl;
} 

int main() 
{ 	
	vector<int> at,bt,p;  
	vector<process> proc;
	cout<<"please enter the number of processes"<<endl;
	int n;
	cin>>n;cout<<"please enter the processes arrival time ,burst time ,priority"<<endl; 
	for(int i=0;i<n;i++) 
	{ 

		process temp;	
		cin>>temp.at;			
		cin>>temp.bt;
		cin>>temp.pr; 
		temp.pno=i+1; 
		proc.push_back(temp);
	} 
	sort(proc.begin(),proc.end(),comp); 
	findgc(proc); 
	return 0; 
} 

