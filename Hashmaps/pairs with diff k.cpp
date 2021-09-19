#include<bits/stdc++.h>
using namespace std ;

int getpair(int* input ,int n ,int k)
{
      unordered_map<int , int> mp ;
      int count =0 ;
      
      
      for(int i=0 ; i<n ; i++)
      {
      	if(mp.count(input[i]) == 0)
      	{
      		mp[input[i]] =1 ;
		  } else
		  {
		  	mp[input[i]] ++ ;
		  }
	  }
	  
	  for(int i=0 ; i<n ;i++)
	  {
	  	int k1 = input[i] - k ;
	  	int k2 = input[i] + k ;
	  	int kp = input[i] ;
	  	
	  	
	  	if(kp < k1 && mp.count(k1) == 1)
	  	{
	  		int x = mp[k1] ;
	  		
	  		for(int j=0 ; j<x ; j++)
	  		{
	  			count ++ ;
			  }
		  }
		  
		  if(kp < k2 && mp.count(k2) == 1)
		  {
		  	int x = mp[k2] ;
		  	for(int	j=0 ; j<x ; j++)
		  	{
		  		count++ ;
			  }
		  }
		  
		  
		  if(k1 == k2)
		  {
		  	mp[k1] -- ;
		  	int x = mp[k1] ;
		  	
		  	for(int j=0 ; j<x ; j++)
		  	{
		  		count++ ;
			  }
		  }
	  }
	  
	  
	  return count ;
}



int main()
{
	int n ;
	cin>> n ;
	
	int *input = new int[n] ;
	
	for(int i=0 ; i<n ; i++)
	{
		cin>>input[i] ;
	}
	
	int k ;
	cin>> k; 
	
	
	cout<<getpair(input ,n ,k) ;
	
	delete [] input ;	
}
