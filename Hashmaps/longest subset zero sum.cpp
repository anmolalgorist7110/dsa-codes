#include<bits/stdc++.h>
using namespace std ;

int lengthsub(int* arr , int size)
{
	unordered_map<int , int> freq ;
	for(int i=1 ; i<size ; i++)
	{
		arr[i] += arr[i-1] ;
	}
	
	int m=0 ; 
	for(int i=0 ; i<size ; i++)
	{
			if(arr[i] == 0)
			{
				if(m<i+1)
				{
					m = i+1 ;
				}
			} else if(freq.count(arr[i]) == 1)
			{
				if(m < i - freq[arr[i]])
				{
					m = i - freq[arr[i]] ;
				}
			} else {
				freq[arr[i]] = i ;
			}
	}
	
	return m ;
}








int main()
{
	int size ;
	cin>>size ;
	int* arr = new int[size] ;
	
	for(int i=0 ; i<size ; i++)
	{
		cin>>arr[i] ;
	}
	
	
	cout<<lengthsub(arr , size) ;
	
	delete [] arr ;
}
