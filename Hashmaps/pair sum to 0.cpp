#include<bits/stdc++.h>
using namespace std ;

int pairsum(int* input , int n)
{
	unordered_map<int,int> freq ;
	
	int paircount = 0 ;
	
	for(int i=0  ; i<n ; i++)
	{
		int compliment = -input[i] ;
		
		if(freq.find(compliment)!=freq.end())
		{
			paircount += freq[compliment] ;
		}
		
		++freq[input[i]] ;
	}
	
	return paircount ;
}


int main()
{
   int n  ;
   cin>> n ;
   
   int* arr = new int[n] ;
   
   for(int i=0 ; i<n ; i++)
   {
   	cin>>arr[i] ;
   }
   
   
   cout<<pairsum(arr , n) ;
   
   delete [] arr ;
}
