#include<stdio.h>
#include<iostream>
void swap(int &x, int &y){
	int i=x;
	x=y; y=i;
}
int main(){
	FILE *fp;
	int a[38];
	fp=fopen("D:\\Work\\C\\排序\\排序用的数字组.txt","r");
	
	for(int i=0;i<36;i++)
	{
		fscanf(fp,"%d",&a[i]);
//		printf("%d ",a[i]);
	} 
	fclose(fp);
/***********************排序开始*************************/
	int i, j, t;
	for(i=0;i<36-1;i++)
	{
		for(j=0;j<36-i-1;j++)
		{
			if(a[j]>a[j+1]) swap(a[j],a[j+1]);
		}
	}
	
	for(i=0;i<36;i++)
	{
		printf("%d  ",a[i]);
	 } 



}
