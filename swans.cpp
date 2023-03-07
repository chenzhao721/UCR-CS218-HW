#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

struct pos{
	short int rpos;
	short int cpos;
};

char **lake;
char **temp;
bool **searchflag;
int r,c;
pos s1,s2;                //position of swan 1 and 2;


void showlake(){
	int i,j;
	for(i=0;i<r;i++){
		for(j=0;j<c;j++){
			printf("%c",lake[i][j]);
		}
		printf("\n");
	}
}

void updatelake(){
	int i,j;
	for(i=0;i<r;i++){
		for(j=0;j<c;j++){
			if(lake[i][j]=='X'){
				if(i>0){
					if(lake[i-1][j]=='.' || lake[i-1][j]=='L'){
					    temp[i][j] = '.';
					    continue;
					}
				}
		    	if(i<r-1){
			     	if(lake[i+1][j]=='.' || lake[i+1][j]=='L'){
				    	temp[i][j] = '.';
				    	continue;
					}
				}

				if(j>0){
					if(lake[i][j-1]=='.' || lake[i][j-1]=='L'){
					    temp[i][j] = '.';
					    continue;
					}
				}
				if(j<c-1){
					if(lake[i][j+1]=='.' || lake[i][j+1]=='L'){
					    temp[i][j] = '.';
					    continue;
					}
				}

				temp[i][j] = 'X';
			}

			else if(lake[i][j]=='.'){
				temp[i][j] = '.';
			}

			else{
				temp[i][j] = 'L';
			}

		}
	}

	for(i=0;i<r;i++){
		for(j=0;j<c;j++){
			lake[i][j] = temp[i][j];
		}
	}
}

bool findfriend(queue<pos> q){
	pos current;
	pos next;
	q.push(s1);
	searchflag[s1.rpos][s1.cpos] = true;
	while(q.size()!=0){
		current = q.front();
		q.pop();       
		if(current.cpos==s2.cpos && current.rpos==s2.rpos){
			return true;
		}
		if(current.rpos>0){
			if(lake[current.rpos-1][current.cpos]!='X' && searchflag[current.rpos-1][current.cpos]== false){
				next.rpos=current.rpos-1;
			    next.cpos=current.cpos;
				q.push(next);
				searchflag[current.rpos-1][current.cpos]= true;

			}
		}

		if(current.rpos<r-1){
			if(lake[current.rpos+1][current.cpos]!='X' && searchflag[current.rpos+1][current.cpos]== false){
				next.rpos=current.rpos+1;
			    next.cpos=current.cpos;
				q.push(next);
				searchflag[current.rpos+1][current.cpos]= true;
				
			}
		}

		if(current.cpos>0){
			if(lake[current.rpos][current.cpos-1]!='X'&& searchflag[current.rpos][current.cpos-1]== false){
				next.rpos=current.rpos;
			    next.cpos=current.cpos-1;
				q.push(next);
				searchflag[current.rpos][current.cpos-1]= true;
			}
		}

		if(current.cpos<c-1){
			if(lake[current.rpos][current.cpos+1]!='X'&& searchflag[current.rpos][current.cpos+1]== false){
				next.rpos=current.rpos;
			    next.cpos=current.cpos+1;
				q.push(next);
				searchflag[current.rpos][current.cpos+1]= true;
			}
		}
	}

	return false;

}

void updatesearchflag(){
	int i,j;
	for(i=0;i<r;i++){
		for(j=0;j<c;j++){
			searchflag[i][j] = false;
		}
	}
}





int main(){
	
	int i,j;
	int output=0;
	char dump;
	queue<pos> q;
	

	s1.cpos=-1;
	s1.rpos=-1;
	s2.cpos=-1;
	s2.rpos=-1;



	scanf("%d %d", &r, &c);
	lake = new char*[r];
	temp = new char*[r];
	searchflag = new bool*[r];

	for(i=0;i<r;i++){
		lake[i] = new char[c];
		temp[i] = new char[c];
		searchflag[i] = new bool[c];
	}

	scanf("%c",&dump);

	for(i=0;i<r;i++){
		for(j=0;j<c;j++){
			searchflag[i][j] = false;
			scanf("%c",&lake[i][j]);
			if(lake[i][j]=='L'){
				if(s1.rpos==-1){
					s1.rpos=i;
					s1.cpos=j;
				}
				else{
					s2.rpos=i;
					s2.cpos=j;
				}
			}

		}
		scanf("%c",&dump);
	}
    
    while(1){	
		if(findfriend(q)==true) break;
		updatelake();
		updatesearchflag();
		showlake();
		printf("\n");
		output++;
	}

	for(i=0;i<r;i++){
		delete[] lake[i];
		delete[] searchflag[i];
		delete[] temp[i];
	}

	delete[] lake;
	delete[] searchflag;
	delete[] temp;

	printf("%d",output);

	return 0;

	

}
