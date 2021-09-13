#include<bits/stdc++.h>
using namespace std ;

vector<int> ksmallest(int* input , int n , int k)
{
	
	priority_queue<int> pq ;
	
	// push first k elemnets in the priority queue 
	for(int i=0 ; i<k ; i++)
	{
		pq.push(input[i]) ;
	}
	
	// for remainig element compare the elements with the max of the pq on the top
	
	for(int i=k ; i<n ; i++)
	{
		if(input[i] < pq.top())
		{
			pq.pop() ;
			pq.push(input[i]) ;
		}
	}
	
	// convert heap into vector and return that
	
	vector<int> ans ;
	
	
	
	
	while(!pq.empty())
	{
		ans.push_back(pq.top()) ;
		pq.pop() ;
	}
	
	return ans ;
	
}

int main()
{
	int size ;
	cin>>size ;
	
	int *input = new int[size] ;
	
	for(int i=0 ; i<size ; i++)
	{
		cin>>input[i] ;
	}
	
	int k ;
	cin>> k ;
	 vector<int> output = ksmallest(input , size , k) ;
	 sort(output.begin() , output.end()) ;
	 
	 for(int i=0 ; i<output.size() ; i++)
	 {
	 	cout<<output[i]<<" " ;
	 }
	 
	 
	 delete[] input ;
}




























