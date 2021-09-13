#include<bits/stdc++.h>
using namespace std ;

int main()
{
	priority_queue<int, vector<int>, greater<int> > pq ;
	
	pq.push(100) ;
	pq.push(30) ;
	pq.push(9) ;
	pq.push(25) ;
	pq.push(785) ;
	
	
	cout<<pq.size()<<endl ;
	cout<<pq.size()<<endl ;
	cout<<pq.top()<<endl ;
	
	while(!pq.empty())
	{
		cout<<pq.top()<<endl ;
		pq.pop() ;
	}
}
