#include <iostream>
#include <algorithm>

// Driver Code
int main() {

   int choice;

   int arr[10];
   int const SIZE = 10;

   for(int  i = 0 ; i < SIZE ; i++ )
       arr[i] = -1;

   int currentIdx = 0;
   // Menu System

   do{

       std::cout << "1 _ Insert Data \n ";
       std::cout << "2 _ Display Data \n ";
       std::cout << "3 _ Delete Data \n ";
       std::cout << "4 _ Update Data \n ";
       std::cout << "5 _ Search Data \n ";
       std::cout << "6 _ Sort Data \n ";
       std::cout << "7 _ Reverse List \n ";
       std::cout << "8 _ MAX Data \n ";
       std::cout << "9 _ MIN Data \n ";
       std::cout << "10 _ Average Data \n ";
       std::cout << "11 _ Remove All Data \n ";
       std::cout << "12 _ Check Array is Empty \n ";
       std::cout << "13 _ Check Array is full \n ";
       std::cout << "14 _ exit \n";

       std::cout << "Enter Choice : "; std:: cin >> choice;

       if(choice == 1){ // Insert Data
         if(currentIdx != SIZE){
            int newVal;
            std::cout << "\t Enter New Val : ";
            std::cin >>  newVal;
            arr[currentIdx] = newVal;
            currentIdx ++;
            std::cout << "\t value has been added\n";
         }else std::cout << "\nArray is Already Full !\n";
       }
       else if(choice == 2){ // print data
         int _choice;
         std::cout << "Display full - 1\n";
         std::cout << "Display till mid - 2\n";
         std::cout << "Display from mid - 3\n";
         std::cout << "Display display From range - 4\n";

         std::cout << "Enter Choice : ";
         std::cin >> _choice;

         if(_choice == 1){
             for(int  i =0 ; i < SIZE ; i++)
                 std::cout << " " << arr[i] << " ";
             std::cout << "\n";
         }
         else if(_choice == 2){
             for(int i = 0 ; i< SIZE/2 ; i++)
                 std::cout << " " << arr[i] << " ";
             std::cout << "\n";
         }
         else if(_choice == 3){
             for(int i = SIZE/2 ; i < SIZE ; i ++)
                 std::cout << " " << arr[i] << " ";
             std::cout << "\n";
         }
         else if(_choice == 4){
             std::cout << "Enter Range : ";
             int range ; std::cin >> range;
             std::abs(range);
             if(!range >= SIZE){
                 for(int  i = range ; i < SIZE ; i++)
                     std::cout << " " << arr[i] << " ";
                 std::cout << "\n";
             }
             else std::cout << "Invalid Range !\n";
         } else std::cout << "Invalid Choice !\n";
       } // display
       else if(choice == 3){ // delete data
           if(currentIdx != 0){
              std::cout << "Enter Idx u want to delete\n";
              int idx;
              std::cin >> idx;
              if(idx == currentIdx){
                  arr[currentIdx] = -1;
                  currentIdx -=1;
              }
              else if(idx < currentIdx){
                  for(int  i = idx ; i < currentIdx ; i++){
                    // swap
                    if(i+1 != SIZE){ // to prevent out of idx
                        int temp = arr[i];
                        arr[idx] = arr[i+1];
                        arr[i+1] = temp;
                    }
                  }
                  arr[currentIdx] = -1;
                  currentIdx -= 1;
              } else std::cout << "\nInvalid Idx !";
           } else std::cout << "\nArray is Already Empty !";
       }
       else if(choice == 4){
           int idx;
           std::cout << "Enter Idx where you wana to update data : ";
           std::cin  >> idx;

           std::abs(idx);
           if(idx <= currentIdx){
              int newData;
              std::cout << "Enter new Data : ";
              std::cin >> newData;
              std::abs(newData);
              arr[idx] = newData;
           } else std::cout << "Invalid Idx \n";
       }
       else if(choice == 5){ // search Data
          int data;
          std::cout << "Enter Data : ";
          std::cin >>data;

          bool isFound = false;

           int _choice;
          std::cout << "\n Linear Search - 1\n";
          std::cout << "\n Binary Search - 2\n";
          std::cout << "Enter choice _ "; std::cin >> _choice;

          if(_choice == 1){
              for(int  i =0 ; i<SIZE ; i++)
                  if(data == arr[i]){
                      isFound = true;
                      break;
                  }
          }
          else if(_choice == 2){
              int startIdx = 0;
              int endIdx = currentIdx;
              int midIdx ;
              while(startIdx <= endIdx){
                  midIdx = (startIdx + endIdx) / 2;

                  if(data == arr[midIdx]){
                      isFound = true;
                      break;
                  }
                  else if(data < arr[midIdx]){
                      endIdx = midIdx -1;
                  }
                  else if(data > arr[midIdx]){
                      startIdx = midIdx +1;
                  }
              }
          }
          std::cout << ((isFound) ? "\n Data Found" : "Data not Found\n");
       }
       else if(choice == 6){ // sort data
           std::cout << " Sort in Ascending order 1\n";
           std::cout << " Sort in Descending order 1\n";
           int _choice;
           std::cout << "Enter Choice : ";
           std::cin >> _choice;

           if(_choice == 1){
               std::sort(arr,arr+SIZE);
               std::cout<< "Array has been Sorted !\n";
           }
           else if(choice == 2){
               std::sort(arr+SIZE , arr);
               std::cout<< "Array has been Sorted !\n";
           } else std::cout << "Invalid Choice \n";
       }
       else if(choice == 7){
           int itr = currentIdx;
           while(itr--)
              std::cout << " " << arr[itr] << " ";
           std::cout << "\n";
       }
       else if(choice == 8){
        int max = arr[0];

        for(int i =0 ; i <SIZE ; i ++)
            if(arr[i] > max)
                max = arr[i];

        std::cout << "\n Max is : "<<max <<"\n";
       }
       else if(choice == 9){
           int min = arr[0];

           for(int i =0 ; i <SIZE ; i ++)
               if(arr[i] < min)
                   min = arr[i];

           std::cout << "\n Min is : "<<min <<"\n";
       }
       else if(choice == 10){
          int sum = 0;
          int count = 0;
          for(int  i = 0 ; i <SIZE ; i++)
              if(arr[i] != -1){
                  sum += arr[i];
                  count +=1;
              }
          std::cout << "\n Average is : "<< (sum / count) <<"\n";
       }
       else if(choice == 11){
          currentIdx = 0;
           for(int i =0 ; i < SIZE ; i++)
               arr[i] = -1;
       }
       else if(choice == 12){
         std::cout << ((currentIdx == 0 && arr[currentIdx] ==-1) ? "\nArray is Empty\n" : "Array is not Empty!\n");
       }
       else if(choice == 13){
          std::cout << ((currentIdx >= SIZE-1) ? "Array is Full \n" : "Array is not full\n");
       }
       else choice = 0;

       system("pause");
   }while(choice != 0);
}