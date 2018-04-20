#include<iostream>
#include<stdio.h>
void Merger(int a[], int low, int mid, int high){ 	
	int b[high-low+1], x=0;    //数组b用来当缓存 
	int i, j;
	for(i=low, j=mid+1;i<=mid&&j<=high;)  
	{													//将两个数组中的元素由小到大依次 
		if(a[i]<a[j])	b[x++]=a[i++];			//放入b中 
		else	b[x++]=a[j++];	
	}
	while(i<=mid)	b[x++]=a[i++];//若第一组有剩余，则将剩余的元素复制到数组b中 
	while(j<=high) b[x++]=a[j++];//若第一组有剩余，则将剩余的元素复制到数组b中
	
	for(i=0;i<=high;i++)         //将b中的内容放回a中 
	{
		a[i]=b[i];
	} 	
}
int main(){
	int a[10]={3,8,9,5,4,7,6,3,8,1};
//	Merger(a, 0,4,9);

	int i;
	
	for( i=0; i+2*gap-1<length; i+=2*gap)	
	Merger(a,i,i+gap-1,i+2*gap-1);
	
	if(i+gap-1<length)
	Merger(a,i,i+gap-1,length-1);
			
	

		for(int i=0;i<10;i++)
	{
		printf("%d  ",a[i]);
	 } 

	return 0;
}

