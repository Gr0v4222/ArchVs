#include <iostream> 
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
using namespace std; 
 
int main() 
{ 
    srand(5); //srand(87)
    int N = 0; 
    cin >> N; 
    int * intArray = new int [N]; 
    cout << "Sizeof int = "<<sizeof(intArray[0]) << endl; 
    cout << "Arr: "; 
    intArray[0] = rand() % N; 
    cout << intArray[0]; 
    for(int i=1;i<N;i++) 
    { 
    intArray[i] = rand() % N; 
    cout << "," << intArray[i]; 
    } 
    cout << "\n"; 
    delete [] intArray; 
return 0; 
} 
