#include<stdio.h>
#include<iostream>
int main(){
	FILE *fp;
	int a[38], i;
	fp=fopen("D:\\Work\\C\\排序\\排序用的数字组.txt","r");
	
	for(i=0;i<36;i++)
	fscanf(fp,"%d",&a[i]);

	fclose(fp);
/***********************排序开始*************************/
	for(i=0;i<36;i++)
	{
		int key=a[i], j;
		for(j=i-1;j>=0;j--)
		{
			if(key<a[j]) a[j+1]=a[j];
			else break;
		}
		a[j+1]=key;
	}



	for(i=0;i<36;i++)
	{
		printf("%d  ",a[i]);
	 } 

	return 0;
}
