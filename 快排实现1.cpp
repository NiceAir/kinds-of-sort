#include<stdio.h>

void qsort(int *array, int len)
{
    int value, start, end;
    if (len <= 1) 
        return; 
    value = array[0]; 
    start = 0; 
    end = len - 1; 
    while (start < end) { 
        for (; start < end; --end) { 
            if (array[end] < value) { 
                array[start++]=array[end];  
                break; 
            } 
        } 
        for (; start < end; ++start) { 
            if (array[start] > value)
            {
                array[end--]=array[start]; 
                break;
            }
        }
    }
     array[start]=value; 
    qsort(array, start );
    qsort(array+start+1 , len-start-1 );
}

int main()
{
int a[10]={9,8,7,3,4,5,6,1,2,0};
qsort(a,10);
int i;
for(i = 0; i < 10; i++)
{
printf("%d ", a[i]);
} 
}
