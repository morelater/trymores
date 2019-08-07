#ifndef  __SORT_H
#define  __SORT_H


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <malloc.h>
#include <math.h>

typedef struct stack
{
	int *data;
	int top;
}Stack,*pStack;

void BubbleSort(int *arr,int len);

void SelectSort(int *arr,int len);

void InsertSort(int *arr,int len);

void ShellSort(int *arr,int len);

void QuickSort(int *arr,int len);

void HeapSort(int *arr,int len);

void MegerSort(int *arr,int len);

void Show(int *arr,int len);







#endif