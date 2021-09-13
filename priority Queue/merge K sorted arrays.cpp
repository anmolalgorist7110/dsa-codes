#include<bits/stdc++.h>
using namespace std ;

// method 1 (the most effircient soln)
vector<int> mergeKsortedarray(vector<vector<int>*> input)
{
	priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>> > pq ;
	int size = input.size() ;
	
	for(int i=0 ; i<size ; i++)
	{
		pq.push({input[i] -> at(0) , {i,0}}) ;
		}	
		
		vector<int> ans ;
		
		while(!pq.empty())
		{
			pair<int,pair<int,int>> current = pq.top() ;
			pq.pop() ;
			
			int i= current.second.first ;
			int k= current.second.second ;
			ans.push_back(current.first) ;
			
			if(k+1 < input[i] -> size())
			{
				pq.push({input[i]->at(k+1) , {i,k+1}}) ;
			}
		}
		
		return ans ;
}


// vector<int> mergedarray	 ;
 
 
 // another soln but not eff
/*priority_queue<int , vector<int> , greater<int>> minheap ;

for(int i=0 ; i< input.size() ; i++)
{
	for(int j=0 ; j< input[i] -> size() ; j++)
	{
		minheap.push(input[i] -> at(j)) ;
	}
}

while(!minheap.empty())
{
	mergedarray.push_back(minheap.top()) ;
	minheap.pop() ;
}

return mergedarray ;*/









int main()
{
	int k ;
	cin>>k ;
	
	vector<vector<int>*> input ;
	
	for(int j=1 ; j<=k ; j++)
	{
		int size ;
		cin>>size ;
		vector<int>* current = new vector<int> ;
		
		for(int i=0 ; i< size ; i++)
		{
			int a; 
			cin>>a ;
			current -> push_back(a) ;
		}
		
		input.push_back(current) ;
	}
	
	vector<int> output = mergeKsortedarray(input) ;
	
	for(int i=0 ; i<output.size() ; i++)
	{
		cout<<output[i]<<" " ;
	}
	

}












