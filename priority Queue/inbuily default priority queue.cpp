#include<bits/stdc++.h>
using namespace std ;

int main()
{
	priority_queue<int> pq ;
	
	pq.push(5) ;
	pq.push(99) ;
	pq.push(75) ;
	pq.push(24) ;
	pq.push(85) ;
	
	cout<<"size"<<pq.size()<<endl ;
	cout<<"Top"<<pq.top()<<endl ;
	
	while(!pq.empty())
	{
		cout<<pq.top()<<endl ;
		pq.pop() ;
	}
	
}
