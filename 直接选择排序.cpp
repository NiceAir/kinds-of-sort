#include<stdio.h>
#include<iostream>
void swap(int &x, int &y){
	int i=x;
	x=y; y=i;
}
int main(){
	FILE *fp;
	int a[38], i, j;
	fp=fopen("D:\\Work\\C\\����\\�����õ�������.txt","r");
	
	for(i=0;i<36;i++)
	fscanf(fp,"%d",&a[i]);

	fclose(fp);
/***********************����ʼ*************************/
// ��һ�α����Ĺ����У�����ͬʱ�ҳ������С��Ԫ�ء��������ͻ��ʡһ���ʱ�� 
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
