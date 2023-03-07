#include <iostream>
#include <vector>
#include <stack>
#include <climits>
#include <utility>
#include<algorithm>
using namespace std;


int T;
bool **matrix;
bool *flag;
int *p;
bool *b;

bool find(int i, int n){
	int j;
	for(j=0;j<n;j++){
		if(matrix[i][j]==1 && b[j]==false){
			b[j]=true;
			if(p[j]==-1 || find(p[j],n)){
				p[j]=i;
				return true;
			}
		}
	}
	return false;
}

void Hungarian(int n){
	int i;
	int j;
	for(i=0;i<n;i++){
		p[i]=-1;
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			b[j]=false;
		}
		find(i,n);
	}
}

bool check(int n){
	int i;
	int count=0;
	for(i=0;i<n;i++){
		if(p[i]!=-1) count++;
	}
	if(count==n) return true;
	else return false;
}

int main(){
	scanf("%d",&T);
	flag = new bool[T];
	int pos=0;
	int n;
	int iter=T;
	int i,j;
	int convertor;

	while(iter>0){
	    int count=0;

		scanf("%d",&n);
		matrix=new bool* [n];

		for(i=0;i<n;i++){
			matrix[i] = new bool[n];
		}

		p = new int[n];
	    b = new bool[n];

        for(i=0;i<n;i++){
		    for(j=0;j<n;j++){
				scanf("%d", &convertor);
				if(convertor==1){
				    matrix[i][j] = true;
				    count++;
				}
				else
					matrix[i][j] = false;

			}
		}


	    Hungarian(n);
		
        if(check(n)==true)
			flag[pos]=true;
		else
			flag[pos]=false;

		iter--;
		pos++;

		for(i=0;i<n;i++){
			delete[] matrix[i];
		}
		delete[] matrix;
		delete[] p;
		delete[] b;


	}

	for(i=0;i<T;i++){
		if(flag[i])
			printf("Yes\n");
		else
			printf("No\n");
	}

	return 0;
}

