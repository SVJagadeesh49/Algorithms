#include<bits/stdc++.h>

using namespace std;

void Knapsack(int W,int wt[],int val[],int n){

	int Kn[n+1][W+1];

	for(int i=0;i<=n;i++){
		for(int w=0;w<=W;w++){

			if(i==0||w==0){
				Kn[i][w] = 0;
			}
			else if(wt[i-1]<=w){
				Kn[i][w] = std::max(val[i-1]+Kn[i-1][w-wt[i-1]],Kn[i-1][w]);
			}

			else{
				Kn[i][w] = Kn[i-1][w];
			}
		}
	}

	cout << Kn[n][W]<<endl;
}

int main(){
	
	int n;
	cout<<"No.of items available :"<<endl;

	cin >> n;

	int wt[n],val[n];

	cout<<"Enter weights of the items : "<<endl;

	for(int i=0;i<n;i++){
		cin >> wt[i];
	}

	cout<<"Enter values of the items : "<<endl;

	for(int i=0;i<n;i++){
		cin >> val[i];
	}

	cout<<"Enter the Max weigth :"<<endl;
	int W;
	cin >> W;

	Knapsack(W,wt,val,n);

}