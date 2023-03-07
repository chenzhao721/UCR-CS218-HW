#include <iostream>
#include <vector>
#include <numeric>      // std::iota
#include <algorithm>    // std::sort, std::stable_sort
#include <math.h>
#include <stdlib.h>     // abs 

using namespace std;

const int n=3;                  //The board size is n*n

struct state{
	int board[n][n];
	int depth;
	int heuristic;
	int cost;
	int num;
	int blanki, blankj;
};

vector<state> queue;
int functiontype;
int totalnode=0;                               // number of total created nodes

 state remove_front(){
	 state front;
	 vector<state>::iterator front_pos = queue.begin();
	 int mincost=100000000;
     for(vector<state>::iterator i=queue.begin(); i!=queue.end(); i++){
		 if(mincost>(*i).cost){
			 front = *i;
			 mincost = (*i).cost;
			 front_pos = i;
		 }
	 }
	 queue.erase(front_pos);
	 return front;
 }

 bool goal_test(state &front){
	 int i,j;
	 for(i=0;i<n;i++){
		 for(j=0;j<n;j++){
			 if(front.board[i][j]!=i*n+j+1) 
				 return false;
		 }
	  }
	 return true;

}

 void compute_heuristic(state &newnode){
	 int i,j,k,l;
	 newnode.heuristic = 0;
	 switch (functiontype){
	     case 1:
		     break;
	     case 2:
             for(i=0;i<n;i++){
		         for(j=0;j<n;j++){
             		 if(newnode.board[i][j]!=i*n+j+1) 
						 newnode.heuristic++;
				 }
			 }
			 break;
	     case 3:
			 int misplacedi;             // the position i,j of misplaced elements
			 int misplacedj;
		     for(i=0;i<n;i++){
		         for(j=0;j<n;j++){
					 if(newnode.board[i][j]!=i*n+j+1){
						 for(k=0;k<n;k++){
							 for(l=0;l<n;l++){
								 if(newnode.board[i][j]==i*n+j+1){
									 misplacedi = k;
									 misplacedj = l;
								 }
							 }
						 }

						 newnode.heuristic += (abs(i-misplacedi) + abs(j-misplacedj));
					 }

				 }
			 }
			 break;
	 }
 }



 void create_one_node(state newnode, state &front){
	 int temp;
	 //swap the elements in the old blank position and new blank position
	 temp = newnode.board[newnode.blanki][newnode.blankj];
	 newnode.board[newnode.blanki][newnode.blankj] = n*n;
	 newnode.board[front.blanki][front.blankj] = temp;
	 compute_heuristic(newnode);
	 newnode.cost = newnode.heuristic+newnode.depth;
	 totalnode= totalnode+1;
	 newnode.num = totalnode;
	 queue.push_back(newnode);
	 
 }

 
 
 void expand_nodes(state front){
	 int i,j;
	 state newnode;
	 newnode.depth = front.depth+1;
     newnode.num = totalnode + 1;
	 for(i=0;i<n;i++){
		 for(j=0;j<n;j++){
             newnode.board[i][j] = front.board[i][j];
		 }
	 }

	 if(front.blanki!=0){
		 newnode.blanki = front.blanki-1;
		 newnode.blankj = front.blankj;	
		 create_one_node(newnode, front);
	 }

	 if(front.blankj!=0){
		 newnode.blanki = front.blanki;
		 newnode.blankj = front.blankj-1;		
		 create_one_node(newnode, front);
	 }

	 if(front.blanki!=n-1){
		 newnode.blanki = front.blanki+1;
		 newnode.blankj = front.blankj;	
		 create_one_node(newnode, front);
	 }

	 if(front.blankj!=n-1){
		 newnode.blanki = front.blanki;
		 newnode.blankj = front.blankj+1;	
		 create_one_node(newnode, front);
	 }

	 
 }

	 
 void showstate(state front){
	 int i,j;
	 for(i=0;i<n;i++){
		 for(j=0;j<n;j++){
			 if(front.board[i][j]!=n*n){
				 cout<<front.board[i][j]<<" ";
			 }
			 else{
				 cout<<"* ";
			 }
		 }
		 cout<<endl;
	 }
	 cout<<endl;
 }


           
state gamestart(state &initstate){
	state output;
	output.num = -1;
	queue.push_back(initstate);
	state front = initstate;	
	while(queue.size()!=0){
		front = remove_front();
		showstate(front);
		if(goal_test(front)==true){
			output = front;
			return output;
		}
		else{
			expand_nodes(front);
		}
	}
	return output;
}



int main ()
{
 
  int i,j;
  char temp;
  state output;
  
  cout<<"please input which function type you would like to use:";
  cout<<"uniform cost -- 1"<<endl;
  cout<<"A* with the Misplaced Tile heuristic -- 2"<<endl;
  cout<<"A* with the Manhanttan Distance heuristic -- 3"<<endl;

  cin>>functiontype;

  state initstate;
  initstate.depth=0;
  initstate.num=1;
 
  
  cout<<"please input the value of initial states"<<endl;
  cout<<"such as 1 2 3"<<endl;
  cout<<"        4 5 6"<<endl;
  cout<<"        7 8 *"<<endl;
  cout<<endl;

  for(i=0;i<n;i++){
	  for(j=0;j<n;j++){
	      cin>>temp;
		  if(temp!='*')
			  initstate.board[i][j] = temp - '0';
		  else{
			  initstate.board[i][j] = n*n;
			  initstate.blanki = i;
			  initstate.blankj = j;
		  }
	  }
  }
  
  compute_heuristic(initstate);
  initstate.cost = initstate.heuristic;

  output = gamestart(initstate);
  cout<<"The depth of solution is: "<<output.depth<<endl;
  cout<<"The total number of nodes is: "<<totalnode<<endl;

  return 0;
}