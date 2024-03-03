#define CATCH_CONFIG_RUNNER
#include "catch.h"

#include <iostream>
#include <omp.h>

#include"hashtable.h"

#include "sorting.h"

using namespace std;

//benchmark functions
void benchmark_quicksort();
void benchmark_hybridquicksort();
void benchmark_mergesort();
void benchmark_natmergesort();

void benchmark_heapsort();
void benchmark_shellsort_2n();
void benchmark_shellsort_3n();


int main(int argc, char** argv) {
	
	std::vector<int> Vteset{ 8,2,9,1,3,7,6 };
	sorting::QuickSort(Vteset,0,6);
  Catch::Session().run();
  int hashvalue = 0;
  cout << "HashTabelle: " << '\n' << "waehlen sie eine Kollisionsstrategie:\n1.Quadratisches Sondieren\n2.Lineares Sondieren\n3.Doppeltes Hashing<"<<endl;
  do
  {
	  cout << ">? ";
	  cin >> hashvalue;
  } while (hashvalue >3 || hashvalue <= 0 );

  ////HashTable hash(1000);
  ////hash.setHv(hashvalue);
  ////for (int i = 0; i < 200; i++)
  ////{
	////  hash.insert(rand() % 500 + 1001);
	////  
  ////}
  //hash.print();
  HashTable hash(5,0.7);
 


  hash.insert(7);
  hash.insert(15);
  hash.insert(14);
  hash.insert(5);
  hash.insert(24);
  hash.insert(54);
  hash.print();

  cout << "Kollisionen: " << hash.getCollisionCount() << endl;
  std::cin.get();

  std::cout << "\nPress Enter to run measurement" << std::endl;
  std::cin.get();
 // for (int i = 0; i < 9; i++)
 // {
//	  cout << "Quicksort:" << i << endl;
 //     benchmark_quicksort();
 // }
 // for (int i = 0; i < 9; i++)
 // {
//	  cout << "HybridQuicksort:" << i << endl;
 //
//	  benchmark_hybridquicksort();
 //
 // }
 // for (int i = 0; i < 9; i++)
 // {
//	  cout << "mergesort:" << i << endl;
 //
//	  benchmark_mergesort();
 //
 // }
  for (int i = 0; i < 10; i++)
  {
	  cout << "natmergesort:" << i << endl;

	  benchmark_natmergesort();

  }
 // for (int i = 0; i < 9; i++)
 // {
//	  cout << "heapsort:" << i << endl;
 //
//	  benchmark_heapsort();
 //
 // }
 // for (int i = 0; i < 9; i++)
 // {
//	  cout << "shellsort2:" << i << endl;
 //
//	  benchmark_shellsort_2n();
 //
 // }
 // for (int i = 0; i < 9; i++)
 // {
//	  cout << "shellsort3: " << i << endl;
 //
//	  benchmark_shellsort_3n();
 // }

  
  return 0;
}


//executes benchmark for quicksort
void benchmark_quicksort() {

  //file stream
  ofstream quicksort_measurement;
  quicksort_measurement.open("quicksort.txt", ios::out | ios::app);

  //benchmark parameters / variables
  double dtime;
  int n_start = 1000;
  int n_step = 1000;
  int n_end = 1000000;

  vector<int> V;


  //actual benchmark loop
  for (int n = n_start; n<=n_end; n += n_step) {
	
	//"progress bar"
    //std::cout << "Running Quicksort with n: " << n << std::endl;

	//generate n random integers
	sorting::randomizeVector(V, n);

	//start measurement
    dtime = omp_get_wtime();
    
	//execzute sorting algorithm
    sorting::QuickSort(V,0,V.size()-1);

	//stop time
    dtime = omp_get_wtime() - dtime;

	//write to file
    quicksort_measurement << n << "\t" << setprecision(10) << scientific << dtime << endl;
  }

  //close file handle
  quicksort_measurement.close();
}

void benchmark_hybridquicksort(){

	//file stream
	ofstream hybridquicksort_measurement;
	hybridquicksort_measurement.open("hybridquicksort.txt", ios::out | ios::app);

	//benchmark parameters / variables
	double dtime;
	int n_start = 1000;
	int n_step = 1000;
	int n_end = 1000000;

	vector<int> V;

	//actual benchmark loop
	for (int n = n_start; n <= n_end; n += n_step) {

		//"progress bar"
	//	std::cout << "Running Hybriduicksort with n: " << n << std::endl;

		//generate n random integers
		sorting::randomizeVector(V, n);

		//start measurement
		dtime = omp_get_wtime();

		//execzute sorting algorithm
		sorting::HybridQuickSort(V, 0, V.size() - 1);

		//stop time
		dtime = omp_get_wtime() - dtime;

		//write to file
		hybridquicksort_measurement << n << "\t" << setprecision(10) << scientific << dtime << endl;
	}

	//close file handle
	hybridquicksort_measurement.close();
}

void benchmark_mergesort() {

	//file stream
	ofstream mergesort_measurement;
	mergesort_measurement.open("mergesort.txt", ios::out | ios::app);

	//benchmark parameters / variables
	double dtime;
	int n_start = 1000;
	int n_step = 1000;
	int n_end = 1000000;

	vector<int> V;

	//actual benchmark loop
	for (int n = n_start; n <= n_end; n += n_step) {

		

		//"progress bar"
	//	std::cout << "Running Mergesort with n: " << n << std::endl;

		//generate n random integers
		sorting::randomizeVector(V, n);
		std::vector<int> tmp;
		tmp.resize(V.size());
		//start measurement
		dtime = omp_get_wtime();

		//execzute sorting algorithm
		sorting::MergeSort(V,tmp,0, V.size() - 1);

		//stop time
		dtime = omp_get_wtime() - dtime;

		//write to file
		mergesort_measurement << n << "\t" << setprecision(10) << scientific << dtime << endl;
	}

	//close file handle
	mergesort_measurement.close();
}
void benchmark_natmergesort() {

	//file stream
	ofstream natmergesort_measurement;
	natmergesort_measurement.open("natmergesort.txt", ios::out | ios::app);

	//benchmark parameters / variables
	double dtime;
	int n_start = 1000;
	int n_step = 1000;
	int n_end = 1000000;

	vector<int> V;

	//actual benchmark loop
	for (int n = n_start; n <= n_end; n += n_step) {



		//"progress bar"
		std::cout << "Running Mergesort with n: " << n << std::endl;

		//generate n random integers
		sorting::randomizeVector(V, n);
		std::vector<int> tmp;
		tmp.resize(V.size());
		//start measurement
		dtime = omp_get_wtime();

		//execzute sorting algorithm
		sorting::natMergeSort(V, tmp);

		//stop time
		dtime = omp_get_wtime() - dtime;

		//write to file
		natmergesort_measurement << n << "\t" << setprecision(10) << scientific << dtime << endl;
	}

	//close file handle
	natmergesort_measurement.close();
}

void benchmark_heapsort() {

	//file stream
	ofstream heapsort_measurement;
	heapsort_measurement.open("heapsort.txt", ios::out | ios::app);

	//benchmark parameters / variables
	double dtime;
	int n_start = 1000;
	int n_step = 1000;
	int n_end = 1000000;

	vector<int> V;

	//actual benchmark loop
	for (int n = n_start; n <= n_end; n += n_step) {

		//"progress bar"
	//	std::cout << "Running Heapsort with n: " << n << std::endl;

		//generate n random integers
		sorting::randomizeVector(V, n);

		//start measurement
		dtime = omp_get_wtime();

		//execzute sorting algorithm
		sorting::HeapSort(V, V.size() - 1);

		//stop time
		dtime = omp_get_wtime() - dtime;

		//write to file
		heapsort_measurement << n << "\t" << setprecision(10) << scientific << dtime << endl;
	}

	//close file handle
	heapsort_measurement.close();
}

void benchmark_shellsort_2n() {

	//file stream
	ofstream shellsort_2n_measurement;
	shellsort_2n_measurement.open("shellsort_2n.txt", ios::out | ios::app);

	//benchmark parameters / variables
	double dtime;
	int n_start = 1000;
	int n_step = 1000;
	int n_end = 1000000;

	vector<int> V;

	//actual benchmark loop
	for (int n = n_start; n <= n_end; n += n_step) {

		//"progress bar"
	//	std::cout << "Running Shellsort_2n with n: " << n << std::endl;

		//generate n random integers
		sorting::randomizeVector(V, n);

		//start measurement
		dtime = omp_get_wtime();

		//execzute sorting algorithm
		sorting::ShellSort_2n(V, V.size() - 1);

		//stop time
		dtime = omp_get_wtime() - dtime;

		//write to file
		shellsort_2n_measurement << n << "\t" << setprecision(10) << scientific << dtime << endl;
	}

	//close file handle
	shellsort_2n_measurement.close();
}


void benchmark_shellsort_3n() {

	//file stream
	ofstream shellsort_2n_measurement;
	shellsort_2n_measurement.open("shellsort_3n.txt", ios::out | ios::app);

	//benchmark parameters / variables
	double dtime;
	int n_start = 1000;
	int n_step = 1000;
	int n_end = 1000000;

	vector<int> V;

	//actual benchmark loop
	for (int n = n_start; n <= n_end; n += n_step) {

		//"progress bar"
	//	std::cout << "Running Shellsort_3n with n: " << n << std::endl;

		//generate n random integers
		sorting::randomizeVector(V, n);

		//start measurement
		dtime = omp_get_wtime();

		//execzute sorting algorithm
		sorting::ShellSort_3n(V, V.size() - 1);

		//stop time
		dtime = omp_get_wtime() - dtime;

		//write to file
		shellsort_2n_measurement << n << "\t" << setprecision(10) << scientific << dtime << endl;
	}

	//close file handle
	shellsort_2n_measurement.close();
}
