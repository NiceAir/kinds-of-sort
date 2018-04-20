#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Student{
	int number;			//学号 
	char name[15];		//姓名 
	char gender[5];		//性别 
	float score1;		//成绩1 
	float score2;		//成绩2 
	float TOTALscore;	//总成绩 
	
}Student, * student;
void assign(Student *a,Student *b,int n,int m){
	strcpy(a[n].gender,b[m].gender);
	strcpy(a[n].name,b[m].name);
	a[n].number=b[m].number;
	a[n].score1=b[m].score1;
	a[n].score2=b[m].score2;
	a[n].TOTALscore=b[m].TOTALscore;
}
void exchange(Student *a,Student *b,int n,int m){
	Student numbers;
	
	strcpy(numbers.gender,a[n].gender);
	strcpy(numbers.name,a[n].name);
	numbers.number=a[n].number;
	numbers.score1=a[n].score1;
	numbers.score2=a[n].score2;
	numbers.TOTALscore=a[n].TOTALscore; 
	
	strcpy(a[n].gender,b[m].gender);
	strcpy(a[n].name,b[m].name); 
	a[n].number=b[m].number;
	a[n].score1=b[m].score1;
	a[n].score2=b[m].score2;
	a[n].TOTALscore=b[m].TOTALscore;
	
	strcpy(b[m].gender,numbers.gender);
	strcpy(b[m].name,numbers.name);
	b[m].number=numbers.number;
	b[m].score1=numbers.score1;
	b[m].score2=numbers.score2;
	b[m].TOTALscore=numbers.TOTALscore; 	 
} 

//存储学生信息 （从文件里读取）
//num表示总人数
int num;
int Asave(char file[],Student *ST ){
	int i , j;
	FILE *fp; 
	fp=fopen(file,"r");
	if(fp==NULL){
		printf("无法找到文件");
		return 0;
	}
	fscanf(fp,"%d",&num);
	for(i=0;i<num;i++){
		fscanf(fp,"%d%s%s%f%f",&(ST[i].number),(ST[i].name),(ST[i].gender),&(ST[i].score1),&(ST[i].score2));
	}
	fclose(fp);
	//自动计算总成绩
	i=0 ;
	while(i<num){
	 ST[i].TOTALscore=ST[i].score1+ST[i].score2;
	 i++; 
	}
	return 1;	
}
//查询  方法一(简单方法)：
//N表示有N个此姓名的人 
void find(Student *ST, int L1 , char L2[]){
	int i , j , N=0;
	Student st[50];
	if(strcmp(L2,"NULL")!=0){
		for(i=0;i<num;i++){
			j=i;
			while(strcmp(ST[j].name,L2)==0){
				assign(st,ST,N,j);
				j++;N++;
				}
			}
		if(N==0){
			printf("抱歉，找不到该学生的信息");
			printf("**************"); 
			return;
		}
	}
	else {
		for(i=0;i<num;i++){
			if(ST[i].number==L1){	
				assign(st,ST,N,i);		
				N=1;
				break;	
			}	
		}
		if(N==0){
			printf("抱歉，找不到该学生的信息");
			return ; 
		}
	}
	for(i=0;i<N;i++){
		printf("%d  %s  %s  %f  %f  %f",st[i].number,st[i].name,st[i].gender,st[i].score1,st[i].score2,st[i].TOTALscore);
		printf("\n");
	}
	return;
	
}
//查询  方法二（前提是学号是有序排列的）：
//*****************以下部分是一个整体**************** 
int FIND(Student* ST, int L1, char L2[] , int low , int high ){
	Student st[50];
	int i , j , N=0;
	int mid;
	if(strcmp(L2,"NULL")!=0) {
		for(i=0;i<num;i++){
			j=i;
			while(strcmp(ST[j].name,L2)==0){
				 assign(st,ST,N,j);
				j++;N++;
			}	
		}
		if(N==0){
			 printf("抱歉，找不到该学生的信息");
			return 0; 
		}
		for(i=0;i<N;i++){
			printf("%d  %s  %s  %f  %f  %f",st[i].number,st[i].name,st[i].gender,st[i].score1,st[i].score2,st[i].TOTALscore);
			printf("\n");
		}
		return 0;
	
	}	
	else{
//折半查找  非递归
// low表示末尾   high表示开头 
		while(low<=high){
			mid=(low+high)/2;
			if(L1==ST[mid].number){ 
				return mid;	
			}
			else if(L1<ST[mid].number){
				high=mid-1;
			}
			else low=mid+1;	
		}		
	}
	return 0;	
}
void PrintFIND(Student* ST, int L1, char L2[]){
	int i;
	if(strcmp(L2,"NULL")!=0) return;
	else {
		i=FIND(ST,L1,L2,1,num);
		printf("%d  %s  %s  %f  %f  %f",ST[i].number,ST[i].name,ST[i].gender,ST[i].score1,ST[i].score2,ST[i].TOTALscore);
		printf("\n");
	}
}
void SUEresult(Student* ST, int L1, char L2[] , int low , int high){ 
	FIND(ST,L1,L2,1,num);
	PrintFIND(ST,L1,L2);
} 
//*******************以上部分是一个整体***************
//排序方法一：快排
	//排学号 
int numberQuickSort(Student *ST,int low,int high){
	Student AXIS; 
	int  axis=(low+high)/2;	
	strcpy(AXIS.gender,ST[axis].gender);
	strcpy(AXIS.name,ST[axis].name);
	AXIS.number=ST[axis].number;
	AXIS.score1=ST[axis].score1;
	AXIS.score2=ST[axis].score2;
	AXIS.TOTALscore=ST[axis].TOTALscore;	
	assign(ST,ST,axis,high);
	while(low<high){
		while(low<high&&ST[low].number<=AXIS.number) low++;	
		assign(ST,ST,high,low);
		while(low<high&&ST[high].number>=AXIS.number) high--;		
		assign(ST,ST,low,high);	
	}
	strcpy(ST[low].gender,AXIS.gender);
	strcpy(ST[low].name,AXIS.name);
	ST[low].number=AXIS.number;
	ST[low].score1=AXIS.score1;
	ST[low].score2=AXIS.score2;
	ST[low].TOTALscore=AXIS.TOTALscore;
	return low;
}
void ALLnumber(Student *ST,int low , int high){
	int  axs=0;
	if(low<high){
		axs=numberQuickSort(ST,low,high);
		ALLnumber(ST,low,axs-1);
		ALLnumber(ST,axs+1,high);
	}
}
	//排姓名
int nameQuickSort(Student *ST,int low,int high){
	Student AXIS; 
	int  axis=(low+high)/2;	
	strcpy(AXIS.gender,ST[axis].gender);
	strcpy(AXIS.name,ST[axis].name);
	AXIS.number=ST[axis].number;
	AXIS.score1=ST[axis].score1;
	AXIS.score2=ST[axis].score2;
	AXIS.TOTALscore=ST[axis].TOTALscore;	
	assign(ST,ST,axis,high);
	while(low<high){
		while(low<high&&strcmp(ST[low].name,AXIS.name)<=0) 	low++;		
		assign(ST,ST,high,low);
		while(low<high&&strcmp(ST[high].name,AXIS.name)>=0)	high--;	
		assign(ST,ST,low,high);
	}
	strcpy(ST[low].gender,AXIS.gender);
	strcpy(ST[low].name,AXIS.name);
	ST[low].number=AXIS.number;
	ST[low].score1=AXIS.score1;
	ST[low].score2=AXIS.score2;
	ST[low].TOTALscore=AXIS.TOTALscore;
	return low;
}
	 
void ALLname(Student *ST,int low , int high){
	int  axs=0;
	if(low<high){
		axs=nameQuickSort(ST,low,high);
		ALLname(ST,low,axs-1);
		ALLname(ST,axs+1,high);
	}
}
	//排成绩
int scoreQuickSort(Student *ST,int low,int high){
	Student AXIS; 
	int  axis=(low+high)/2;	
	strcpy(AXIS.gender,ST[axis].gender);
	strcpy(AXIS.name,ST[axis].name);
	AXIS.number=ST[axis].number;
	AXIS.score1=ST[axis].score1;
	AXIS.score2=ST[axis].score2;
	AXIS.TOTALscore=ST[axis].TOTALscore;	
	assign(ST,ST,axis,high);
	while(low<high){
		while(low<high&&ST[low].TOTALscore<=AXIS.TOTALscore) low++;	
		assign(ST,ST,high,low);
		while(low<high&&ST[high].TOTALscore>=AXIS.TOTALscore) high--;
		assign(ST,ST,low,high);
	}
	strcpy(ST[low].gender,AXIS.gender);
	strcpy(ST[low].name,AXIS.name);
	ST[low].number=AXIS.number;
	ST[low].score1=AXIS.score1;
	ST[low].score2=AXIS.score2;
	ST[low].TOTALscore=AXIS.TOTALscore;
	return low;	
}
void ALLscore(Student *ST,int low , int high){
	int  axs=0;
	if(low<high){
		axs=scoreQuickSort(ST,low,high);
		ALLscore(ST,low,axs-1);
		ALLscore(ST,axs+1,high);
	}
}
//**********************以上为快排******************************* 
//排序 方法二稳定的简单排序算法（直接插入、冒泡法、归并排序、基数排序）:冒泡 
     //排学号 
void numberBubbleSort(Student *ST){
	int i , j;
	for(i=0;i<num;i++){
		for(j=num-1;j>i;j--){
			if(ST[j-1].number>ST[j].number) 	exchange(ST,ST,j,j-1);
		}
	}
} 

	//排姓名
void  nameBubbleSort(Student *ST){
	int i , j;
	for(i=0;i<num;i++){
		for(j=num-1;j>i;j--){
			if(strcmp(ST[j-1].name,ST[j].name)>0)	exchange(ST,ST,j,j-1);		
		}
	}	
}
 
	//排成绩
void scoreBubbleSort(Student *ST){
	int i , j;
	for(i=0;i<num;i++){
		for(j=num-1;j>i;j--){
			if(ST[j-1].TOTALscore>ST[j].TOTALscore) exchange(ST,ST,j,j-1);
		}	
	}
} 

//********************以上为冒泡排序***************************
 
int main(){
	Student ST[50];
	int i , j=3 , c=3 , L1;
	char L2[20]="NULL";
	char file[60];
	printf("请输入文件");
	scanf("%s",file); 
	c=Asave(file,ST);
	if(c==0) return 0;
//*****************以下为：排序******************** 
//	numberBubbleSort(ST);       // 方法一：冒泡排序 
//	nameBubbleSort(ST);
//	scoreBubbleSort(ST);
//////////////////////////////////////////////////////////////			
	ALLnumber(ST,0,num-1);			// 方法二：快速排序
//	ALLname(ST,0,num-1);
//	ALLscore(ST,0,num-1);
//****************以上为：排序******************** 
	printf("查询请输入1，结束请输入0");
	printf("\n"); 
	scanf("%d",&i);
	if(i==0){
		printf("输入为0，结束");
		return 0;
	}
	while(i!=0&&i!=1){
		printf("输入错误，请重新输入（查询请输入1，结束请输入0）");
		printf("\n");
		scanf("%d",&i);
		if(i=1) break;
		if(i=0){
			printf("输入为0，结束");
			return 0;
		} 
	}
	while(c!=0){		
		while(j!=0){
			printf("通过学号查询请输入1    通过姓名查询请输入2");
			printf("\n"); 
			scanf("%d",&j);
			if(j!=1&&j!=2){
				printf("\n"); 
				printf("输入错误，请重新输入");
				continue;	
			}
			if(j==1){
				printf("请输入学号");
				printf("\n");   
				scanf("%d",&L1);
				break;
			}
			else{
				printf("请输入姓名");
				printf("\n"); 
				scanf("%s",L2);
				break;	
			}
		}
//**********以下为：查询的函数
	find(ST,L1,L2); 			// 方法一：对姓名的普通查找、 对学号的顺序查找 
//	SUEresult(ST,L1,L2,1,num);	// 方法二：对姓名的普通查找、对学号的折半查找
//**********以上为：查询的函数
	printf("\n");
	printf("结束请输入0   继续查询请输入除0之外的任意数字");
	printf("\n");
	scanf("%d",&c);
	if(c==0) return 0;
	printf("*******************************************\n");
	}
	return 0;
}
