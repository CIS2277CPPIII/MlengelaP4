
/************************************************************************************
* Program: Sorter Class
* Programmer: Daudi MLENGELA (dmlengela@cnm.edu)
* Date: Feb 28th 2022
* Purpose: Sorting
************************************************************************************/

#ifndef SORT_H
#define SORT_H
#include<algorithm>

class Sort
{
public:
	Sort() = default;
	void bubbleSort(int* array, int size);
	void combSort(int* array, int size);
	void goofySort(int* array, int size);
	void inPlaceMergeSort(int* array, int size);
	void quickSort(int* array, int size);
	void selectionSort(int* array, int size);
	void insertionSort(int* array, int size);
	void shakerSort(int* array, int size);
	void shellSort(int* array, int size);
private:
	void merge(int* array, int start, int middle, int end);
	void mergeSort(int* array, int left, int right);
	int partition(int* array, int low, int high);
	void quickSort(int* array, int low, int high);
};

#endif // !SORT_H
