
#include "Sort.h"


int main()
{

	int arr[] ={9,5,11,14,32,16,8,23,2} ;
	int len = sizeof(arr)/sizeof(int);

	//Bubble(arr, len);

	HeapSort(arr, len);
//	MegerSort(arr, len);
	Show(arr, len);
	
	return 0;
}