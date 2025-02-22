/************************************************************************************
* Program: Sorter Class
* Programmer: Daudi MLENGELA (dmlengela@cnm.edu)
* Date: Feb 28th 2022
* Purpose: Sorting
************************************************************************************/
#include "Sort.h"
#include<iostream>

void Sort::bubbleSort(int* array, int size){
    for (int i = 0; i < size - 1; i++)
        for (int j = size - 1; j > i; j--)
            if (array[j] < array[j - 1])
                std::swap(array[j], array[j - 1]);
}

void Sort::combSort(int* array, int size){
    int gap = size;
    bool flag = true;

    while (gap != 1 || flag == true){
        gap = (gap * 10) / 13;
        if (gap < 1)
            gap = 1;

        flag = false;
        for (int i = 0; i < size - gap; i++){
            if (array[i] > array[i + gap]){
                std::swap(array[i], array[i + gap]);
                flag = true;
            }
        }
    }

}
void Sort::goofySort(int* array, int size){
    int index = 1;
    while (true)
    {
        if (array[index] >= array[index - 1])
        {
            /********************************************
            * Already in the right order, step forward
            *********************************************/ 
            if (++index == size) {
                break;
            }
        }else{
            std::swap(array[index], array[index - 1]);

            /********************************************
            * If there's no previous element, step forward
            * otherwise step back one element
            *********************************************/ 

            if (index - 1 == 0) {
                index++;
            }
            else {
                index--;
            }
        }
    }
}
void Sort::inPlaceMergeSort(int* array, int size){
    mergeSort(array, 0, size - 1);
}

void Sort::selectionSort(int* array, int size){
    for (int i = 0; i < size - 1; i++){
        int minIndex = -1;
        for (int j = i; j < size; j++)
        if (minIndex == -1 || array[j] < array[minIndex])
                minIndex = j;
        if (minIndex != i)
            std::swap(array[minIndex], array[i]);
    }
}
void Sort::insertionSort(int* array, int size){
    for (int i = 1; i < size; i++) {
        int value = array[i];
        int iterator = 0;
        for (iterator = i - 1; iterator >= 0 && value < array[iterator]; iterator--)
            array[iterator + 1] = array[iterator];
        array[iterator + 1] = value;
    }

}
void Sort::shakerSort(int* array, int size){
    bool swapped = true;
    int start = 0;
    int end = size - 1;

    while (swapped){
        swapped = false;
        for (int i = start; i < end; ++i){
            if (array[i] > array[i + 1]){
                std::swap(array[i], array[i + 1]);
                swapped = true;
            }
        }
        if (!swapped)
            break;
        swapped = false;
        --end;

        for (int i = end - 1; i >= start; --i) {
            if (array[i] > array[i + 1]) {
                std::swap(array[i], array[i + 1]);
                swapped = true;
            }
        }
        ++start;
    }
}
void Sort::shellSort(int* array, int size){
    for (int gapSize = size / 2; gapSize > 0; gapSize /= 2){
        for (int i = gapSize; i < size; i++){
            int temp = array[i];
            int j = i;

            while (j >= gapSize && array[j - gapSize] > temp){
                array[j] = array[j - gapSize];
                j -= gapSize;
            }
            array[j] = temp;
        }
    }
}

void Sort::merge(int* array, int start, int middle, int end){
    int start2 = middle + 1;
    if (array[middle] <= array[start2]) {
        return;
    }
    while (start <= middle && start2 <= end){
        if (array[start] <= array[start2]){
            start++;
        }else{
            int value = array[start2];
            int index = start2;

            while (index != start){
                array[index] = array[index - 1];
                index--;
            }
            array[start] = value;

            start++;
            middle++;
            start2++;
        }
    }
}
void Sort::mergeSort(int* array, int left, int right){
    if (left < right){
        int middle = left + (right - left) / 2;

        mergeSort(array, left, middle);
        mergeSort(array, middle + 1, right);

        merge(array, left, middle, right);
    }
}
int Sort::partition(int* array, int low, int high){
    int pivot = array[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (array[j] < pivot)
        std::swap(array[++i], array[j]);
        std::swap(array[i + 1], array[high]);
        return(i + 1);
    }
}
void Sort::quickSort(int* array, int size) {
    quickSort(array, 0, size - 1);
}
void Sort::quickSort(int* array, int first, int last){
    int lower = first + 1, upper = last;
    std::swap(array[first], array[(first + last) / 2]);
    int bound = array[first];
    while (lower <= upper) {
        while (bound > array[lower])
            lower++;
        while (bound < array[upper])
            upper--;
        if (lower < upper)
            std::swap(array[lower++], array[upper--]);
        else lower++;
    }
    std::swap(array[upper], array[first]);
    if (first < upper - 1)
        quickSort(array, first, upper - 1);
    if (upper + 1 < last)
        quickSort(array, upper + 1, last);
}
