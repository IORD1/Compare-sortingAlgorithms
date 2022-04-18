

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



void swap(int *xp, int *yp)//fuction needed for bubble sort
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n-1; i++)

    // Last i elements are already in place
    for (j = 0; j < n-i-1; j++)
        if (arr[j] > arr[j+1])
            swap(&arr[j], &arr[j+1]);//declared abhove
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
void Quicksort(int arr[],int low, int high,int Partition())
{
    int pivot;
    if(low<high)
    {
        pivot= Partition(arr,low,high);
        Quicksort(arr,low,pivot-1);
        Quicksort(arr,pivot+1,high);
    }
}
int Partition(int arr,int low, int high)
{
    int i=low;
    int j=high;
    int Pivot=arr[low];
    while(low<high){
        while(arr[i]<=Pivot)
        {
            i++;
        }
        while(arr[j]>Pivot)
        {
            j--;
        }
        if(i<j)
        {
            swap(arr,i,j);
        }
    }
    swap(arr,j,low);
    return j;

}

void opt3menu(){
    cout<<"---------------MENU---------------"<<endl;
    cout<<"1: Back"<<endl;
    cout<<"2: Change size of Array"<<endl;
    cout<<"3: Print Array"<<endl;
    cout<<"4: Edit the Array"<<endl;
    cout<<"-----------------------------------"<<endl;
}

void opt3menuopt(vector <int> values){
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

void opt1menuopt(vector <int> values,vector<string>algoptoins,vector<int> algolist ){
    int opt;

    opt1menu();
    cout<<"Enter 0 to stop and go back "<<endl;
    cout<<"-----------------------------------------"<<endl;
    while(true){

        cout<<"Enter a Number from above list to compare : ";
        cin>>opt;
        algolist.push_back(opt);
        if(opt == 0){
            break;
        }
    }
    system("clear");
    cout<<"--------------------------------------------------"<<endl;
    cout<<"Algoriths Chosen are : "<<endl;

    for(int i=0; i<algolist.size()-1; i++){
        cout<<algoptoins[algolist[i]-1]<<endl;
    }
    cout<<"--------------------------------------------------"<<endl;



}

void opt2menu(vector<int> values,vector<int> algolist,vector<string> algoptoins){
    cout<<"Starting Comparison....."<<endl;
    cout<<algolist.size()<<endl;
    cout<<algoptoins.size()<<endl;
    for(int i=0; i<algolist.size(); i++){
        cout<<algolist[i]<<endl;
    }

    // for(int i=0; i<algolist.size()-1; i++){
    //     cout<<"Calculating time for : "<< algoptoins[algolist[i]-1]<<endl;

    // }
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

int main(){
    vector<string> algoptoins {"Bubble Sort","Selection Sort", "Insertion Sort", "Merge Sort", "Quick Sort", "Heap Sort","Bucket Sort", "Radix Sort", "Tim Sort", "Shell Sort" };

    int sizeofarray = 100;//size of our array to test
    vector<int> values(1000);
    auto f = []() -> int { return rand() % 1000; };
    generate(values.begin(), values.end(), f);

    //bubbleSort(valuesarr,sizeofarray);
    // for(int i=0; i<values.size(); i++){
    //     cout<<valuesarr[i]<<" ";
    // }

    system("clear");
    system("clear");
    printmenu();



    while(true){//heart-loop
        int opt;
        cout<<"Enter the Option : ";
        cin>>opt;
        if(opt == 1){
            system("clear");
            opt1menuopt(values,algoptoins,algolist);
            printmenu();
        }else if(opt == 2){
            system("clear");
            opt2menu(values,algolist,algoptoins);
            printmenu();
        }else if(opt == 3){
            system("clear");
            opt3menuopt(values);
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
