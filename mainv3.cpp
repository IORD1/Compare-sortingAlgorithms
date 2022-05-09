#include<algorithm>//for sorting
#include<chrono>//for calculating time
#include<iostream>// IO
#include<vector>//for vector array
#include<fstream>//for file handeling
#include<conio.h>//for clearing terminal
#include<array>
using namespace std;
using namespace std::chrono;
vector<int> algolist;
vector<int> values(1000);



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

	        cout << "Time taken by function: "<< duration.count() << " microseconds" << endl; //printing the time each time 
            avgarray[k] = duration.count();                     //stroing the time in our array to take average later

            for(int i=0; i<values.size() ;i++){                 //now the nums[] array is sorted so make it 
                nums[i] = copy[i];                              //unsorted coping numbers from copy array
            }                                                   //to nums array.
        }                        
    int avgtime = (avgarray[0] + avgarray[1] + avgarray[2])/3;    //taking average
    cout<<"Average time for Bubble sort : "<<avgtime<<endl;                         //printing average
    cout<<"-------------------------------------------------"<<endl;
}

void swapping(int &a, int &b) {         //swap the content of a and b
   int temp;
   temp = a;
   a = b;
   b = temp;
}
//selectionsort.....
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
        cout << "Time taken by function: " << duration.count() << " microseconds" << endl; 
        avgarray[k] = duration.count();                                      

        for (int t = 0; t < values.size(); t++)
        {                      
            nums[t] = copy[t]; 
        }
    }
    int avgtime = (avgarray[0] + avgarray[1] + avgarray[2])/3;    
    cout<<"Average time for Selection sort : "<<avgtime<<endl; 
     cout<<"-------------------------------------------------"<<endl;
}

//insertionsort
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
        cout << "Time taken by function: " << duration.count() << " microseconds" << endl; 
        avgarray[k] = duration.count();                                      

        for (int t = 0; t < values.size(); t++)
        {                      
            nums[t] = copy[t]; 
        }
    }
    int avgtime = (avgarray[0] + avgarray[1] + avgarray[2])/3;    
    cout<<"Average time for Insertion sort : "<<avgtime<<endl; 
     cout<<"-------------------------------------------------"<<endl;
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
        cout << "Time taken by function: " << duration.count() << " microseconds" << endl; 
        avgarray[k] = duration.count();
        for (int t = 0; t < values.size(); t++)
        {                      
            nums[t] = copy[t]; 
        }
    }
    int avgtime = (avgarray[0] + avgarray[1] + avgarray[2])/3;    
    cout<<"Average time for Merge sort : "<<avgtime<<endl; 
    cout<<"-------------------------------------------------"<<endl;

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
 
    // base case
    if (start >= end)
        return;
 
    // partitioning the array
    int p = partition(arr, start, end);
 
    // Sorting the left part
    quickSort(arr, start, p - 1);
 
    // Sorting the right part
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
        for(int g=0; g<n; g++){
            cout<<nums[g]<<"-";
        }cout<<endl;
        quickSort(nums, 0 , n);
        auto stop = high_resolution_clock::now();                  
        auto duration = duration_cast<microseconds>(stop - start); 
        cout << "Time taken by function: " << duration.count() << " microseconds" << endl; 
        avgarray[k] = duration.count();                                      

        for(int g=0; g<n; g++){
            cout<<nums[g]<<"-";
        }cout<<endl;
        for (int t = 0; t < values.size(); t++)
        {                      
            nums[t] = copy[t]; 
        }
    }
    int avgtime = (avgarray[0] + avgarray[1] + avgarray[2])/3;    
    cout<<"Average time for Quick sort : "<<avgtime<<endl; 
    cout<<"-------------------------------------------------"<<endl;
}



void opt3menu(){
    cout<<"---------------MENU---------------"<<endl;
    cout<<"1: Back"<<endl;
    cout<<"2: Change size of Array"<<endl;
    cout<<"3: Print Array"<<endl;
    cout<<"4: Edit the Array"<<endl;
    cout<<"-----------------------------------"<<endl;
}

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

void opt2menu(vector<string> algoptoins){
    cout<<"Starting Comparison....."<<endl;
    cout<<"Comparing : "<<endl;
    for(int i=0; i<algolist.size(); i++){
        cout<<"    "<<algoptoins[algolist[i]-1]<<endl;
    }

    for(int i=0; i<algolist.size(); i++){
        if(algolist[i] == 1){
            bubbleSort();       //calling bubblesort here
        }else if(algolist[i] == 2){
            SelectionSort();
        }else if(algolist[i] == 3){
            Insertionsort();
        }else if(algolist[i] == 4){
            mergemain();
        }else if(algolist[i] == 5){
            cout<<"ruk re bhai quick sort hone ka hai function "<<endl;
        }else if(algolist[i] == 6){
            cout<<"ruk re bhai heap sort hone ka hai function "<<endl;
        }else if(algolist[i] == 7){
            cout<<"ruk re bhai bucket sort hone ka hai function "<<endl;
        }else if(algolist[i] == 8){
            cout<<"ruk re bhai radix sort hone ka hai function "<<endl;
        }else if(algolist[i] == 9){
            cout<<"ruk re bhai tme sort hone ka hai function "<<endl;
        }else if(algolist[i] == 10){
            cout<<"ruk re bhai shell sort hone ka hai function "<<endl;
        }else{
            cout<<"Bhai kuch gad bad hai is me "<<endl;
        }

    }
 
}



void printmenu(){//for priting the menu 
    cout<<"---------------MENU---------------"<<endl;
    cout<<"1: Select Algorithms"<<endl;
    cout<<"2: Compare"<<endl;
    cout<<"3: Edit the used Array"<<endl;
    cout<<"4: Get Information"<<endl;
    cout<<"5: END"<<endl;
    cout<<"-----------------------------------"<<endl;
}

// >>>>>>>>>>>>>>>>>>MAIN<<<<<<<<<<<<<<<<<<<<

int main(){
    vector<string> algoptoins {"Bubble Sort","Selection Sort", "Insertion Sort", "Merge Sort", "Quick Sort", "Heap Sort","Bucket Sort", "Radix Sort", "Tim Sort", "Shell Sort" };
    
    int sizeofarray = 100;//size of our array to test
    auto f = []() -> int { return rand() % 1000; };
    generate(values.begin(), values.end(), f);

    //bubbleSort(valuesarr,sizeofarray);
    // for(int i=0; i<values.size(); i++){
    //     cout<<valuesarr[i]<<" ";
    // }

    system("clear");
    printmenu();



    while(true){//heart-loop
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
            cout<<"Info"<<endl;
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