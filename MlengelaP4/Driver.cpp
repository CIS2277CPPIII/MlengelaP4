/************************************************************************************
* Program: Sorter Class
* Programmer: Daudi MLENGELA (dmlengela@cnm.edu)
* Date: Feb 28th 2022
* Purpose: Sorting
************************************************************************************/
#include<chrono>
#include<iostream>
#include<iomanip>
#include<string>
#include<vector>
#include<fstream>
#include<sstream>
#include"Sort.h"

using std::string;
using std::vector;
using namespace std::chrono;

static void printArray(int* array, int size){
    for (int i = 0; i < size; i++) {
        std::cout << (i == 0 ? "{" : "") << " " << array[i];
        std::cout << " }\n";
    }
}
static bool readFile(const string& fileName, int n, int* values){
    std::ifstream in(fileName);
    if (!in) {
        return(false);
    }
    string line;
    for (int i = 0; i < n; i++){
        getline(in, line);
        values[i] = atoi(line.c_str());
    }
    return(true);
}
enum SortType {
    Bubble, Comb, Goofy, InPlaceMerge, Insertion, Quick, Selection, Shaker, Shell
};
static string toString(SortType type) {
    switch (type)
    {
    case SortType::Bubble: return("bubbleSort");
    case SortType::Comb: return("combSort");
    case SortType::Goofy: return("goofySort");
    case SortType::InPlaceMerge: return("inPlaceMergeSort");
    case SortType::Insertion: return("insertionSort");
    case SortType::Quick: return("quickSort");
    case SortType::Selection: return("selectionSort");
    case SortType::Shaker: return("shakerSort");
    case SortType::Shell: return("shellSort");
    }
    return("N/A");
}
static void runTest(std::ostream& out, Sort& sorter,const string& name,SortType type, int* originalValues,
    int* values,int  size){
    /*****************************************************
    * Copy the original, unsorted values to 'values'
    ******************************************************/ 

    for (int i = 0; i < size; i++)
    values[i] = originalValues[i];

    std::cout << "Starting " << toString(type) << "\n";
    auto start{ high_resolution_clock::now() };

    switch (type)
    {
    case SortType::Bubble: sorter.bubbleSort(values, size);       break;
    case SortType::Comb: sorter.combSort(values, size);         break;
    case SortType::Goofy: sorter.goofySort(values, size);        break;
    case SortType::InPlaceMerge: sorter.inPlaceMergeSort(values, size); break;
    case SortType::Insertion: sorter.insertionSort(values, size);    break;
    case SortType::Quick: sorter.quickSort(values, size);        break;
    case SortType::Selection: sorter.selectionSort(values, size);    break;
    case SortType::Shaker: sorter.shakerSort(values, size);       break;
    case SortType::Shell: sorter.shellSort(values, size);        break;
    }

    auto stop{ high_resolution_clock::now() };
    auto ms{ duration_cast<milliseconds>(stop - start).count() };

    double seconds = ms / 1000.0;

    std::cout << "Finished with " << toString(type) << " with an elapsed time of " <<
    seconds << " seconds\n";
    out << std::setw(20) << std::left << name << "   " << seconds << "\n";

    /*****************************************************************
    * Change 'false' to 'true' to output the first few
    * elements of the array - they should be sorted at this point
    ******************************************************************/
    if (false) {
        printArray(values, 10);
    }

}
/*
const int    Size     = 200000;
const string FILENAME = "../BJTest200K.txt";
*/

/*
const int    Size     = 100000;
const string FILENAME = "../BJTest100K.txt";
*/

const int    Size = 50000;
const string FILENAME = "BJTest50K.txt";

int main() {

    /**********************************************
    * Header
   ***********************************************/
    std::cout << "Student: Daudi Mlengela\n";
    std::cout << "C++ Program 4 - Sorting\n\n";
   
    int* Nums = new int[Size];
    int* TmpNums = new int[Size];

    if (!readFile(FILENAME, Size, Nums))
    {
        std::cout << "Could not read file: [" << FILENAME << "]\n";
        return(1);
    }

    /*************************************************************
    * Change 'false' to 'true' to see the first few elements
    * in 'Nums', which should be unsorted at this point
    **************************************************************/ 

    if (false) {
        printArray(Nums, 10);
    }
    std::ofstream out("output.txt");

    if (!out){
        std::cout << "Could not open output file\n";
        return(1);
    }
    out <<
        "Name of sort function  Elapsed time in secs.msec\n" <<
        "---------------------  -------------------------\n";

    Sort sorter;

    runTest(out, sorter, "bubblesort", SortType::Bubble, Nums, TmpNums, Size);
    runTest(out, sorter, "comb sort", SortType::Comb, Nums, TmpNums, Size);
    runTest(out, sorter, "goofy sort", SortType::Goofy, Nums, TmpNums, Size);
    runTest(out, sorter, "in-place merge", SortType::InPlaceMerge, Nums, TmpNums, Size);
    runTest(out, sorter, "insertion sort", SortType::Insertion, Nums, TmpNums, Size);
    runTest(out, sorter, "quick sort", SortType::Quick, Nums, TmpNums, Size);
    runTest(out, sorter, "selection sort", SortType::Selection, Nums, TmpNums, Size);
    runTest(out, sorter, "shaker sort", SortType::Shaker, Nums, TmpNums, Size);
    runTest(out, sorter, "shell sort", SortType::Shell, Nums, TmpNums, Size);

    delete[] Nums;
    delete[] TmpNums;

    /*********************************************************
    * Say Goodbye
    **********************************************************/
    std::cout << "\n\nThanks for watching my Sorting program. Goodbye!\n\n";
    
	return 0;
}