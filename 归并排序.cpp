#include<stdio.h>
#include<iostream>

//将由两段有序数组组成的数列合成为一个有序数组 
void Merger(int a[], int low, int mid, int high){ 	
	int b[high-low+1]={0};    //数组b用来当缓存 
	int i, j, x=0;
	for(i=low, j=mid+1;i<=mid&&j<=high;)  
	{													//将两个数组中的元素由小到大依次 
		if(a[i]<a[j])	b[x++]=a[i++];			//放入b中 
		else	b[x++]=a[j++];	
	}
	
	while(i<=mid)	b[x++]=a[i++];//若第一组有剩余，则将剩余的元素复制到数组b中 
	while(j<=high) b[x++]=a[j++];//若第一组有剩余，则将剩余的元素复制到数组b中
	
	for(i=low,x=0;i<=high;i++)         //将b中的内容放回a中 
	{
		a[i]=b[x++];
	} 	
}


//将数组a分解成长度为gap的若干段，再两两调用 Merger函数进行合成 
void AllMerger(int a[], int gap, int length){
	int i;
	for( i=0; i+2*gap-1<length; i+=2*gap)	
	Merger(a,i,i+gap-1,i+2*gap-1);
	
	if(i+gap-1<length)
	Merger(a,i,i+gap-1,length-1);
			
	
}


//将数组a不断二分，并且调用AllMerger,对具有gap长度的所有数组进行两两有序组合 
void MergerSort(int a[], int length){
	for(int gap=1; gap<length; gap*=2)	AllMerger(a, gap, length);
	
} 


int main(){
	FILE *fp;
	int a[38];
	fp=fopen("D:\\Work\\C\\排序\\排序用的数字组.txt","r");
	
	for(int i=0;i<36;i++)
	fscanf(fp,"%d",&a[i]);

	fclose(fp);
	
/************************ 排序开始 *************************/
	MergerSort(a,36);

	for(int i=0;i<36;i++)
	{
		printf("%d  ",a[i]);
	 } 

	return 0;
}
