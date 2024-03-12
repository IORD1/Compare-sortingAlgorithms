#include<algorithm>//for sorting
#include<chrono>//for calculating time
#include<iostream>// IO
#include<vector>//for vector array
#include<fstream>//for file handeling
#include<conio.h>//for clearing terminal
#include<array>
#include<omp.h>
#include <bits/stdc++.h> 
using namespace std;
using namespace std::chrono;
vector<int> algolist;
vector<int> values(1000);
const int RUN = 32;

//>>>>>>>>>>>>>>>>>>>>>>>>BUBBLE SORT FUNCTION<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
void swap(int *xp, int *yp)//fuction needed for bubble sort
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
void bubbleSort()           
{
    int avgarray[3] = {0};//decalring the array of size 3 to store the time of each round
    int nums[values.size()] = {0};//declaring the array that is going to get sorted
    int copy[values.size()] = {0};//declaring the copy[] array to copy random numbers to nums[] array after sorting for next loop 
    for(int i=0; i<values.size(); i++){
        nums[i] = values[i];        //coping random numbers form values array to nums array
        copy[i] = values[i];        //coping random number form values array to copy array
    }
    
    int n = values.size();


        for(int k=0; k<3; k++){         //we are going to sort the nums array three times so k = 3 and takes it's average
            int i, j;
            auto start = high_resolution_clock::now();  //clock started <<<<<<
            for (i = 0; i < n-1; i++){                  //bubble sort algo
                for (j = 0; j < n-i-1; j++){
                    if (nums[j] > nums[j+1]){
                        swap(&nums[j], &nums[j+1]);//declared abhove
                    }
                }
            }
            auto stop = high_resolution_clock::now();   //clock stoped <<<<<<<<
            auto duration = duration_cast<microseconds>(stop - start);  //stroreing the time taken in duration (stop - start)

	        // cout << "Time taken by function: "<< duration.count() << " microseconds" << endl; //printing the time each time 
            avgarray[k] = duration.count();                     //stroing the time in our array to take average later

            for(int i=0; i<values.size() ;i++){                 //now the nums[] array is sorted so make it 
                nums[i] = copy[i];                              //unsorted coping numbers from copy array
            }                                                   //to nums array.
        }                        
    int avgtime = (avgarray[0] + avgarray[1] + avgarray[2])/3;  
    cout<<"--------------------------------------------------"<<endl; 
    cout<<"BUBBLE SORT--------------------------------------|"<<endl;
    cout<<"|Time Taken : "<<avgarray[0]<<", "<<avgarray[1]<<", "<<avgarray[2]<<endl;
    cout<<"|Average time : "<<avgtime<<endl;                   
    cout<<"|                                                |"<<endl;
}
void llswap(int &a, int &b)
{

    int test;
    test=a;
    a=b;
    b=test;

}

void parrallelBubbleSort()           
{
    int avgarray[3] = {0};//decalring the array of size 3 to store the time of each round
    int nums[values.size()] = {0};//declaring the array that is going to get sorted
    int copy[values.size()] = {0};//declaring the copy[] array to copy random numbers to nums[] array after sorting for next loop 
    for(int i=0; i<values.size(); i++){
        nums[i] = values[i];        //coping random numbers form values array to nums array
        copy[i] = values[i];        //coping random number form values array to copy array
    }
    
    int n = values.size();


        for(int k=0; k<3; k++){         //we are going to sort the nums array three times so k = 3 and takes it's average
            int i, j;
            auto start = high_resolution_clock::now();  //clock started <<<<<<
            // for (i = 0; i < n-1; i++){                  //bubble sort algo
            //     for (j = 0; j < n-i-1; j++){
            //         if (nums[j] > nums[j+1]){
            //             swap(&nums[j], &nums[j+1]);//declared abhove
            //         }
            //     }
            // }
            for(  int i = 0;  i < n;  i++ )
            {  	 
                int first = i % 2; 	 

                #pragma omp parallel for shared(nums,first)
                for(  int j = first;  j < n-1;  j += 2  )
                {  	 
                    if(  nums[ j ]  >  nums[ j+1 ]  )
                    {  	 
                            llswap(  nums[ j ],  nums[ j+1 ]  );
                    }  	 
                    }  	 
            }
            auto stop = high_resolution_clock::now();   //clock stoped <<<<<<<<
            auto duration = duration_cast<microseconds>(stop - start);  //stroreing the time taken in duration (stop - start)

	        // cout << "Time taken by function: "<< duration.count() << " microseconds" << endl; //printing the time each time 
            avgarray[k] = duration.count();                     //stroing the time in our array to take average later

            for(int i=0; i<values.size() ;i++){                 //now the nums[] array is sorted so make it 
                nums[i] = copy[i];                              //unsorted coping numbers from copy array
            }                                                   //to nums array.
        }                        
    int avgtime = (avgarray[0] + avgarray[1] + avgarray[2])/3; 
    cout<<"BUBBLE SORT PARRALLEL                            |"<<endl;
    cout<<"|Time Taken : "<<avgarray[0]<<", "<<avgarray[1]<<", "<<avgarray[2]<<endl;
    cout<<"|Average time : "<<avgtime<<endl;                   
    cout<<"|________________________________________________|"<<endl;
}

void swapping(int &a, int &b) {         //swap the content of a and b
   int temp;
   temp = a;
   a = b;
   b = temp;
}
//>>>>>>>>>>>>>>>>>>>>>>>>SELECTION SORT FUNCTION<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
struct Compare { int val; int index; };
#pragma omp declare reduction(maximum : struct Compare : omp_out = omp_in.val > omp_out.val ? omp_in : omp_out)


void SelectionSort() {
    int avgarray[3] = {0};
    int nums[values.size()] = {0};
    int copy[values.size()] = {0};
    for(int i=0; i<values.size(); i++){
        nums[i] = values[i];        
        copy[i] = values[i];       
    }

    int n = values.size();
    for (int k = 0; k < 3; k++)
    {
        int i, j, min_in;
        auto start = high_resolution_clock::now();
        for (i = 0; i < n; i++)
        {
            min_in = i;
            for (j = i + 1; j < n; j++){
                if (nums[j] < nums[min_in]){
                    min_in = j;
                }
            }
            swap(nums[i], nums[min_in]);
        }
        auto stop = high_resolution_clock::now();                  
        auto duration = duration_cast<microseconds>(stop - start); 
        // cout << "Time taken by function: " << duration.count() << " microseconds" << endl; 
        avgarray[k] = duration.count();                                      

        for (int t = 0; t < values.size(); t++)
        {                      
            nums[t] = copy[t]; 
        }
    }
    int avgtime = (avgarray[0] + avgarray[1] + avgarray[2])/3; 
    cout<<"--------------------------------------------------"<<endl;  
    cout<<"SELECTION SORT-----------------------------------|"<<endl;
    cout<<"|Time Taken : "<<avgarray[0]<<", "<<avgarray[1]<<", "<<avgarray[2]<<endl;
    cout<<"|Average time : "<<avgtime<<endl;                   
    cout<<"|                                                |"<<endl;
}

void parrallelSelectionSort() {
    int avgarray[3] = {0};
    int nums[values.size()] = {0};
    int copy[values.size()] = {0};
    for(int i=0; i<values.size(); i++){
        nums[i] = values[i];        
        copy[i] = values[i];       
    }

    int n = values.size();
    for (int k = 0; k < 3; k++)
    {
        int i, j, min_in;
        auto start = high_resolution_clock::now();
        // for (i = 0; i < n; i++)
        // {
        //     min_in = i;
        //     for (j = i + 1; j < n; j++){
        //         if (nums[j] < nums[min_in]){
        //             min_in = j;
        //         }
        //     }
        //     swap(nums[i], nums[min_in]);
        // }
        for (int i = n - 1; i > 0; --i)
        {
            struct Compare max;
            max.val = nums[i];
            max.index = i;
            #pragma omp parallel for reduction(maximum:max)
            for (int j = i - 1; j >= 0; --j)
            {
                if (nums[j] > max.val)
                {
                    max.val = nums[j];
                    max.index = j;
                }
            }
            int tmp = nums[i];
            nums[i] = max.val;
            nums[max.index] = tmp;
        }
        auto stop = high_resolution_clock::now();                  
        auto duration = duration_cast<microseconds>(stop - start); 
        // cout << "Time taken by function: " << duration.count() << " microseconds" << endl; 
        avgarray[k] = duration.count();                                      

        for (int t = 0; t < values.size(); t++)
        {                      
            nums[t] = copy[t]; 
        }
    }
    int avgtime = (avgarray[0] + avgarray[1] + avgarray[2])/3; 
    cout<<"SELECTION SORT PARRALLEL                         |"<<endl;
    cout<<"|Time Taken : "<<avgarray[0]<<", "<<avgarray[1]<<", "<<avgarray[2]<<endl;
    cout<<"|Average time : "<<avgtime<<endl;                   
    cout<<"|________________________________________________|"<<endl;
}

//>>>>>>>>>>>>>>>>>>>>>>>>INSERTION SORT FUNCTION<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
void Insertionsort()
{
    int avgarray[3] = {0};
    int nums[values.size()] = {0};
    int copy[values.size()] = {0};
    for (int d = 0; d < values.size(); d++)
    {
        nums[d] = values[d];
        copy[d] = values[d];
    }

    int n = values.size();
    for (int k = 0; k < 3; k++)
    {
        int i, key, j;
        auto start = high_resolution_clock::now();
        for (i = 1; i < n; i++)
        {
            key = nums[i];
            j = i - 1;
            while (j >= 0 && nums[j] > key)
            {
                nums[j + 1] = nums[j];
                j = j - 1;
            }
            nums[j + 1] = key;
        }
        auto stop = high_resolution_clock::now();                  
        auto duration = duration_cast<microseconds>(stop - start); 
        // cout << "Time taken by function: " << duration.count() << " microseconds" << endl; 
        avgarray[k] = duration.count();                                      

        for (int t = 0; t < values.size(); t++)
        {                      
            nums[t] = copy[t]; 
        }
    }
    int avgtime = (avgarray[0] + avgarray[1] + avgarray[2])/3;  
    cout<<"--------------------------------------------------"<<endl;  
    cout<<"SELECTION SORT-----------------------------------|"<<endl;
    cout<<"|Time Taken : "<<avgarray[0]<<", "<<avgarray[1]<<", "<<avgarray[2]<<endl;
    cout<<"|Average time : "<<avgtime<<endl;                   
    cout<<"|________________________________________________|"<<endl;
}



//>>>>>>>>>>>>>>>>>>>>>>>>MERGE SORT FUNCTION<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
void merge(int array[], int const left, int const mid, int const right)
{
    auto const subArrayOne = mid - left + 1;
    auto const subArrayTwo = right - mid;
  
    // Create temp arrays
    auto *leftArray = new int[subArrayOne],
         *rightArray = new int[subArrayTwo];
  
    // Copy data to temp arrays leftArray[] and rightArray[]
    for (auto i = 0; i < subArrayOne; i++)
        leftArray[i] = array[left + i];
    for (auto j = 0; j < subArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];
  
    auto indexOfSubArrayOne = 0, // Initial index of first sub-array
        indexOfSubArrayTwo = 0; // Initial index of second sub-array
    int indexOfMergedArray = left; // Initial index of merged array
  
    // Merge the temp arrays back into array[left..right]
    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
        if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) {
            array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else {
            array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }
    // Copy the remaining elements of
    // left[], if there are any
    while (indexOfSubArrayOne < subArrayOne) {
        array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
    // Copy the remaining elements of
    // right[], if there are any
    while (indexOfSubArrayTwo < subArrayTwo) {
        array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
}
void mergeSort(int array[], int const begin, int const end)
{
    if (begin >= end)
        return; // Returns recursively
  
    auto mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);

}

void parrallelMerge(int * X, int n, int * tmp) {
   int i = 0;
   int j = n/2;
   int ti = 0;
	//i will iterate till first  half anf J will iterate for 2nd half of array
   while (i<n/2 && j<n) {
      if (X[i] < X[j]) {
         tmp[ti] = X[i];
         ti++; i++;
      } else {
         tmp[ti] = X[j];
         ti++; 
	 j++;
      }
   }
   while (i<n/2) { /* finish up lower half */
      tmp[ti] = X[i];
	ti++;
	i++;
   }
      while (j<n) { /* finish up upper half */
         tmp[ti] = X[j];
         ti++; 
	 j++;
   }
	//Copy sorted array tmp back to  X (Original array)
   memcpy(X, tmp, n*sizeof(int));

} 

void parallelMergesort(int * X, int n, int * tmp)
{
   if (n < 2) return;

   #pragma omp task firstprivate (X, n, tmp)
   parallelMergesort(X, n/2, tmp);

   #pragma omp task firstprivate (X, n, tmp)
   parallelMergesort(X+(n/2), n-(n/2), tmp);
	
   //Wait for both paralel tasks to complete execution
   #pragma omp taskwait

    /* merge sorted halves into sorted list */
   parrallelMerge(X, n, tmp);
}


void parallelMergeSortMain(){
    int avgarray[3] = {0};
    int nums[values.size()] = {0};
    int copy[values.size()] = {0};
    int tmp[values.size()];
    for (int d = 0; d < values.size(); d++)
    {
        nums[d] = values[d];
        copy[d] = values[d];
    }

    int n = values.size();
    for (int k = 0; k < 3; k++)
    {
        auto start = high_resolution_clock::now();
        parallelMergesort(nums,n,tmp);
        auto stop = high_resolution_clock::now();                  
        auto duration = duration_cast<microseconds>(stop - start); 
        // cout << "Time taken by function: " << duration.count() << " microseconds" << endl; 
        avgarray[k] = duration.count();
        for (int t = 0; t < values.size(); t++)
        {                      
            nums[t] = copy[t]; 
        }
    }
    int avgtime = (avgarray[0] + avgarray[1] + avgarray[2])/3;   
    cout<<"MERGE SORT PARRALLEL                             |"<<endl;
    cout<<"|Time Taken : "<<avgarray[0]<<", "<<avgarray[1]<<", "<<avgarray[2]<<endl;
    cout<<"|Average time : "<<avgtime<<endl;                   
    cout<<"|________________________________________________|"<<endl;
}


void mergemain(){

    int avgarray[3] = {0};
    int nums[values.size()] = {0};
    int copy[values.size()] = {0};
    for (int d = 0; d < values.size(); d++)
    {
        nums[d] = values[d];
        copy[d] = values[d];
    }

    int n = values.size();
    for (int k = 0; k < 3; k++)
    {
        auto start = high_resolution_clock::now();
        mergeSort(nums, 0 , n);
        auto stop = high_resolution_clock::now();                  
        auto duration = duration_cast<microseconds>(stop - start); 
        // cout << "Time taken by function: " << duration.count() << " microseconds" << endl; 
        avgarray[k] = duration.count();
        for (int t = 0; t < values.size(); t++)
        {                      
            nums[t] = copy[t]; 
        }
    }
    int avgtime = (avgarray[0] + avgarray[1] + avgarray[2])/3;    
    cout<<"--------------------------------------------------"<<endl;  
    cout<<"MERGE SORT---------------------------------------|"<<endl;
    cout<<"|Time Taken : "<<avgarray[0]<<", "<<avgarray[1]<<", "<<avgarray[2]<<endl;
    cout<<"|Average time : "<<avgtime<<endl;                   
    cout<<"|                                                |"<<endl;

}

//>>>>>>>>>>>>>>>>>>>>>>>>QUICK SORT FUNCTION<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
int partition(int arr[], int start, int end)
{
 
    int pivot = arr[start];
 
    int count = 0;
    for (int i = start + 1; i <= end; i++) {
        if (arr[i] <= pivot)
            count++;
    }
 
    // Giving pivot element its correct position
    int pivotIndex = start + count;
    swap(arr[pivotIndex], arr[start]);
 
    // Sorting left and right parts of the pivot element
    int i = start, j = end;
 
    while (i < pivotIndex && j > pivotIndex) {
 
        while (arr[i] <= pivot) {
            i++;
        }
 
        while (arr[j] > pivot) {
            j--;
        }
 
        if (i < pivotIndex && j > pivotIndex) {
            swap(arr[i++], arr[j--]);
        }
    }
 
    return pivotIndex;
}
 
void quickSort(int arr[], int start, int end)
{
 

    if (start >= end)
        return;
 

    int p = partition(arr, start, end);

    quickSort(arr, start, p - 1);
    quickSort(arr, p + 1, end);
}

void quicksortmain(){
    int avgarray[3] = {0};
    int nums[values.size()] = {0};
    int copy[values.size()] = {0};
    for (int d = 0; d < values.size(); d++)
    {
        nums[d] = values[d];
        copy[d] = values[d];
    }

    int n = values.size();
    for (int k = 0; k < 3; k++)
    {
        auto start = high_resolution_clock::now();
        quickSort(nums, 0 , n-1);
        auto stop = high_resolution_clock::now();                  
        auto duration = duration_cast<microseconds>(stop - start); 
        // cout << "Time taken by function: " << duration.count() << " microseconds" << endl; 
        avgarray[k] = duration.count(); 
        for (int t = 0; t < values.size(); t++)
        {                      
            nums[t] = copy[t]; 
        }
    }
    int avgtime = (avgarray[0] + avgarray[1] + avgarray[2])/3;  
    cout<<"Time Taken : "<<avgarray[0]<<", "<<avgarray[1]<<", "<<avgarray[2]<<endl;  
    cout<<"Average time for Quick sort : "<<avgtime<<endl; 
    cout<<"-------------------------------------------------"<<endl;
}

//>>>>>>>>>>>>>>>>>>>>>>>>HEAP SORT FUNCTION<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
void heapify(int arr[], int n, int i)
{
    int largest = i; 
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2
  

    if (l < n && arr[l] > arr[largest])
        largest = l;
  

    if (r < n && arr[r] > arr[largest])
        largest = r;
  

    if (largest != i) {
        swap(arr[i], arr[largest]);
  
  
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{
   
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
  

    for (int i = n - 1; i >= 0; i--) {
        // Move current root to end
        swap(arr[0], arr[i]);
  

        heapify(arr, i, 0);
    }
}

void heapsortmain(){
    int avgarray[3] = {0};
    int nums[values.size()] = {0};
    int copy[values.size()] = {0};
    for (int d = 0; d < values.size(); d++)
    {
        nums[d] = values[d];
        copy[d] = values[d];
    }

    int n = values.size();
    for (int k = 0; k < 3; k++)
    {
        auto start = high_resolution_clock::now();
        heapSort(nums, n);
        auto stop = high_resolution_clock::now();                  
        auto duration = duration_cast<microseconds>(stop - start); 
        // cout << "Time taken by function: " << duration.count() << " microseconds" << endl; 
        avgarray[k] = duration.count();  
        for (int t = 0; t < values.size(); t++)
        {                      
            nums[t] = copy[t]; 
        }
    }
    int avgtime = (avgarray[0] + avgarray[1] + avgarray[2])/3; 
    cout<<"Time Taken : "<<avgarray[0]<<", "<<avgarray[1]<<", "<<avgarray[2]<<endl;   
    cout<<"Average time for Heap sort : "<<avgtime<<endl; 
    cout<<"-------------------------------------------------"<<endl;
}
//>>>>>>>>>>>>>>>>>>>>>>>>BUCKET SORT FUNCTION<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
void bucketSort(float arr[], int n)
{
     

    vector<float> b[n];
 

    for (int i = 0; i < n; i++) {
        int bi = n * arr[i]; // Index in bucket
        b[bi].push_back(arr[i]);
    }

    for (int i = 0; i < n; i++)
        sort(b[i].begin(), b[i].end());
 

    int index = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < b[i].size(); j++)
            arr[index++] = b[i][j];
}

void bucketmain(){
    int avgarray[3] = {0};
    float nums[values.size()] = {0};
    float copy[values.size()] = {0};
    for (int d = 0; d < values.size(); d++)
    {
        nums[d] = (float)values[d]/1000;
        copy[d] = (float)values[d]/1000;
    }

    int n = values.size();
    for (int k = 0; k < 3; k++)
    {
        auto start = high_resolution_clock::now();
        bucketSort(nums, n);
        auto stop = high_resolution_clock::now();                  
        auto duration = duration_cast<microseconds>(stop - start); 
        // cout << "Time taken by function: " << duration.count() << " microseconds" << endl; 
        avgarray[k] = duration.count();  
        for (int t = 0; t < values.size(); t++)
        {                      
            nums[t] = copy[t]; 
        }
    }
    int avgtime = (avgarray[0] + avgarray[1] + avgarray[2])/3;
    cout<<"Time Taken : "<<avgarray[0]<<", "<<avgarray[1]<<", "<<avgarray[2]<<endl;    
    cout<<"Average time for Bucket sort : "<<avgtime<<endl; 
    cout<<"NOTE : Bucket sort algorithm sorts float values(eg : 0.132,0.870) hence it requrires more time "<<endl;
    cout<<"-------------------------------------------------"<<endl;
}

//>>>>>>>>>>>>>>>>>>>>>>>>RADIX SORT FUNCTION<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

// A utility function to get maximum value in arr[]
int getMax(int arr[], int n)
{
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}

void countSort(int arr[], int n, int exp)
{
    int output[n]; // output array
    int i, count[10] = { 0 };
 

    for (i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;
 

    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
 

    for (i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
 
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}

void radixsort(int arr[], int n)
{
    int m = getMax(arr, n);
 
    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(arr, n, exp);
}
void radixmain(){
    int avgarray[3] = {0};
    int nums[values.size()] = {0};
    int copy[values.size()] = {0};
    for (int d = 0; d < values.size(); d++)
    {
        nums[d] = values[d];
        copy[d] = values[d];
    }

    int n = values.size();
    for (int k = 0; k < 3; k++)
    {
        auto start = high_resolution_clock::now();
        radixsort(nums, n);
        auto stop = high_resolution_clock::now();                  
        auto duration = duration_cast<microseconds>(stop - start); 
        // cout << "Time taken by function: " << duration.count() << " microseconds" << endl; 
        avgarray[k] = duration.count();  
        for (int t = 0; t < values.size(); t++)
        {                      
            nums[t] = copy[t]; 
        }
    }
    int avgtime = (avgarray[0] + avgarray[1] + avgarray[2])/3;    
    cout<<"Time Taken : "<<avgarray[0]<<", "<<avgarray[1]<<", "<<avgarray[2]<<endl;
    cout<<"Average time for Radix sort : "<<avgtime<<endl; 
    cout<<"-------------------------------------------------"<<endl;
}

//>>>>>>>>>>>>>>>>>>>>>>>>TIM SORT FUNCTION<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<


void insertionSorttim(int arr[], int left, int right)
{
    for (int i = left + 1; i <= right; i++)
    {
        int temp = arr[i];
        int j = i - 1;
        while (j >= left && arr[j] > temp)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
}
 
// Merge function merges the sorted runs
void mergetim(int arr[], int l, int m, int r)
{
     
    int len1 = m - l + 1, len2 = r - m;
    int left[len1], right[len2];
    for (int i = 0; i < len1; i++)
        left[i] = arr[l + i];
    for (int i = 0; i < len2; i++)
        right[i] = arr[m + 1 + i];
 
    int i = 0;
    int j = 0;
    int k = l;
 
    while (i < len1 && j < len2)
    {
        if (left[i] <= right[j])
        {
            arr[k] = left[i];
            i++;
        }
        else
        {
            arr[k] = right[j];
            j++;
        }
        k++;
    }
 
    // Copy remaining elements of left, if any
    while (i < len1)
    {
        arr[k] = left[i];
        k++;
        i++;
    }
 
    // Copy remaining element of right, if any
    while (j < len2)
    {
        arr[k] = right[j];
        k++;
        j++;
    }
}
 
void timSort(int arr[], int n)
{
     
    // Sort individual subarrays of size RUN
    for (int i = 0; i < n; i+=RUN)
        insertionSorttim(arr, i, min((i+RUN-1),
                                    (n-1)));
 
    
    for (int size = RUN; size < n;
                             size = 2*size)
    {
        for (int left = 0; left < n;
                             left += 2*size)
        {
            int mid = left + size - 1;
            int right = min((left + 2*size - 1),
                                            (n-1));
              if(mid < right)
                mergetim(arr, left, mid, right);
        }
    }
}

void timmain(){
    int avgarray[3] = {0};
    int nums[values.size()] = {0};
    int copy[values.size()] = {0};
    for (int d = 0; d < values.size(); d++)
    {
        nums[d] = values[d];
        copy[d] = values[d];
    }

    int n = values.size();
    for (int k = 0; k < 3; k++)
    {
        auto start = high_resolution_clock::now();
        timSort(nums, n);
        auto stop = high_resolution_clock::now();                  
        auto duration = duration_cast<microseconds>(stop - start); 
        // cout << "Time taken by function: " << duration.count() << " microseconds" << endl; 
        avgarray[k] = duration.count();
        for (int t = 0; t < values.size(); t++)
        {                      
            nums[t] = copy[t]; 
        }
    }
    int avgtime = (avgarray[0] + avgarray[1] + avgarray[2])/3;   
    cout<<"Time Taken : "<<avgarray[0]<<", "<<avgarray[1]<<", "<<avgarray[2]<<endl; 
    cout<<"Average time for Tim sort : "<<avgtime<<endl; 
    cout<<"-------------------------------------------------"<<endl;
}


//>>>>>>>>>>>>>>>>>>>>>>>>SHELL SORT FUNCTION<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

int shellSort(int arr[], int n)
{
    // Start with a big gap, then reduce the gap
    for (int gap = n/2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i += 1)
        {
            int temp = arr[i];
            int j;           
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];
            arr[j] = temp;
        }
    }
    return 0;
}

void shellmain(){
    int avgarray[3] = {0};
    int nums[values.size()] = {0};
    int copy[values.size()] = {0};
    for (int d = 0; d < values.size(); d++)
    {
        nums[d] = values[d];
        copy[d] = values[d];
    }

    int n = values.size();
    for (int k = 0; k < 3; k++)
    {
        auto start = high_resolution_clock::now();
        shellSort(nums, n);
        auto stop = high_resolution_clock::now();                  
        auto duration = duration_cast<microseconds>(stop - start); 
        // cout << "Time taken by function: " << duration.count() << " microseconds" << endl; 
        avgarray[k] = duration.count(); 
        for (int t = 0; t < values.size(); t++)
        {                      
            nums[t] = copy[t]; 
        }
    }
    int avgtime = (avgarray[0] + avgarray[1] + avgarray[2])/3;   
    cout<<"Time Taken : "<<avgarray[0]<<", "<<avgarray[1]<<", "<<avgarray[2]<<endl; 
    cout<<"Average time for Shell sort : "<<avgtime<<endl; 
    cout<<"-------------------------------------------------"<<endl;   
} 

//>>>>>>>>>>>>>>>>>>>>>>>>ALgo's END<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<



// Setting menu
void opt3menu(){

    cout<<"|--------------MENU---------------|"<<endl;
    cout<<"|1: Back                          |"<<endl;
    cout<<"|2: Change size of Array          |"<<endl;
    cout<<"|3: Print Array                   |"<<endl;
    cout<<"|4: Edit the Array                |"<<endl;
    cout<<"|_________________________________|"<<endl;
}
// function handles the execution the of Settings for application
// handles the array editing
void opt3menuopt(){
    opt3menu();
    while(true){
        int opt;
        cout<<"Enter the Option : ";
        cin>>opt;
        if(opt == 1){
            system("clear");
            break;
        }else if(opt == 2){
            system("clear");
            cout<<"Enter the Size of array"<<endl;
            int size;
            cin>>size;
            values.resize(size);
            system("clear");
            cout<<"Array size changed to : "<<size<<endl;
            cout<<values.size()<<endl;
            opt3menu();
        }else if(opt == 3){
            system("clear");
            for (int i: values){
                cout << i << ' ';
            }
            opt3menu();
        }else if(opt == 4){
            system("clear");
            cout<<"Enter the position and values to edit the array"<<endl;
            while(true){
                int position;
                int valuestoedit;
                int opt2;
                cout<<"Enter position : ";cin>>position;
                cout<<"Enter value for abhove position : ";cin>>valuestoedit;
                values[position] = valuestoedit;
                cout<<"Enter 1 to edit more : ";cin>>opt2;
                if(opt2 != 1){
                    break;
                }
            }
            system("clear");
            cout<<"Array editing successful"<<endl;
            opt3menu();

        }
    }

}

// function to print list of sorting algorithms
void opt1menu(){
    cout<<"1: Bubble Sort"<<endl;
    cout<<"2: Selection Sort"<<endl;
    cout<<"3: Insertion Sort"<<endl;
    cout<<"4: Merge Sort"<<endl;
    cout<<"5: Quick Sort"<<endl;
    cout<<"6: Heap Sort"<<endl;
    cout<<"7: Bucket Sort"<<endl;
    cout<<"8: Radix Sort"<<endl;
    cout<<"9: Tim Sort"<<endl;
    cout<<"10: Shell Sort"<<endl;
}


// function to select the sorting algorithms to compare
void opt1menuopt(vector<string>algoptoins ){
    int opt;

    opt1menu();
    cout<<"Enter 0 to stop and go back "<<endl;
    cout<<"-----------------------------------------"<<endl;
    while(true){
        
        cout<<"Enter a Number from above list to compare : ";
        cin>>opt;
        if(opt == 0){
            break;
        }
        algolist.push_back(opt);
    }
    system("clear");
    cout<<"--------------------------------------------------"<<endl;
    cout<<"Algoriths Chosen are : "<<endl;
    
    for(int i=0; i<algolist.size(); i++){
        cout<<algoptoins[algolist[i]-1]<<endl;
    }
    cout<<"--------------------------------------------------"<<endl;

    cout<<algolist.size()<<endl;

}


// function handles the actually sorting by executing each function
void opt2menu(vector<string> algoptoins){
    cout<<"Starting Comparison....."<<endl;
    cout<<"Comparing : "<<endl;
    for(int i=0; i<algolist.size(); i++){
        cout<<"    "<<algoptoins[algolist[i]-1]<<endl;
    }

    for(int i=0; i<algolist.size(); i++){
        if(algolist[i] == 1){
            bubbleSort(); 
            parrallelBubbleSort();
        }else if(algolist[i] == 2){
            SelectionSort();
            parrallelSelectionSort();
        }else if(algolist[i] == 3){
            Insertionsort();
        }else if(algolist[i] == 4){
            mergemain();
            parallelMergeSortMain();
        }else if(algolist[i] == 5){
            quicksortmain();
        }else if(algolist[i] == 6){
            heapsortmain();
        }else if(algolist[i] == 7){
            bucketmain();
        }else if(algolist[i] == 8){
            radixmain();
        }else if(algolist[i] == 9){
            timmain();
        }else if(algolist[i] == 10){
            shellmain();
        }else{
            cout<<"Bhai kuch gad bad hai is me "<<endl;
        }

    }
 
}


//for MAIN MENU 
void printmenu(){
    cout<<"|--------------MENU--------------|"<<endl;
    cout<<"|1: Select Algorithms            |"<<endl;
    cout<<"|2: Compare                      |"<<endl;
    cout<<"|3: Edit the used Array          |"<<endl;
    cout<<"|4: Get Information              |"<<endl;
    cout<<"|5: END__________________________|"<<endl;
    // cout<<"|________________________________|"<<endl;
    cout<<">"<<endl;
}

// Just a function to print the time complexities of the Sorting algorithm
void printinfo(){
    cout<<"Average Time complexities of different Sorting techniques"<<endl;
    cout<<"Bubble sort :    O(n2) "<<endl;
    cout<<"Selection sort : O(n2) "<<endl;
    cout<<"Insertion sort : O(n2) "<<endl;
    cout<<"Merge sort :     O(n*Log n) "<<endl;
    cout<<"Quick sort :     O(n*Log n) "<<endl;
    cout<<"Heap sort :      O(n*Log n) "<<endl;
    cout<<"Bucket sort :    O(n) "<<endl;
    cout<<"Radix sort :     O(D*(n+b)) "<<endl;
    cout<<"Tim sort :       O(nlog n) "<<endl;
    cout<<"Shell sort :     O(nlog n) "<<endl;
    cout<<"where n = size of array "<<endl;;
    cout<<"      b = base"<<endl;
    cout<<"-----------------------------------"<<endl;
}
// >>>>>>>>>>>>>>>>>>MAIN<<<<<<<<<<<<<<<<<<<<

int main(){
    vector<string> algoptoins {"Bubble Sort","Selection Sort", "Insertion Sort", "Merge Sort", "Quick Sort", "Heap Sort","Bucket Sort", "Radix Sort", "Tim Sort", "Shell Sort" };
    
    int sizeofarray = 100;//size of our array to test
    auto f = []() -> int { return rand() % 1000; };
    generate(values.begin(), values.end(), f);



    system("clear");
    printmenu();

    // HEART LOOP-handles the execution of application 
    while(true){
        int opt;
        cout<<"Enter the Option : ";
        cin>>opt;
        if(opt == 1){
            system("clear");
            algolist.clear();
            opt1menuopt(algoptoins);
            printmenu();
        }else if(opt == 2){
            system("clear");
            opt2menu(algoptoins);
            printmenu();
        }else if(opt == 3){
            system("clear");
            opt3menuopt();
            //system("clear");
            printmenu();
        }else if(opt == 4){
            system("clear");
            printmenu();
            printinfo();
        }else if(opt == 5){
            system("clear");
            printmenu();
            break;
        }else{
            system("clear");
            printmenu();
            cout<<"Please Enter valid option"<<endl;
        }
    }

    return 0;
}
