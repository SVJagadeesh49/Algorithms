#include<bits/stdc++.h>

using namespace std;

void Bin_Coff_modified(int n,int k){
	int c[k+1];
	memset(c,0,sizeof(c));

	c[0] = 1;

	for(int i=0;i<=n;i++){
		for(int j=std::min(i,k);j>0;j--){ // k must be less than or equal to n so j must be less than or equal to i
        	
        	c[j] = c[j] + c[j-1];
		}
	}

   cout<<c[k]<<endl;

}
void Bin_Coff(int n,int k){
	int c[n+1][k+1];

	for(int i=0;i<=n;i++){
		for(int j=0;j<=std::min(i,k);j++){
        		// k must be less than or equal to n so j must be less than or equal to i
            if(j==0||j==i){
            	c[i][j] = 1;
            }
            else{
            	c[i][j] = c[i-1][j] + c[i-1][j-1]; //(n)c(k) = (n-1)c(k-1) + (n-1)c(k)
            }
		} 
	}

	cout<<c[n][k]<<endl;
}

int main(){
	
	cout<<"Enter n and k :"<<endl;
	int n,k;
	cin >> n;
	cin >> k;

	Bin_Coff(n,k); // Time Complexity = O(n*k) and Auxilary space = O(n*k)
	Bin_Coff_modified(n,k); // Time Complexity = O(n*k) and Auxilary space = O(k)
}