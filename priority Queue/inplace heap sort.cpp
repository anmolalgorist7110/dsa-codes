 #include<bits/stdc++.h>
 using namespace std ;
 
 
 
 
 void heapsort(int arr[] , int n)
 {
 	// build the heapsort
 	
 	for(int i=0 ; i<n ; i++)
 	{
 		int childindex = i ;
 		
 		while(childindex > 0)
 		{
 			int parentindex = (childindex - 1)/2 ;
 			
 			if(arr[childindex] < arr[parentindex])
 			{
 				int temp = arr[childindex] ;
 				arr[childindex] = arr[parentindex] ;
 				arr[parentindex] = temp ;
			 }
			 else
			 {
			 	break ;
			 }
			 
			 childindex ;
		 }
	 }
	 
	 // removin the element
	 
	 int size = n ;
	 
	 while(size > 1)
	 {
	 	int temp = arr[0] ;
	 	arr[0] = arr[size -1] ;
	 	arr[size -1] = temp ;
	 	
	 	size -- ;
	 	
	 	int parentindex = 0 ;
	 	int leftchildindex = 2* parentindex + 1 ;
	 	int rightchildindex = 2* parentindex + 2 ;
	 	
	 	while(leftchildindex < size)
	 	{
	 		int minindex = parentindex ;
	 		
	 		if(arr[minindex] > arr[leftchildindex])
	 		{
	 			minindex = leftchildindex ;
			 }
			 
			 if(rightchildindex < size && arr[rightchildindex] < arr[minindex])
			 {
			 	minindex = rightchildindex ;
			 }
			 
			 if(minindex == parentindex)
			 {
			 	break ;
			 }
			 
			 int temp = arr[minindex] ;
			 arr[minindex] = arr[parentindex] ;
			 arr[parentindex] = temp ;
			 
			 parentindex = minindex ;
			 leftchildindex = 2* parentindex + 1 ;
			 rightchildindex = 2* parentindex + 2 ;
		 }
	 	
	 }
 }
 
 
 int main()
 {
 	int size ;
 	cin>>size ;
 	
 	int* input = new int[size] ;
 	
 	for(int i=0 ; i<size ; i++)
 	{
 		cin>>input[i] ;
	 }
	 
	 heapsort(input , size) ;
	 
	 for(int i=0 ; i<size ; i++)
	 {
	 	cout<<input[i]<<" " ;
	 }
	 
	 delete [] input ;
 }
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
