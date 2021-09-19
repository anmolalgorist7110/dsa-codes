#include<bits/stdc++.h>

using namespace std ;

int highfreq(int input[] , int n)
{
	unordered_map<int,int> m ;
	for(int i=0 ; i<n ; i++)
	{
		int key = input[i] ;
		if(m.count(key)==0)
		{
			m[key] = 1 ; // intialize frequency value to 1 whenk key isn not already present in hashmap
		} else
		{
			m[key]++ ; // incrementing fre value by 1 when key is already present in hashmap
		}
	}
	
	int maxim = m[input[0]] ;
	int ans = input[0] ;
	int j=1 ;
	
	while(j<n)
	{
		if(m[input[j] > maxim])
		{
			maxim = m[input[j]] ;
			ans = input[j] ;
		}
		
		j++ ;
	}
	
	return ans ;
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
	
	cout<<highfreq(arr , n) ;
	
	delete [] arr ;
}
