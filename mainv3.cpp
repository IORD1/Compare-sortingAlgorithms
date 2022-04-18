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
    cout<<values.size()<<endl;              //printing size of values array just for debugging
    cout<<n<<endl;                          //ans also n
    int avgtime = (avgarray[0] + avgarray[1] + avgarray[2])/3;    //taking average
    cout<<"Average time for Bubble sort : "<<avgtime<<endl;                         //printing average

}


//selectionsort.....
void SelectionSort(int arr[], int n)
{
    int i, j, min_ind;
    for(i=0;i<n-1;i++)
    {
        i=min_ind;
        for(j=i+1;j<n;j++)
        {
            if(arr[j]<arr[min_ind])
                min_ind=j;
            swap(&arr[min_ind],&arr[i]);
        }
    }
}

//insertionsort
void Insertionsort(int arr[],int n)
{
 int i,key,j;
 for(i=1;i<n;i++)
 {
     key=arr[i];
     j=i-1;
     while(j>=0 && arr[j]>key)
     {
         arr[j+1]=arr[j];
         j=j-1;
     }
     arr[j+1]=key;
 }
}

//mergesort
void MergeSort(int arr[],int left,int right,int temp)
{
    int mid;
    if(left<right)
    {
        mid=(left+right)/2;
        MergeSort(arr,left,mid,temp);
        MergeSort(arr,mid+1,right,temp);
   //     Merge(arr,left,mid+1,temp,right);
    }

}
void Merge(int arr[],int left,int mid,int temp[],int right)
{

    int i=left;
    int j=mid+1;
    int k=left;
    while(i<=mid && j<=right)
    {

        if(arr[i]<arr[j])
        {
           temp[k]=arr[i];
           i++;

        }
        else{
            temp[k]=arr[j];
            j++;
        }
        k++;
    }
    if(i>mid){
        while(j<right)
        {

            temp[k]=arr[j];
            k++;
            j++;
        }
    }
    else{
        while(i<=mid)
        {
            temp[k]=arr[i];
            k++;
            i++;
        }
    }
    for(k=left; k<=right; k++)
    {
        arr[k]=temp[k];
    }
}


//quicksort
// void Quicksort(int arr[],int low, int high,int Partition())
// {
//     int pivot;
//     if(low<high)
//     {
//         pivot= Partition(arr,low,high);
//         Quicksort(arr,low,pivot-1);
//         Quicksort(arr,pivot+1,high);
//     }
// }

// int Partition(int arr,int low, int high)
// {
//     int i=low;
//     int j=high;
//     int Pivot=arr[low];
//     while(low<high){
//         while(arr[i]<=Pivot)
//         {
//             i++;
//         }
//         while(arr[j]>Pivot)
//         {
//             j--;
//         }
//         if(i<j)
//         {
//             swap2(arr,i,j);
//         }
//     }
//     swap2(arr,j,low);
//     return j;

// }



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
            cout<<"ruk re bhai Selection Sort hone ka hai function "<<endl;
        }else if(algolist[i] == 3){
            cout<<"ruk re bhai insertion sort hone ka hai function "<<endl;
        }else if(algolist[i] == 4){
            cout<<"ruk re bhai merge sort hone ka hai function "<<endl;
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