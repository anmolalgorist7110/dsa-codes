#include<bits/stdc++.h>
using namespace std ;

bool ismax(int arr[] , int n)
{
	for(int i=0 ; i<=(n-2)/2 ; i++)
	{
		// if left child is greater , return false
		
		if(arr[2*i + 1] > arr[i])
		{
			return false ;
		}
		
		// if right child is greater , return false 
		
		if(2*i+2 < n && arr[2*i+2] > arr[i])
		{
			return false ;
		}
	}
	
	return true ;
}

int main()
{
	int n ;
	cin>>n ;
	
	int *arr = new int[n] ;
	
	for(int i=0 ; i<n ; i++)
	{
		cin>>arr[i] ;
	}
	
	cout<<(ismax(arr , n) ? "true" : "false")<<endl ;
	
	delete [] arr ;
}
