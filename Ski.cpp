#include <iostream>
#include <vector>
#include <numeric>      // std::iota
#include <algorithm>    // std::sort, std::stable_sort

using namespace std;
  int **h;
  int **s ;
  int output=1;
  int r,c;
  int *array;
  
 
  
  int max(int i, int j){
	  if(i>j) return i;
	  else return j;
  }



int ski(int i, int j){
	if(s[i][j]!=-1) return s[i][j];
	if(i==0 || j==0 || i==r+1 || j==c+1) return 0;
	int best=1;

	if(h[i][j]>h[i-1][j]){
		best = max(best,ski(i-1,j)+1);
	}

	if(h[i][j]>h[i][j-1]){
		best = max(best,ski(i,j-1)+1);
	}

	if(h[i][j]>h[i+1][j]){
		best = max(best,ski(i+1,j)+1);
	}

	if(h[i][j]>h[i][j+1]){
		best = max(best,ski(i,j+1)+1);
	}

	s[i][j]=best;

	if(best>output)
		output = best;

	return best;

}
int main ()
{
 
  int i,j,k;
  int min;
  int mini,minj;
  
  cin >> r;
  cin >> c;
  h = new int*[r+2];
  s = new int*[r+2];
  array = new int[r*c];
  
 

  for (i=0; i<=r+1; i++)
  {
      h[i] = new int[c+2];
	  s[i] = new int[c+2];
  }

  for (i=0; i<=r+1; i++)
  {
	  for (j=0; j<=c+1; j++)
	  {
		  h[i][j]=0;
	  }
  }

  

  for (i=1; i<=r; i++)
  {
	  for (j=1; j<=c; j++)
	  {
		  cin >> h[i][j];

	  }
  }

  for (i=0; i<=r+1; i++)
  {
	  for (j=0; j<=c+1; j++)
	  {
		  s[i][j] = -1;
	  }
  }


  for(i=0;i<r*c;i++){
	  min=10000;
	  for(j=1;j<=r;j++){
		  for(k=1;k<=c;k++){
			  if(h[j][k]<min && s[j][k]==-1){
				  min = h[j][k];
				  mini = j;
				  minj = k;
			  }
		  }
	  }
	  ski(mini,minj);
  }

  
  cout << output;
 
  //delete[] weight;
  //delete[] value;
  //for(i=0;i<=W;i++){    //To delete the inner arrays
   //   delete[] s[i];
  //}
  //delete[] s;   
  return 0;
}