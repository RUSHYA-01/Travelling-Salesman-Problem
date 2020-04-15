#include<iostream>
using namespace std;

#define INT_MAX 999999

int n=4;
int dist[4][4] = {
    	{0,10,15,20},
    	{10,0,35,25},
    	{15,35,0,30},
    	{20,25,30,0}
};
int VISITED_ALL = (1<<n) -1;

int dp[16][4];


int  tsp(int mask,int pos){

    if(mask==VISITED_ALL){
   	 return dist[pos][0];
    }
    if(dp[mask][pos]!=-1){
   	return dp[mask][pos];
    }

    int ans = INT_MAX;

    for(int city=0;city<n;city++){

   	 if((mask&(1<<city))==0){

   		 int newAns = dist[pos][city] + tsp( mask|(1<<city), city);
   		 ans = min(ans, newAns);
   	 }

    }

    return dp[mask][pos] = ans;
}

int main(){
	for(int i=0;i<(1<<n);i++){
    	for(int j=0;j<n;j++){
        	dp[i][j] = -1;
    	}
	}
    cout<<"Travelling Saleman Distance is "<<tsp(1,0) << endl << endl << endl << endl;

return 0;
}
