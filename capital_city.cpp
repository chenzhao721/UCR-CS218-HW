// A simple representation of graph using STL
#include <iostream>
#include <vector>
using namespace std;
 
vector<int> *adj;
int *flagmatrix;
bool **outputmatrix;
vector<int> output;
int outputnum=0;
/////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////


int check_outputmatrix(int node, int nodenum){
	for(int i=0;i<nodenum;i++){
		if(outputmatrix[node][i]==false)
			return -1;
	}
	return 1;
}


void traverse(int node, int nodenum){
	if(flagmatrix[node]==1 || flagmatrix[node]==-1) return;               // this node has already been traversed
	outputmatrix[node][node] = true;
	flagmatrix[node]=2;                            // this node is being traversed

	if(adj[node].size()==0){
		flagmatrix[node] = -1;
		return;
	}

	for(vector<int>::iterator i=adj[node].begin(); i<adj[node].end();i++){
        

		if(flagmatrix[*i]==1){
            flagmatrix[node] = 1;
			//outputmatrix[node] = 1;
			//output.push_back(node);
			outputnum++;
			return;
		}

		if(flagmatrix[*i]==-1){
			for(int j=0; j<nodenum; j++){
				if(outputmatrix[*i][j]==1)
					outputmatrix[node][j] = 1;
			}
		}

		else if(flagmatrix[*i]==2){
			outputmatrix[node][*i] = 1;
		}

		else{
			traverse(*i, nodenum);
			for(int j=0; j<nodenum; j++){
				if(outputmatrix[*i][j]==1)
					outputmatrix[node][j] = 1;
			}
		}

	}

	flagmatrix[node]=check_outputmatrix(node, nodenum);

	if(flagmatrix[node]==1){
		//output.push_back(node);
		outputnum++;
	}
	return;


}



 

int main()
{
    int nodenum;
	int edgenum;
	int i,j;
	int src, tar;
	

	scanf("%d", &nodenum);
	scanf("%d", &edgenum);
    adj = new vector<int>[nodenum];
	flagmatrix = new int[nodenum];
	for(i=0;i<nodenum;i++){
		flagmatrix[i]=0;
	}

	outputmatrix = new bool*[nodenum];
	for(i=0;i<nodenum;i++){
		outputmatrix[i]= new bool[nodenum];
	}

	for(i=0;i<nodenum;i++){
		for(j=0;j<nodenum;j++){
		    outputmatrix[i][j]=0;
		}
	}

   
	//clearflag(nodenum);
	
	

	for(i=0;i<edgenum;i++){
		scanf("%d %d", &src, &tar);
		adj[tar-1].push_back(src-1);
	}

    for(i=0;i<nodenum;i++){
		traverse(i, nodenum);
	}

	printf("%d\n", outputnum);

    //for(vector<int>::iterator k=output.begin(); k<output.end(); k++){
      //  printf("%d ", (*k+1));
	//
      //}
    for(i=0;i<nodenum;i++){
	    if(flagmatrix[i]==1)
			printf("%d ", i+1);
	}


    //printGraph(nodenum);
    return 0;
}