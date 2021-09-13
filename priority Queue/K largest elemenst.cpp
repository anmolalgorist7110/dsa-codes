#include<bits/stdc++.h>
using namespace std ;


vector<int> Klargest(int input[] , int n , int k)
{
	//priority_queue<int,vector<int>,greater<int>>max;
	 priority_queue<int,vector<int>,greater<int>>max;
	for(int i=0 ; i<k ; i++)
	{
		max.push(input[i]) ;
	}
	
	for(int i=k ; i<n ; i++)
	{
		if(max.top() < input[i])
		{
			max.pop() ;
			max.push(input[i]) ;
		}
	}
	
	while(!max.empty())
	{
		cout<<max.top()<<endl ;
		max.pop() ;
	}
}


int main()
{
	int size ;
	cin>>size ;
	
	int *input = new int[1 + size] ;
	
	for(int i=0 ; i<size ;i++)
	{
		cin>>input[i] ;
	}
	
	int k ;
	cin>>k ;
	
	vector<int> output = Klargest(input , size , k) ;
	
	for(int i=0 ; i<output.size() ; i++)
	{
		cout<<output[i]<<endl ;
	}
	
	return 0 ;
}

