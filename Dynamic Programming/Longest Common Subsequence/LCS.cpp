#include<bits/stdc++.h>

using namespace std;

int LCS(string x,string y){
  int n = x.length();
  int m = y.length();
  int lcs[n+1][m+1];

  
  for(int i=0;i<=n;i++){
  	for(int j=0;j<=m;j++){
  		if(i==0||j==0)
  			lcs[i][j] = 0;
  		else if(x[i-1]==y[j-1]){
  			lcs[i][j] = lcs[i-1][j-1] + 1;
  		}
  		else{
  			if(lcs[i-1][j]>lcs[i][j-1])
  				lcs[i][j] = lcs[i-1][j];
  			else
  				lcs[i][j] = lcs[i][j-1];
  		}
  	}
  }
  cout<<lcs[n][m]<<endl;

int k = lcs[n][m];
char substr[k];
int i=n,j=m;

while(i>0&&j>0){
    if(x[i-1]==y[j-1]){
        substr[k-1]=x[i-1];
        k--;i--;j--;
    }
    else{
        if(lcs[i-1][j]>lcs[i][j-1]){
            i--;
        }
        else{
            j--;
        }
    }
}

for(int i=0;i<lcs[n][m];i++) cout<<substr[i];
	
}

int main(){
	string x,y;
	cin >> x;
	cin >> y;

	LCS(x,y);
}