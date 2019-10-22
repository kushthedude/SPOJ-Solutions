#include<bits/stdc++.h> 
using namespace std; 
int v[100][6]; 
 

void arrival(int n, int v[][6]) 
{ 
	for(int i=0; i<n; i++) 
	{ 
		for(int j=0; j<n-i-1; j++) 
		{ 
			if(v[j][1] > v[j+1][1]) 
			{ 
				for(int k=0; k<5; k++) 
				{ 
					swap(v[j][k], v[j+1][k]); 
				} 
			} 
		} 
	} 
} 

void comp(int n, int v[][6]) 
{ 
	int temp, val; 
	v[0][3] = v[0][1] + v[0][2]; 
	v[0][5] = v[0][3] - v[0][1]; 
	v[0][4] = v[0][5] - v[0][2]; 
	
	for(int i=1; i<n; i++) 
	{ 
		temp = v[i-1][3]; 
		int low = v[i][2]; 
		for(int j=i; j<n; j++) 
		{ 
			if(temp >= v[j][1] && low >= v[j][2]) 
			{ 
				low = v[j][2]; 
				val = j; 
			} 
		} 
		v[val][3] = temp + v[val][2]; 
		v[val][5] = v[val][3] - v[val][1]; 
		v[val][4] = v[val][5] - v[val][2]; 
		for(int k=0; k<6; k++) 
		{ 
			swap(v[val][k], v[i][k]); 
		} 
	} 
} 

int main() 
{ 
	int n; 
	
	cout<<"Enter the number of Process"; 
	cin>>n; 
	
	cout<<"--------------------Enter processes in fashion arrival time and burst time--------------------\n"; 
	for(int i=0; i<n; i++) 
	{  
		v[i][0]=i+1;
		cin>>v[i][1]; 
		cin>>v[i][2]; 
	} 
	
	cout<<"-----------------current input----------\n"; 
	cout<<"Process ID\tArrival Time\tBurst Time\n"; 
	for(int i=0; i<n; i++) 
	{ 
		cout<<v[i][0]<<"\t\t"<<v[i][1]<<"\t\t"<<v[i][2]<<"\n"; 
	} 
	
	arrival(n, v); 
	comp(n, v); 
	cout<<"Final Result...\n"; 
	cout<<"Process ID\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n"; 
	for(int i=0; i<n; i++) 
	{ 
		cout<<v[i][0]<<"\t\t"<<v[i][1]<<"\t\t"<<v[i][2]<<"\t\t"<<v[i][4]<<"\t\t"<<v[i][5]<<"\n"; 
	} 
}
