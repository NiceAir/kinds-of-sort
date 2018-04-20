#include<stdio.h>
#include<iostream>

//������������������ɵ����кϳ�Ϊһ���������� 
void Merger(int a[], int low, int mid, int high){ 	
	int b[high-low+1]={0};    //����b���������� 
	int i, j, x=0;
	for(i=low, j=mid+1;i<=mid&&j<=high;)  
	{													//�����������е�Ԫ����С�������� 
		if(a[i]<a[j])	b[x++]=a[i++];			//����b�� 
		else	b[x++]=a[j++];	
	}
	
	while(i<=mid)	b[x++]=a[i++];//����һ����ʣ�࣬��ʣ���Ԫ�ظ��Ƶ�����b�� 
	while(j<=high) b[x++]=a[j++];//����һ����ʣ�࣬��ʣ���Ԫ�ظ��Ƶ�����b��
	
	for(i=low,x=0;i<=high;i++)         //��b�е����ݷŻ�a�� 
	{
		a[i]=b[x++];
	} 	
}


//������a�ֽ�ɳ���Ϊgap�����ɶΣ����������� Merger�������кϳ� 
void AllMerger(int a[], int gap, int length){
	int i;
	for( i=0; i+2*gap-1<length; i+=2*gap)	
	Merger(a,i,i+gap-1,i+2*gap-1);
	
	if(i+gap-1<length)
	Merger(a,i,i+gap-1,length-1);
			
	
}


//������a���϶��֣����ҵ���AllMerger,�Ծ���gap���ȵ����������������������� 
void MergerSort(int a[], int length){
	for(int gap=1; gap<length; gap*=2)	AllMerger(a, gap, length);
	
} 


int main(){
	FILE *fp;
	int a[38];
	fp=fopen("D:\\Work\\C\\����\\�����õ�������.txt","r");
	
	for(int i=0;i<36;i++)
	fscanf(fp,"%d",&a[i]);

	fclose(fp);
	
/************************ ����ʼ *************************/
	MergerSort(a,36);

	for(int i=0;i<36;i++)
	{
		printf("%d  ",a[i]);
	 } 

	return 0;
}
