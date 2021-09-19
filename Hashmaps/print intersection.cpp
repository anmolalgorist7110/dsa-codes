#include<bits/stdc++.h>
using namespace std ;

void inter(int input1[] , int input2[] , int size1 , int size2)
{
	unordered_map<int,int> hash ;
	sort(input1 , input1+size1) ;
	sort(input2 , input2+size2) ;
	
	for(int i=0 ; i<size1 ; i++)
	{
		hash[input1[i]]++ ;
	}
	
	
	for(int j=0 ; j<size2 ; j++)
	{
		if(hash[input2[j]] > 0)
		{
			cout<<input2[j]<<" " ;
			hash[input2[j]]-- ;
		}
	}
	
	cout<<endl ;
}

int main()
{
	int t ;
	cin>>t ;
	
	while(t--)
	{
		int size1 , size2 ;
		
		cin>>size1 ;
		int *input1 =  new int[size1] ;
		
		for(int i=0 ; i<size1 ; i++)
		{
			cin>>input1[i] ;
		}
		
		cin>>size2 ;
		int *input2 = new int[size2] ;
		
		for(int i=0 ; i<size2 ; i++)
		{
			cin>>input2[i] ;
		}
		
		inter(input1 , input2 , size1 , size2) ;
		
		delete[] input1 ;
		delete[] input2 ;
	}
}
