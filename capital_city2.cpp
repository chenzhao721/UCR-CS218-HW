
#include <iostream>
#include <vector>
using namespace std;
 
vector<int> *adj;
int *flagmatrix;
int *outputflag;
int outputnum = 0;

void printGraph(int nodenum)
{
    for (int i = 0; i<nodenum; i++)
    {
        cout << "\n Adjacency list of vertex "
             << i+1 << "\n head ";
        //for (auto x : adj[v])
        //   cout << "-> " << x;
		for(vector<int>::iterator j=adj[i].begin(); j<adj[i].end(); j++){

            printf("%d\n", (*j+1));
		}
    }
}

bool checkflag(int nodenum){

	for(int i=0;i<nodenum;i++){
		if(flagmatrix[i]==0) return false;
	}
	return true;
}

void clearflag(int nodenum){

	for(int i=0;i<nodenum;i++){
		flagmatrix[i]=0;
	}
}




void traverse(int node, int nodenum){
	if(flagmatrix[node]==1) return;
	if(outputflag[node]==1) return;
	flagmatrix[node]=1;

	if(adj[node].size()==0){		
		return;
	}

	for(vector<int>::iterator i=adj[node].begin(); i<adj[node].end();i++){

		traverse(*i, nodenum);
		if(outputflag[*i] == 1){ 
			outputflag[node] = 1;
			return;
		}

	}


	
}


 

int main()
{
    int nodenum;
	int edgenum;
	int i;
	int src, tar;
	vector<int> output;

	scanf("%d", &nodenum);
	scanf("%d", &edgenum);
    adj = new vector<int>[nodenum];
	flagmatrix = new int[nodenum];
	outputflag = new int[nodenum];
   
	clearflag(nodenum);

	for(i=0;i<nodenum;i++){
		outputflag[i]=0;
	}
	

	for(i=0;i<edgenum;i++){
		scanf("%d %d", &src, &tar);
		adj[tar-1].push_back(src-1);
	}

    for(i=0;i<nodenum;i++){
		if(outputflag[i]==1){
			outputnum++;
			clearflag(nodenum);
			continue;
		}

		traverse(i, nodenum);

		if(outputflag[i]==1){
			outputnum++;
			clearflag(nodenum);
			continue;
		}

		if(checkflag(nodenum)==true){
		    outputflag[i] = 1;
		    outputnum++;

		}

	    clearflag(nodenum);

	
	}

	printf("%d\n", outputnum);

    for(i=0;i<nodenum;i++){
         if(outputflag[i]==1)
            printf("%d ", (i+1));
	}

    //printGraph(nodenum);
    return 0;
}