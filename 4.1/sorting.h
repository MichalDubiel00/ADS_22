#ifndef _SORTING_H_
#define _SORTING_H_

#include <vector>
#include <iostream>
#include <string>

using namespace std;

namespace sorting {
  
  //************
  // QuickSort *
  //************
  int median3(vector<int>& arr, int left, int right);
  int Partition(vector<int>& arr, int left, int right);
  void QuickSort(vector<int> &arr, int left, int right);
  void InsertionSort(vector<int>& arr ,int left ,int right);
  void HybridQuickSort(vector<int>& arr, int left, int right);
  
  //************
  // MergeSort *
  //************
  void Merge(vector<int> &a, vector<int> &b,int low, int pivot, int high);
  void MergeSort(vector<int> &a, vector<int> &b, int low, int high);

  //************************
  // Natuerliche Mergesort *
  //************************
  void natMerge(vector<int>& a, vector<int>& b, int low, int pivot, int high);
  void natMergeSort(vector<int> &a, vector<int> &b);

  //************
  // Heapsort  *
  //************
  void HeapSort(vector<int> &a, int n);

  //************
  // Shellsort *
  //************
  void hibbard(vector<int>& h, int length);

  void ShellSort_2n(vector<int> &a, int n);
  void ShellSort_3n(vector<int> &a, int n);

  //*******************
  // Helper functions *
  //*******************
  void randomizeVector(vector<int> &array, int n);
  
 }
#endif 
