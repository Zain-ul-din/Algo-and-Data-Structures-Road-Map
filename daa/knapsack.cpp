// knapsack problem
/*
  Don't Edit any code start coding from line no 30
*/
#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <assert.h>

class Object final {
public:
    Object (int32_t idx , int32_t profit , int32_t weight) 
    : idx (idx) , profit (profit) , weight (weight) {
        worth = this->profit / this->weight; // P / W
    }
    int32_t idx , profit , weight;
    double worth;
};

#define Object_Ptr std::unique_ptr <Object> 
#define INSERT_OBJECTS(I,P,W) objects.push_back( Object_Ptr ( new Object (I,P,W)));

/*
  TODOS : write KnapSack function to find profit with maximum bag capcity
*/
double KnapSack (
    std::vector < std::unique_ptr <Object> > & objects , int bagCapcity 
) {
    // write you're code here
}

// don't edit main
int main () {
    static std::vector < Object_Ptr > objects;
    
    INSERT_OBJECTS(0,10,2);
    INSERT_OBJECTS(1,5,3);
    INSERT_OBJECTS(2,15,5);
    INSERT_OBJECTS(3,7,7);
    INSERT_OBJECTS(4,6,1);
    INSERT_OBJECTS(5,18,4);
    INSERT_OBJECTS(6,3,1);

    const int bagCapcity = 15;
    const double profit = KnapSack (objects , bagCapcity);
    std::cout << "Profit : " << profit << "\n";
    assert (profit == [&]()->double{
     std::sort(objects.begin() , objects.end() , [&](Object_Ptr& acc , Object_Ptr& curr) {
      return acc->worth > curr->worth;
     });

     double profit = 0;
     double remainingBagCapcity = bagCapcity; 

     for (auto itr = objects.begin() ; itr != objects.end() ; itr ++) {
        const int32_t weight = (*itr)->weight;
        const int32_t objProfit = (*itr)->profit;
        if (remainingBagCapcity < weight) {
            const double netWorth = remainingBagCapcity / weight ;
            remainingBagCapcity -= netWorth;
            profit += objProfit * netWorth;
            return profit;
        } else {
            remainingBagCapcity -= weight;
            profit += objProfit * 1;
        }
     } 
     return profit;
    }());
    std::cout << "You passed the Exam \n";
    return 0;
}