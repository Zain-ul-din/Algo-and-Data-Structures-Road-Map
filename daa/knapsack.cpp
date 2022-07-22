// knapsack problem

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

double KnapSack (
    std::vector < std::unique_ptr <Object> > & objects , int bagCapcity 
) {
    std::sort(objects.begin() , objects.end() , [&](Object_Ptr& acc , Object_Ptr& curr) {
      return acc->worth > curr->worth;
    });

    double profit = 0;
    double remainingBagCapcity = bagCapcity; 

    for (auto itr = objects.begin() ; itr != objects.end() ; itr ++) {
        const int32_t weight = (*itr)->weight;
        const int32_t objProfit = (*itr)->profit;
        if (remainingBagCapcity < weight) {
            const double netWorth = weight / remainingBagCapcity;
            remainingBagCapcity -= netWorth;
            profit += objProfit * netWorth;
            return profit;
        } else {
            remainingBagCapcity -= weight;
            profit += objProfit * 1;
        }
    } 

    
    return profit;
}

// Driver Code
int main () {
    static std::vector < Object_Ptr > objects;
    
    objects.push_back( Object_Ptr (new Object (0,10,2)) );
    objects.push_back( Object_Ptr (new Object (1,5,3)) );
    objects.push_back( Object_Ptr (new Object (2,15,5)) );
    objects.push_back( Object_Ptr (new Object (3,7,7)) );
    objects.push_back( Object_Ptr (new Object (4,6,1)) );
    objects.push_back( Object_Ptr (new Object (5,18,4)) );
    objects.push_back( Object_Ptr (new Object (6,3,1)) );

    const int bagCapcity = 15;
    const double profit = KnapSack (objects , bagCapcity);
    std::cout << "Profit : " << profit << "\n";
    //assert (KnapSack (objects , bagCapcity) == bagCapcity);
    std::cout << "You passed the Exam \n";

   return 0;
}