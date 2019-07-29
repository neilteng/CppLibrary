//please compile it with c++11 or above
#include <iostream>
#include <array>
#include<unordered_map>

using namespace std; 

// function to print combinations that contain 
// one element from each of the given arrays 
void print_all_points(array <array<int,3>, 6> & arr) 
{ 

	// to keep track of next element in each of 
	// the n arrays 
	int* indices = new int[6]; 

	// initialize with first element's index 
	for (int i = 0; i < 6; i++) {indices[i] = 0;}

    // map of match pnts
    int mp[4]={3,1,0,0};
    int i=0;
	while (1) { 
        // initialize the 4 teams
        int A=0,B=0,C=0,D=0;

		// get current combination
        i++;
		A+=arr[0][indices[0]]+arr[1][indices[1]]+arr[2][indices[2]];
        B+=mp[arr[0][indices[0]]]+arr[3][indices[3]]+arr[4][indices[4]];
        C+=mp[arr[1][indices[1]]]+mp[arr[3][indices[3]]]+arr[5][indices[5]];
        D+=mp[arr[2][indices[2]]]+mp[arr[4][indices[4]]]+mp[arr[5][indices[5]]];
		cout <<i<< ". "<<"A: "<<A<<", B: "<<B<<", C: "<<C<<", D: "<<D<< endl; 

		// find the rightmost array that has more 
		// elements left after the current element 
		// in that array 
		int next = 5; 
        // while(next>=0) {next--;}
		while (next >= 0 && (indices[next] + 1 >= 3)) {next--;}

		// no such array is found so no more 
		// combinations left 
		if (next < 0) 
			return; 

		// if found move to next element in that 
		// array 
		indices[next]++; 

		// for all arrays to the right of this 
		// array current index again points to 
		// first element 
		for (int i = next + 1; i < 6; i++) 
			indices[i] = 0; 
	} 
} 

// driver function to test above function 
int main() 
{ 
	// initializing a vector with 3 empty vectors 
	// vector<int[3] > arr(6, {0,1,3});
    array<int,3> IntPnts={0,1,3};
    array <array<int,3>, 6> arr;
    arr.fill(IntPnts);
	print_all_points(arr); 
} 
