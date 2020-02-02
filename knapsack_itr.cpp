#include<iostream>
using namespace std;

void knapsack(int* wt, int* val, int n, int W){
	
   int i, w; 
   int K[n+10][W+10]; 
  
   for (i = 0; i <= n; i++) 
   { 
       for (w = 0; w <= W; w++) 
       { 
           if (i==0 || w==0) 
               K[i][w] = 0; 
           else if (wt[i-1] <= w) 
           {		   
                K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]],  K[i-1][w]);
                 
		   }
           else
                K[i][w] = K[i-1][w]; 
       } 
   } 
   
   	int maxfun=K[n][W]; //value
	int minmoney=0;
	for(i=0;i<=W;i++)
	{
		if(K[n][i]==maxfun)
		{
			minmoney=i;  //finding out weight
			break;
		}
	}
   cout<<minmoney<<" "<<K[n][W]<<endl;
}

int main(){

	while(true)
	{
  int maxWeight;
  cin >> maxWeight;
  
  int n; 
  cin >> n;
  if(maxWeight==0 && n==0)
  break;
  int* weights = new int[n];
  int* values = new int[n];

  for(int i = 0; i < n; i++){

    cin >> weights[i];
    cin >> values[i];
   }

knapsack(weights, values, n, maxWeight);
}
}



