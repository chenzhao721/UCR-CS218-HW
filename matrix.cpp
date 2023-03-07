#include <iostream>
#include <vector>
#include <numeric>      // std::iota
#include <algorithm>    // std::sort, std::stable_sort

using namespace std;
  int **matrix;
  int **s;
  int output=0;


void maxidentitymatrix(int i, int j){
	int k;
	int iter;
	bool flag=0;

    if(matrix[i][j]==0){
		s[i][j]=0;
	}
	else if(matrix[i-1][j-1]==1){
		k = s[i-1][j-1];
		for(iter=1;iter<=k;iter++){
			if(matrix[i-iter][j]!=0){
				flag=1;
				break;
			}
			if(matrix[i][j-iter]!=0){
				flag=1;
				break;
			}
		}
		if(flag==1){
			s[i][j]=1;
		}
		else{
			s[i][j]=s[i-1][j-1]+1;
		}
	}
	else{
		s[i][j]=1;
	}

	if(s[i][j]>output)
		output = s[i][j];

}

int main ()
{
 
  int i,j;
  int n;
  
  scanf("%d", &n);
  matrix = new int*[n];
  s = new int*[n];
  
 

  for (i=0; i<n; i++)
  {
      matrix[i] = new int[n];
	  s[i] = new int[n];
  }

  

  for (i=0; i<n; i++)
  {
	  for (j=0; j<n; j++)
	  {
		  scanf("%d", &matrix[i][j]);
		  if(i==0 || j==0 ){
			  s[i][j] = matrix[i][j];
			  if(s[i][j]==1){
				  output = 1;
			  }
		  }

	  }
  }

  

   for (i=1; i<n; i++)
  {
	  for (j=1; j<n; j++)
	  {
		  maxidentitymatrix(i,j);

	  }
  }

  
   cout << output;
  return 0;
}