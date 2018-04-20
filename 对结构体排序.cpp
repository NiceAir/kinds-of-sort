#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;

struct OrderList{
	int needs;
	int StartTime;
	int ContinueTime;
};




int cmp(OrderList a, OrderList b){
	if(a.StartTime!=b.StartTime) return a.StartTime<b.StartTime;
	else return a.needs<b.needs;
}


int main(){
	int t=5, n=t, i;
	OrderList list[n];
	for(i=0;i<n;i++)  cin >>list[i].needs>>list[i].StartTime>>list[i].ContinueTime;
	sort(list,list+n,cmp);
	for(i=0;i<n;i++)	cout <<list[i].needs<<" "<<list[i].StartTime<<" "<<list[i].ContinueTime<<endl;
	
	
	return 0;
}
