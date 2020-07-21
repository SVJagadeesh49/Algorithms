#include<bits/stdc++.h>

using namespace std;

void edit_distance(string x,string y){
	int n = x.length();
	int m = y.length();

	int ans[n+1][m+1];
	for(int i=0;i<=n;i++){
		for(int j=0;j<=m;j++){
			if(i==0){
			   ans[i][j] = j;
			}
			else if(j==0){
				ans[i][j] = i;
			}
			else if(x[i-1]==y[j-1]){
				ans[i][j] = ans[i-1][j-1];
			}
			else{
				ans[i][j] = std::min(std::min(ans[i-1][j-1],ans[i-1][j]),ans[i][j-1]) + 1;
			}
		}
	}

	for(int i=0;i<=n;i++){
		for(int j=0;j<=m;j++){
			cout<< ans[i][j] << " ";
		}
		cout<<endl;
	}

	cout<<ans[n][m]<<endl;
}

int main(){
	string x,y;
	cin>>x;
	cin>>y;

	edit_distance(x,y);
}