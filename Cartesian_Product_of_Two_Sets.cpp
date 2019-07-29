// C++ Program to find the Cartesian Product of Two Sets 
#include <stdio.h> 

void findCart(int arr1[], int arr2[], int n, int n1) 
{ 
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < n1; j++) 
			printf("{%d, %d}, ", arr1[i], arr2[j]); 
} 

int main() 
{ 
	int arr1[] = { 1, 2, 3 }; // first set 
	int arr2[] = { 4, 5, 6 }; // second set 
	int n1 = sizeof(arr1) / sizeof(arr1[0]); 
	int n2 = sizeof(arr2) / sizeof(arr2[0]); 
	findCart(arr1, arr2, n1, n2); 
	return 0; 
} 

// Input : A = {1, 2}, B = {3, 4}
// Output : A × B = {{1, 3}, {1, 4}, {2, 3}, {2, 4}}

// Input  : A = {1, 2, 3} B = {4, 5, 6}
// Output : A × B = {{1, 4}, {1, 5}, {1, 6}, {2, 4}, 
//          {2, 5}, {2, 6}, {3, 4}, {3, 5}, {3, 6}}