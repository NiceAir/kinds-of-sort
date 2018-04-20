#include<stdio.h>
#include<iostream>
void swap(int &x, int &y){
	int i=x;
	x=y; y=i;
}
int main(){
	FILE *fp;
	int a[38], i, j;
	fp=fopen("D:\\Work\\C\\排序\\排序用的数字组.txt","r");
	
	for(i=0;i<36;i++)
	fscanf(fp,"%d",&a[i]);

	fclose(fp);
/***********************排序开始*************************/
// 在一次遍历的过程中，可以同时找出最大、最小的元素。这样，就会节省一半的时间 
	for(i=0;i<35;i++)
	{
		int t=i;
		for(j=i+1;j<36;j++)
		{
			if(a[t]>a[j]) t=j;
		}
		swap(a[i],a[t]);
	}


	for(i=0;i<36;i++)
	{
		printf("%d  ",a[i]);
	 } 

	return 0;
}
