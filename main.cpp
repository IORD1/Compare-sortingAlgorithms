
#include<graphics.h>
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
    int avgarray[3] = {0};
    int nums[values.size()] = {0};
    for(int i=0; i<values.size(); i++){
        nums[i] = values[i];
    }
    
    int n = values.size();


        for(int k=0; k<3; k++){
            int i, j;
            auto start = high_resolution_clock::now();
            for (i = 0; i < n-1; i++){
         // Last i elements are already in place
                for (j = 0; j < n-i-1; j++){
                    if (nums[j] > nums[j+1]){
                        swap(&nums[j], &nums[j+1]);//declared abhove
                    }
                }
            }
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);

	        cout << "Time taken by function: "<< duration.count() << " microseconds" << endl;
            avgarray[k] = duration.count();
        }
    cout<<values.size()<<endl;
    cout<<n<<endl;
    int avgtime = (avgarray[0] + avgarray[1] + avgarray[2])/3;
    cout<<"Average time : "<<avgtime<<endl;

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
            bubbleSort();
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