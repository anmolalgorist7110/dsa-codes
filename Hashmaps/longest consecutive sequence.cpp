#include<bits/stdc++.h>
using namespace std ;

vector<int> longestseq(int *arr, int n)
{
	unordered_map<int , int> h ;
	
	for(int i=0 ; i<n ; i++)
	{
		if(h.count(arr[i]) == 0)
		{
			h[arr[i]] = i ;
		}
	}
	
	
      unordered_map<int , int> ourmap ;
      vector<int> output ; 
      
      for(int i=0 ; i<n ; i++)
      {
      	ourmap[arr[i]] = true ;
	  }
	  
	  int len ;
	  int maxstart ;
	  int maxlen =0 ; 
	  
	  
	  for(int i=0 ; i<n ; i++)
	  {
	  	int current = arr[i] ;
	  	
	  	if(ourmap[arr[i]] == false)
	  	{
	  		continue ;
		  }
		  
		  ourmap[current] = false ;
		  len = 1 ;
		  int start = current ;
		  int nextelement = current+1 ;
		  
		  while(1)
		  {
		  		if(ourmap[nextelement] == true)
		  		{
		  			len++ ;
		  			ourmap[nextelement] = false ;	
		  			nextelement += 1 ;	
				  } else
				  {
				  	break ;
				  }
		  }
		  
		  int prevele = current -1 ;
		  
		  while(1)
		  {
		  	if(ourmap[prevele] == true)
		  	{
		  		start = prevele ;
		  		ourmap[prevele] = false ;
		  		len++ ;
		  		prevele -= 1 ;
			  } else
			  {
			  	break ;
			  }
		  }
		  
		if(len > maxlen)
		{
			maxlen = len ;
			maxstart = start ;
		} else if(len == maxlen)
		{
			if(h[start] < h[maxstart])
			{
				maxstart = start ;
			}
		}
	  }
	  
	  
	  
	  
	  for(int i=maxstart ; i<maxstart + maxlen ; i++)
	  {
	  	output.push_back(i) ;
	  }
	  
	  
	  
	  return output ;
	  
	  
	  
	  
	  
	  
	  
	  
	  
	  
	  
	  
}



int main()
{
	int size ;
	cin>>size ;
	
	int *arr = new int[size] ;
	
	for(int i=0 ; i<size ; i++)
	{
		cin>>arr[i] ;
	}
	
	
	vector<int> ans = longestseq(arr , size) ;
	
	cout<<ans[0] ;
	
	if(ans.size() > 1)
	{
		cout<<" "<<ans[ans.size() - 1] ;
	}
	
	delete [] arr ;
}
