#include <iostream>
#include <vector>
#include <numeric>      // std::iota
#include <algorithm>    // std::sort, std::stable_sort
#include <math.h>

using namespace std;




int checkwin(int *board){
	if(board[0]==1&&board[1]==1&&board[2]==1){
		return 1;
	}
	if(board[3]==1&&board[4]==1&&board[5]==1){
		return 1;
	}
	if(board[6]==1&&board[7]==1&&board[8]==1){
		return 1;
	}
	if(board[0]==1&&board[3]==1&&board[6]==1){
		return 1;
	}
	if(board[1]==1&&board[4]==1&&board[7]==1){
		return 1;
	}
	if(board[2]==1&&board[5]==1&&board[8]==1){
		return 1;
	}
	if(board[0]==1&&board[4]==1&&board[8]==1){
		return 1;
	}
	if(board[2]==1&&board[4]==1&&board[6]==1){
		return 1;
	}

	if(board[0]==0&&board[1]==0&&board[2]==0){
		return 0;
	}
	if(board[3]==0&&board[4]==0&&board[5]==0){
		return 0;
	}
	if(board[6]==0&&board[7]==0&&board[8]==0){
		return 0;
	}
	if(board[0]==0&&board[3]==0&&board[6]==0){
		return 0;
	}
	if(board[1]==0&&board[4]==0&&board[7]==0){
		return 0;
	}
	if(board[2]==0&&board[5]==0&&board[8]==0){
		return 0;
	}
	if(board[0]==0&&board[4]==0&&board[8]==0){
		return 0;
	}
	if(board[2]==0&&board[4]==0&&board[6]==0){
		return 0;
	}

	return -1;
}


int checkturn(int *board){
	int cross = 0;
	int noughts = 0;
	int i;
	for(i=0;i<9;i++){
		if(board[i] == 0)
			noughts++;
		else if(board[i]==1)
			cross++;
	}

	if(cross>noughts)
		return 0;
	else
		return 1;

}

int tictactoe(int *board){
	int i,j;
	
	bool drawflag = false;
	bool lossflag = true;
	bool completeflag = true;

	if(checkwin(board)==0)
		return 0;
	else if(checkwin(board)==1)
		return 1;


	for(i=0;i<9;i++){
		if(board[i]==-1){
			completeflag = false;
		}
	}
	if(completeflag == true){
		if(checkwin(board)==-1){
			return -1;
		}
	}
    
	int *temp = new int[9];

	if(checkturn(board)==0){
	    for(i=0;i<9;i++){
	     	if(board[i]==-1){
		    	for(j=0;j<9;j++){
		     		temp[j] = board[j];
				}
		    	temp[i] = 0;

				if(tictactoe(temp)==0){
                    delete[] temp;
		     		return 0;
				}

		    	if(tictactoe(temp)==-1){
		    		drawflag = true;
				}
			}
			
		}

		if(drawflag == false){
			delete[] temp;
			return 1;
		}
		else
			return -1;

	}

	if(checkturn(board)==1){
	    for(i=0;i<9;i++){
	     	if(board[i]==-1){
		    	for(j=0;j<9;j++){
		     		temp[j] = board[j];
				}
		    	temp[i] = 1;

				if(tictactoe(temp)==1){
			    	delete[] temp;
			    	return 1;
				}

		    	if(tictactoe(temp)==-1){
			    	drawflag = true;
				}
			}
			
		}

		if(drawflag == false){
			delete[] temp;
			return 0;
		}
		else
			return -1;

	}



   	
}


int main ()
{
 
  int i,j;
  int n;
  char temp, comma;
  int ans;
  
  int board[9];
  for(j=0;j<3; j++){

      for (i=0; i<3; i++)
	  {
	      scanf("%c", &temp);
	      if(temp=='X')
		      board[3*j+i] = 1;
    	  else if(temp=='O')
	    	  board[3*j+i] = 0;
	      else
		      board[3*j+i] = -1;
	  }
	  scanf("%c", &comma);
 
  }

  ans = tictactoe(board);

  if(ans==1)
	  printf("Crosses win");
  if(ans==0)
	  printf("Noughts win");
  if(ans==-1)
	  printf("Draw");

  return 0;
}