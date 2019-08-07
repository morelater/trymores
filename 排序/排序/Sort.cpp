#include "Sort.h"


void Swap(int *a,int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

//√∞≈›≈≈–Ú∑®
void BubbleSort(int *arr,int len)
{
	for(int i = 0;i < len;i++)
	{
		for(int j = 0;j <len - i - 1;j++)
		{
			if(arr[j] > arr[j + 1])
			{
				Swap(&arr[j],&arr[j + 1]);
			}
		}
	}
}

//—°‘Ò≈≈–Ú∑®
void SelectSort(int *arr,int len)
{
	int min = 0;
	for(int i = 0; i < len;i++)
	{
		min = i;
		for(int j = i + 1;j < len;j++)
		{
			if(arr[min] > arr[j])
			{
				min = j;		
			}
		}
		if(min != i)
		{
			Swap(&arr[min],&arr[i]);
		}
		
	}

}

//≤Â»Î≈≈–Ú∑®
void InsertSort(int *arr,int len)
{
	for(int i = 1;i < len;i++)
	{
		int tmp = arr[i];
		int j;
		for(j = i - 1;j >= 0;j--)
		{
			if(arr[j] > tmp)
			{
				arr[j + 1] = arr[j];
			}
			else
			{
				break;
			}
		}
		 arr[j + 1]= tmp;
	}
}

//œ£∂˚≈≈–Ú
void Shell(int *arr,int len ,int wide)
{
	for(int i = wide;i < len;i ++)
	{
		int tmp = arr[i];
		int j ;
		for(j = i - wide;j >= 0;j -= wide)
		{
			if(arr[j] > tmp)
			{
				arr[j + wide] = arr[j];
			}
			else
			{
				break;
			}
		}
		arr[j + wide] = tmp;
	}
}

void ShellSort(int *arr,int len)
{
	int d[] = {5,3,1};
	for(int i = 0;i < sizeof(d)/sizeof(d[0]);i++)
	{
		Shell(arr,len,d[i]);
	}
}


//øÏÀŸ≈≈–Ú
int OnceQuick(int *arr,int start,int end)
{
	int i = start;
	int j = end ;
	int tmp = arr[start];

	while(i < j)
	{
		while(i < j && arr[j] > tmp)
		{
			j--;
		}
		if(i == j)
		{
			break;
		}

		arr[i] = arr[j];

		while(i < j && arr[i] < tmp)
		{
			i++;
		}
		if(i == j)
		{
			break;
		}

		arr[j] = arr[i];
	}
	arr[i] = tmp;

	return i;
}

void Quick(int *arr,int start,int end)
{
	int pos = OnceQuick(arr,start,end);
	
	if(pos - start > 1)
	{
		OnceQuick(arr,start,pos - 1);
	}
	if(end - pos > 1)
	{
		OnceQuick(arr,pos + 1,end);
	}
}

void Quick2(int *arr,int start,int end)
{
	Stack st;
	int size = log10((double)(end - start + 1)) / log10((double)2) + 1;
	st.data = (int *)malloc(sizeof(int) * size);
	assert(st.data != NULL);
	st.top = 0;

	st.data[st.top++] = start;
	st.data[st.top++] = end;

	while(st.top != 0)
	{
		end = st.data[--st.top] ;
		start = st.data[--st.top];
		int pos = OnceQuick(arr,start,end);

		if(pos - start > 1)
		{
			st.data[st.top++] = start;
			st.data[st.top++] = pos - 1;
		}
		if(end - pos > 1)
		{
			st.data[st.top++] = pos + 1;
			st.data[st.top++] = end;
		}
	}

}

void QuickSort(int *arr,int len)
{
	Quick2(arr,0,len - 1);
}



//∂—≈≈–Ú
void Adjust(int *arr,int len,int start)
{
	int tmp = arr[start];
	int i = start * 2 + 1;
	while(i < len)
	{
		if(i + 1 < len && arr[i + 1] > arr[i])
		{
			i += 1;
		}

		if(arr[i] < tmp)
		{
			break;
		}

		arr[start] = arr[i];
		start = i;
		i = 2 * start + 1;
	}
	arr[start] = tmp;
}
void CreateHeap(int *arr,int len)
{
	for(int i = (len - 2)/2;i >= 0;i--)
	{
		Adjust( arr, len,i);
	}
}
void HeapSort(int *arr,int len)
{
	CreateHeap(arr,len);
}

//∂˛¬∑πÈ≤¢≈≈–Ú
void Meger(int *arr,int len,int wide)
{
	int l1 = 0;
	int h1 = l1 + wide - 1;
	int l2 = h1 + 1;
	int h2 = l2 + wide - 1 > len - 1 ? len - 1 : l2 + wide - 1;

	int *brr = (int *)malloc(sizeof(int) * len);
	int index = 0;

	while(l1 < len)
	{
		while(l1 <= h1 && l2 <= h2)
		{
			if(arr[l1] < arr[l2])
			{
				brr[index++] = arr[l1++];
			}
			else
			{
				brr[index++] = arr[l2++];
			}

		}
		while(l1 <= h1)
		{
			brr[index++] = arr[l1++];
		}
		while(l2 <= h2)
		{
			brr[index++] = arr[l2++];
		}

		l1 = h2 +1;
		h1 = l1 + wide -1 > len - 1 ? len - 1 : l1 + wide - 1;
		l2 = h1 + 1;
		h2 = l2 + wide -1 > len - 1 ? len - 1 : l2 + wide - 1;

	}

	for(int i = 0;i < len;i++)
	{
		arr[i] = brr[i];
	}
	free(brr);
}
void MegerSort(int *arr,int len)
{
	for(int i = 1;i < len;i *= 2)
	{
		Meger(arr,len,i);
	}
	
}

void Show(int *arr,int len)
{
	printf("after sort diplay:\n");
	for(int i = 0;i < len;i++)
	{
		printf("%3d",arr[i]);
	}
	printf("\n");
}