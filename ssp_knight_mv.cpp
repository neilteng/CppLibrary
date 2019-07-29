// Minimum steps to reach target by a Knight
// C++ program to find minimum steps to reach to 
// specific cell in minimum moves by Knight 
/************************************************************
 **********************************BFS ***************************
********************************************************************/

#include <iostream> 
#include<queue>
#include <stdio.h>
#include <string.h>
using namespace std; 

// structure for storing a cell's data 
struct cell 
{ 
	int x, y; 
	int dis; 
	cell() {} 
	cell(int x, int y, int dis) : x(x), y(y), dis(dis) {} 
}; 

template <class T, size_t W, size_t H>
class Array2D
{
public:
    const int width = W;
    const int height = H;
    // typedef typename T type;

    Array2D()
        : buffer(width*height)
    {
    }

    inline T& at(unsigned int x, unsigned int y)
    {
        return buffer[y*width + x];
    }

    inline const T& at(unsigned int x, unsigned int y) const
    {
        return buffer[y*width + x];
    }

private:
    std::vector<T> buffer;
};
// Utility method returns true if (x, y) lies 
// inside Board 
bool isInside(int x, int y, int N) 
{ 
	if (x >-1 && x < N && y >-1 && y < N) {return true; }
	return false; 
} 

// Method returns minimum step to reach target position 
int minStepToReachTarget(int knightPos[], int targetPos[], int N, int a, int b) 
{ 
	// x and y direction, where a knight can move 
	int dx[] = {a, a, -a, -a, b, b, -b, -b};
	int dy[] = {b, -b, b, -b, a, -a, a, -a}; 

	// queue for storing states of knight in board 
	queue<cell> q; 

	// push starting position of knight with 0 distance 
	q.push(cell(knightPos[0], knightPos[1], 0)); 

	cell t; 
	int x, y; 
	bool *visit=new bool[10000*10000];

	// make all cell unvisited 
	for (int i = 0; i < N; i++) 
		for (int j = 0; j < N; j++) 
			visit[j*10000+i] = false; 

	// visit starting state 
	visit[knightPos[0]+10000*knightPos[1]] = true; 

	// loop untill we have one element in queue 
	while (!q.empty()) 
	{ 
		t = q.front(); 
		q.pop(); 

		// if current cell is equal to target cell, 
		// return its distance 
		if (t.x == targetPos[0] && t.y == targetPos[1]){
			delete[] visit;
			return t.dis; 
		}
			
		// loop for all reachable states 
		for (int i = 0; i < 8; i++) 
		{ 
			x = t.x + dx[i]; 
			y = t.y + dy[i]; 

			// If reachable state is not yet visited and 
			// inside board, push that state into queue 
			if (isInside(x, y, N) && !visit[y*10000+x]){
				visit[y*10000+x] = true; 
				q.push(cell(x, y, t.dis + 1)); 
			}
		}
	}
	delete[] visit;
	
	return -1;
}

// Driver code to test above methods 
int main() 
{
	cout<<"please type the size of the board N: "<<endl;
	int N;
	cin>>N;
	cout<<"please type a,b for knight(a,b), seperate by space: "<<endl;
	int a,b;
	cin>>a>>b;
	int knightPos[] = {0, 0};
	int targetPos[] = {N-1, N-1}; 
	cout <<"ssp: "<< minStepToReachTarget(knightPos, targetPos, N, a, b)<<endl; 
	return 0; 
}
