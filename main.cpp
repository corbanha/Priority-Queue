#include <iostream>
#include <cstdlib>
#include <cstring>
#include "PQueue.h"

int main(){
    PQueue pq;
    
    
    std::cout << "Adding bunches of random numbers! " << std::endl;
    
    std::srand(time(0));
    
    for(int i = 0; i < 110; i++){
        int rand = std::rand() % 1000;
        std::cout << rand << " ";
        pq.push(rand);
    }
    
    pq.printPQueue();
    
    std::cout << "Popping!" << std::endl;
    while(pq.size() > 0){
        std::cout << pq.pop() << " ";
    }
    
    return 0;
}