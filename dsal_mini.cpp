
#include <algorithm>
#include <chrono>
#include <iostream>
#include<vector>
using namespace std;
using namespace std::chrono;

int main()
{

	vector<int> values(1000);

	// Generate Random values
	auto f = []() -> int { return rand() % 1000; };
    
	// Fill up the vector
	generate(values.begin(), values.end(), f);

    for(int i=0; i<values.size(); i++){
        cout<<values[i]<<" ";
    }
    
    cout<<endl<<"---------------------"<<endl;
	// Get starting timepoint
	auto start = high_resolution_clock::now();

	// Call the function, here sort()
	sort(values.begin(), values.end());

	// Get ending timepoint
	auto stop = high_resolution_clock::now();

    for(int i=0; i<values.size(); i++){
        cout<<values[i]<<" ";
    }
    cout<<endl<<"---------------------"<<endl;
	// Get duration. Substart timepoints to
	// get duration. To cast it to proper unit
	// use duration cast method
	auto duration = duration_cast<microseconds>(stop - start);

	cout << "Time taken by function: "<< duration.count() << " microseconds" << endl;

	return 0;
}
