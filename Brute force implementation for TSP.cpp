#include <bits/stdc++.h>
using namespace std;

int travellingSalesmanProblem(int **graph, int s,int V)
{
	vector<int> path;
	vector<int> vertex;
	for (int i = 0; i < V; i++)
    	if (i != s)
        	vertex.push_back(i);

	int min_path = INT_MAX;
	do {
    	int current_pathweight = 0;

    	int k = s;
    	for (int i = 0; i < vertex.size(); i++) {
        	current_pathweight += graph[k][vertex[i]];
        	k = vertex[i];
    	}
    	current_pathweight += graph[k][s];

    	if(min_path > current_pathweight)
    	{
        	while(!path.empty())
        	{path.pop_back();}
        	k = s;
      	for (int i = 0; i < vertex.size()+1; i++)
      	{
          	path.push_back(k);
          	k = vertex[i];
      	}
    	}
    	min_path = min(min_path, current_pathweight);
  } 
while (next_permutation(vertex.begin(), vertex.end()));
cout << "The shortest tour is ";
for (int i = 0; i < vertex.size()+1; i++)
      	{
          cout << path[i]+1 << "->";  }
        	cout << s+1 <<endl;
    	cout <<	"The length of the shortest tour is : " ;
	return min_path;
}

int main()
{
	int no_of_cities;
	cout << "Enter the number of cities - ";
	cin >> no_of_cities;
    int **graph;
	graph = new int*[no_of_cities];
	for(int i=0;i<no_of_cities;i++)
	{
    	graph[i] = new int[no_of_cities];
	}
     for(int i=0;i<no_of_cities;i++)
	{
    	graph[i][i] = 0;
    	for(int j=i+1;j<no_of_cities;j++){
    	cout << "Enter the distance from city " << i+1 << " to " << j+1 << ": " ;
    	cin >> graph[i][j];
    	graph[j][i] = graph[i][j];   }
	}
cout << endl;
	int s = 0;
	cout <<  travellingSalesmanProblem(graph, s,no_of_cities) << endl;
	return 0;
}
