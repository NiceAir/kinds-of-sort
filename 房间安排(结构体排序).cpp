//对结构体排序（自己写的快排算法） 
/*测试数据 ： 
3
3 10 4
4 9 3
3 12 6
*/ 
#include<iostream>
using namespace std;
struct OrderForm{
	int needs;
	int StartTime;
	int ContinueTime;
	int EndTime;
};
void Addtion(OrderForm order[], int n){
	for(int i=0;i<n;i++)		order[i].EndTime=order[i].StartTime + order[i].ContinueTime;
}
int FormSort(OrderForm order[], int low, int high){
	int i=low, j=high;
	OrderForm a;
	a.needs=order[0].needs;
	a.StartTime=order[0].StartTime;
	a.ContinueTime=order[0].ContinueTime;
	a.EndTime=order[0].EndTime;
	while(i<j)
	{
		while(i<j&&a.StartTime<=order[j].StartTime) j--;
		order[i].needs=order[j].needs;
		order[i].StartTime=order[j].StartTime;
		order[i].ContinueTime=order[j].ContinueTime;
		order[i].EndTime=order[j].EndTime;
		
		while(i<j&&a.StartTime>=order[i].StartTime) i++;
		order[j].needs=order[i].needs;
		order[j].StartTime=order[i].StartTime;
		order[j].ContinueTime=order[i].ContinueTime;
		order[j].EndTime=order[i].EndTime;
	}
	order[i].needs=a.needs;
	order[i].StartTime=a.StartTime;
	order[i].ContinueTime=a.ContinueTime;
	order[i].EndTime=a.EndTime;
	
	return i;
}

void AllSort(OrderForm order[], int low, int high){
	int sign=0;
	if(low<high)
	{
		sign=FormSort(order,low,high);
		AllSort(order,low,sign-1);
		AllSort(order,sign+1,high);
	}
}
int main(){
	int n, i=0;
	cin>>n;
	OrderForm order[n];
	while(i<n)
	{
		cin >>order[i].needs>>order[i].StartTime>>order[i].ContinueTime;
		i++;
	}	
	Addtion(order,n);	
	cout <<endl;
	for(i=0;i<n;i++)	cout <<order[i].needs<<" "<<order[i].StartTime<<" "<<order[i].ContinueTime<<" "<<order[i].EndTime<<endl;
	AllSort(order,0,n-1);		
	cout <<endl;
	for(i=0;i<n;i++)	cout <<order[i].needs<<" "<<order[i].StartTime<<" "<<order[i].ContinueTime<<endl;
	return 0;
}
