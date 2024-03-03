#include "sorting.h"
#include <iostream>
#include <fstream>


using namespace std;
namespace sorting {
	int median3(vector<int>& arr, int left, int right)
	{
		int mid = (left + right) / 2;
		if (arr[mid] < arr[left])
			swap(arr[mid], arr[left]);
		if (arr[right] < arr[left])
			swap(arr[right], arr[left]);
		if (arr[right] < arr[mid])
			swap(arr[mid], arr[right]);
		swap(arr[mid], arr[right]);
			
		int pivot = arr[right];
		return pivot;
	}
	int Partition(vector<int>& arr, int left, int right)
	{
	
		//int pivot = median3(arr,left,right);
		int pivot = arr[right];
		int i = left - 1;
		for (int j = left; j < right; j++)
		{
			if (arr[j]<= pivot)
			{
				i++;
				swap(arr[i], arr[j]);
			}
		}
		swap(arr[i + 1], arr[right]);
		return i+1;
	}
	//************
	// QuickSort *
	//************      
	void QuickSort(vector<int>& arr, int left, int right) //avg O(n*logn)
	{
		if (left < right)
		{
			int q = Partition(arr, left, right);
			QuickSort(arr, left, q - 1);
			QuickSort(arr, q+1, right);

		}

	}

	void InsertionSort(vector<int>& arr, int low, int n) //worst case O(n^2) best case O(n) avg O(N^2/4))
	{
		for (int i = low + 1; i < n + 1; i++)
		{
			int val = arr[i];
			int j = i;
			while (j > low && arr[j - 1] > val)
			{
				arr[j] = arr[j - 1];
				j -= 1;
			}
			arr[j] = val;
		}
	}

	void HybridQuickSort(vector<int>& arr, int left, int right)
	{
		//ofstream quicksort_measurement_n;
		//quicksort_measurement_n.open("hybridquicksort_n.txt", ios::out | ios::app);
		int n = 0, avgInsertion = 0, avgQuickSort = 0;
		while (left < right)
		{
			n = right-left+1;
			//avgInsertion = (n * n) / 4;
			//avgQuickSort = n * log2(n);
			if ( n<= 10)
			{
				//cout << n << endl;
				//quicksort_measurement_n << n << endl;
				InsertionSort(arr, left, right);
				break;
			}
			else
			{
				int pivot = Partition(arr, left, right);

				if (pivot - left < right - pivot)
				{
					HybridQuickSort(arr, left, pivot - 1);
					left = pivot + 1;
				}
				else
				{


					HybridQuickSort(arr, pivot + 1, right);
					right = pivot - 1;
				}
			}
		}

	}

	//************
	// MergeSort *  //O(N/2 * log2N)
	//************
	void Merge(vector<int>& a, vector<int>& b, int low, int pivot, int high)  
	{
		int leftEnd = pivot-1;
		int tmpPos = low;
		int n = high - low + 1;
		while (low <= leftEnd && pivot <= high)
		{
			if (a[low] <= a[pivot])
			{
				b[tmpPos] = a[low];
				low++;
			}
			else
			{
				b[tmpPos] = a[pivot];
				pivot++;
			}
			tmpPos++;
		}
		while (low <= leftEnd)
			b[tmpPos++] = a[low++];
		while (pivot <= high)
			b[tmpPos++] = a[pivot++];
		int i = 0;
		while (i < n)
		{
			a[high] = b[high];
			high--;
			i++;
		}
	}


	void MergeSort(vector<int>& a, vector<int>& b, int low, int high) 
	{
		if (low < high)
		{
			int middle = (low + high) / 2;
			MergeSort(a, b, low, middle);
			MergeSort(a, b, middle + 1, high);
			Merge(a, b, low, middle + 1, high);
		}
	}

	void natMerge(vector<int> &a, vector<int> &b, int left, int middle, int right) 
	{

	}

	void natMergeSort(vector<int>& a, vector<int>& b)
	{
		int n = a.size() - 1;
		int left = 0;
		do {
			int right = -1;
			while (right < n) {
				left = right + 1;
				int middle = left;
				while (middle < n && a[middle + 1] >= a[middle]) {
					middle = middle + 1;
				}
				if (middle < n) {
					right = middle + 1;
					while (right < n && a[right + 1] >= a[right]) {
						right = right + 1;
					}
					Merge(a, b, left, middle + 1, right);
				}
				else {
					right = n;
				}
			}
		} while (left != 0);
	}


	//************
	// Heapsort  * //2N *log2N - O(N * log2log2N) O(n log n) unstable
	//************
	void heapify(vector<int> &a, int n, int i)
	{
		int lar = i;
		int left = 2 * i + 1;
		int right = 2 * i + 2;
		if (left < n && a[left] > a[lar])
			lar = left;

		if (right < n && a[right] > a[lar])
			lar = right;

		if (lar != i)
		{
			swap(a[i], a[lar]);
			heapify(a, n, lar);
		}
	}


	void HeapSort(vector<int> &arr, int n) 
	{
		for (int i = n / 2 - 1; i >= 0; i--)
			heapify(arr, n, i);

		for (int i = n - 1; i > 0; i--) {

			swap(arr[0], arr[i]);

			heapify(arr, i, 0);
		}
	}

	//************
	// Shellsort *  // <= O(n2)
	//************
	void hibbard(vector<int>& h, int length) {
		h.push_back(-1);
		for (int i = 1; i <= 5 * length; i = 2 * i + 1) // ausgangskriterien ? 
			h.push_back(i);
	}
	void abstand(vector<int>& h, int length) {
		h.push_back(-1);
		for (int i = 1; i <= 8 * length; i = 3 * i + 1) // ausgangskriterien ? 
			h.push_back(i);
	}

	void ShellSort_2n(vector<int> &a, int n)
	{
		vector<int> hib;
		hibbard(hib, n);
		int hib_start = 0;

		while (hib.at(hib_start) < n)
			hib_start++;

		while (hib.at(hib_start) != -1) {
			int gap = hib.at(hib_start);
			for (int i = gap; i < n; i++) {
				int tmp = a[i];
				int j = i;
				for (j; j >= gap && tmp < a[j - gap]; j -= gap) {
					a[j] = a[j - gap];
				}
				a[j] = tmp;
			}
			hib_start--;
		}
	}


	void ShellSort_3n(vector<int>& a, int n)
	{
		vector<int> abst;
		abstand(abst, n);
		int abst_start = 0;

		while (abst.at(abst_start) < n)
			abst_start++;

		while (abst.at(abst_start) != -1) {
			int gap = abst.at(abst_start);
			for (int i = gap; i < n; i++) {
				int tmp = a[i];
				int j = i;
				for (j; j >= gap && tmp < a[j - gap]; j -= gap) {
					a[j] = a[j - gap];
				}
				a[j] = tmp;
			}
			abst_start--;
		}
	}


  void randomizeVector(vector<int> &array, int n) {
    array.resize(n);

    for(unsigned int i=0;i<array.size();i++)
      array[i]=rand() % 1000000;
  }


}





