#include<stdio.h>
#include<iostream>
int d[6]={11,9,7,5,3,1};
void SHELLsort(int a[], int d[], int length){
	int  i, j, k, z, x;
	for(i=0;i<6;i++)
	{
		for(j=0;j<d[i];j++)
		{
			for(k=j+d[i];k<length;k+=d[i])
			{
				x=a[k];
				for(z=k-d[i];z>=0;z-=d[i])
				{
					if(x<a[z]) a[z+d[i]]=a[z];
					else break;
				}
				a[z+d[i]]=x;
			}
		}
	}
}


int main(){
	FILE *fp;
	int a[38], i;
	fp=fopen("D:\\Work\\C\\����\\�����õ�������.txt","r");
	
	for(i=0;i<36;i++)
	fscanf(fp,"%d",&a[i]);

	fclose(fp);
/***********************����ʼ*************************/


	SHELLsort(a,d,36);


	for(i=0;i<36;i++)
	{
		printf("%d  ",a[i]);
	 } 

	return 0;
}
