#include <iostream>
using namespace std;
 int n,W;
  int *weight ;
  int *value ;
  int **s ;

  int max(int i, int j){
	  if(i>j) return i;
	  else return j;
  }

int suitcase(int i, int j){
	if(s[i][j]!=-1) return s[i][j];
	if(i==0 || j==0) return 0;
	int best=suitcase(i,j-1);
	if(i>=weight[j]){
		best = max(best,suitcase(i-weight[j],j-1)+value[j]);
	}
	s[i][j]=best;
	return best;
}
int main ()
{
 
  int i,j;
  cin >> W;
  cin >> n;
  weight = new int[n+1];
  value = new int[n+1];
  s = new int*[W+1];
  
  weight[0] = 0;
  value[0] = 0;

  for(i = 1; i<=n; i++){
	  cin>> weight[i];
	  cin>> value[i];
  }


  for (i=0; i<=W; i++)
  {
      s[i] = new int[n];
  }


  for (i=0; i<=W; i++)
  {
	  for (j=0; j<=n; j++)
	  {
		  s[i][j] = -1;
	  }
  }

  
  cout << suitcase(W,n);
 
  delete[] weight;
  delete[] value;
  //for(i=0;i<=W;i++){    //To delete the inner arrays
   //   delete[] s[i];
  //}
  //delete[] s;   
  return 0;
}