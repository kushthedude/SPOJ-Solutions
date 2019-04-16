#include<stdio.h>
#include<vector>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	int t;
	scanf("%i", &t);
	while(t-->0){
		int n, m, x;
		scanf("%i", &n);
		vector<vector<int> > graph(n);
		for(int i=1; i<n; i++){
			scanf("%i", &m);
			for(int j=0; j<m; j++){
				scanf("%i", &x);
				graph[i].push_back(x);
			}
			sort(graph[i].begin(), graph[i].end());
		}
		bool visited[n+1];
		int path[n+1];
		for(int i=0; i<=n; i++){
			visited[i]=false;
			path[i]=0;
		}
		bool flag=false;
		visited[1]=true;
		queue<int> bfsQueue;
		bfsQueue.push(1);
		while(bfsQueue.empty()==false){
			int u=bfsQueue.front();
			bfsQueue.pop();
			if(u==n){
				flag=true;
				break;
			}
			for(int i=0; i<graph[u].size(); i++){
				if(visited[graph[u][i]]==false){
					visited[graph[u][i]]=true;
					path[graph[u][i]]=u;
					bfsQueue.push(graph[u][i]);
				}
			}
		}
		if(flag){
			x=path[n];
			vector<int> ans;
			while(x!=1){
				ans.push_back(x);
				x=path[x];
			}
			ans.push_back(1);
			printf("%lu\n", ans.size());
			for(int i=ans.size()-1; i>=0; i--){
				printf("%i ", ans[i]);
			}
		}
		else
			printf("-1");
		printf("\n");

	}

	return 0;
}



