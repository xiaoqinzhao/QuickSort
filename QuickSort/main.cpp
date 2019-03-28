#include<stdio.h>

typedef int ElemType;

void QuickSort(ElemType arr[],int start,int end);
int Sort(ElemType arr[],int low,int high,int key);
void Exchange(ElemType *a,ElemType *b);
void print(ElemType arr[],int len);
void findmin(ElemType arr[],int *low,int *high,int *key);
void findmax(ElemType arr[],int *low,int *high,int *key);

int main()
{
	ElemType arr[]={11,26,2,5,158,176,2,4,6};
	int len=sizeof(arr)/sizeof(ElemType);
	print(arr,len);
	QuickSort(arr,0,len-1);
	printf("Quick Sort ....\n");
	print(arr,len);
	return 0;
}

void QuickSort(ElemType arr[],int start,int end)
{
	if(start<end)
	{
	int key=(start+end)/2;
	key=Sort(arr,start,end,key);
	QuickSort(arr,start,key-1);
	QuickSort(arr,key+1,end);
	}
}
int Sort(ElemType arr[],int low,int high,int key)
{
	findmin(arr,&low,&high,&key);
	return key;
}
void findmin(ElemType arr[],int *low,int *high,int *key)
{
	if(low<high)
	{
		int pos=-1;
	for(int i=*high;i>=*low;i--)
	{
		if(arr[i]<=arr[*key])
		{
			pos=i;
			break;
		}
	}
	if(pos!=-1)
	{	
		*high=pos;
		Exchange(&arr[*high],&arr[*key]);
		*key=pos;
		int value=*high;
		value--;
		*high=value;

		findmax(arr,low,high,key);
	}
	}
}

void findmax(ElemType arr[],int *low,int *high,int *key)
{
	if(low<high)
	{
	int pos=-1;
	for(int i=*low;i<=*high;i++)
	{
		if(arr[i]>=arr[*key])
		{
			pos=i;
			break;
		}
	}
	if(pos!=-1)
	{
		*low=pos;
		Exchange(&arr[*low],&arr[*key]);
		*key=pos;

		int value=*low;
		value++;
		*low=value;

		findmin(arr,low,high,key);
	}
	}
}

void Exchange(ElemType *a,ElemType *b)
{
	ElemType temp=*a;
	*a=*b;
	*b=temp;
}

void print(ElemType arr[],int len)
{
	for(int i=0;i<len;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
}