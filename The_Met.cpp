#include <iostream>
#include <vector>
#include <numeric>      // std::iota
#include <algorithm>    // std::sort, std::stable_sort
#include <math.h>

using namespace std;

vector<int> *tree; 
float *s;
int ans=0;

int met(int i){
	float longest=0;
    float longest2=0;

    if(tree[i].size()==0){
		s[i] = 0;
		return s[i];
	}

	if(tree[i].size()==1){
		s[i] = met(*(tree[i].begin()))+1;
		if(ceil(s[i]/2)>ans)
			ans = int(ceil(s[i]/2));
		return s[i];
	}

    for (std::vector<int>::iterator j=tree[i].begin(); j!=tree[i].end();j++){
		if (longest<met(*j)){
			longest2 = longest;
			longest = met(*j);
		}
		else if(longest2<met(*j)){
			longest2 = met(*j);
		}
	}

	if((longest2+longest)/2+1>ans)
		ans = int(ceil((longest2+longest+2)/2));

	s[i] = longest+1;
	return s[i];
}


int main ()
{
 
  int i;
  int n;
  int parent;
  int child;
  int temp;
  
  scanf("%d", &n);
  tree = new vector<int>[n];
  s = new float[n];
 

  for (i=0; i<n-1; i++)
  {
	  scanf("%d", &parent);
	  scanf("%d", &child);

	  if(parent>child){
		  temp = parent;
		  parent = child;
		  child = temp;
	  }

	  tree[parent-1].push_back(child-1);
  }

  for (i=0; i<n; i++){
	  for (std::vector<int>::iterator j=tree[i].begin(); j!=tree[i].end();j++){
		  printf("%d, %d\n",i+1, (*j)+1);
	  }
  }

  met(0);

  for (i=0; i<n; i++){
	  printf("%d:%f\n", i, s[i]);
  } 
  
  
  printf("%d", ans);
  return 0;
}