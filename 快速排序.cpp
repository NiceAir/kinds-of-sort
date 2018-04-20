#include<stdio.h>
#include<iostream>
using namespace std; 
void swap(int &x, int &y){
	int i=x;
	x=y; y=i;
}
/***********************快速排序开始*************************/
int kuaipai(int *a, int low, int high){
	int sign=a[low], i=low, j=high;
	while(i<j)
	{
		whil	e(i<j &&a[j]>=sign) j--;
		a[i]=a[j];
		while(i<j &&a[i]<=sign) i++;
		a[j]=a[i];
	}
	a[i]=sign;	
	return i;
} 
void QSORT(int *a, int low, int high){
	int  axs=0;
	if(low<high){
		axs=kuaipai(a,low,high);
		QSORT(a,low,axs-1);
		QSORT(a,axs+1,high);		
	}
}

int main(){
	FILE *fp;
	int a[36], i;
	fp=fopen("D:\\Work\\C\\排序\\排序用的数字组.txt","r");
	
	for( i=0;i<36;i++)
	{
		fscanf(fp,"%d",&a[i]);
//		printf("%d  ",a[i]);
	} 
	fclose(fp);

//	cout <<"\n\n";
	
	QSORT(a,0,35); 
		for(i=0;i<36;i++)
	{
		printf("%d  ",a[i]);
	 } 

	return 0; 
}
