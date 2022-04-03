#include <algorithm>
#include <numeric>
#include <utility>
#include <iostream>

void PrintMatrix (int arr[][4] , int rowSize , int colSize ){
    if(rowSize < 0) return;
    
    const int COL = colSize;

    while(colSize--)
       std::cout << arr[rowSize] [colSize] << " ";

    rowSize -= 1;
    std::cout << "\n";
    PrintMatrix(arr , rowSize , COL);   
}

int main() {
int arr[3][4];
std::iota((int*)arr, (int*)arr + 12, 0);

 PrintMatrix(arr , 3-1 ,4-1);


}