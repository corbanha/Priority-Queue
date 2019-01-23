#include "PQueue.h"
#include <iostream>


PQueue::PQueue(){
    numItems = 0;
    arraySize = 100;
    
    array = new int[arraySize];
}


PQueue::PQueue(int optimSize){
    numItems = 0;
    arraySize = optimSize;
    array = new int[arraySize];
}


PQueue::~PQueue(){
    while(numItems > 0){
        pop();
    }
    delete array;
}

/*read the thing that is most front from the queue, doesn't take it off though */
int PQueue::top(){
    return array[0];
}

/*read the thing that is most in front from the queue, and also takes it off the front */
int PQueue::pop(){
    int front = array[0];
    array[0] = array[numItems - 1];
    
    //delete array[numItems - 1];
    //array[numItems - 1] = NULL;
    
    numItems--;
    percolateDown(0); //perculate down from the first index
    return front;
}

/*returns the number of items in the PQueue */
int PQueue::size(){
    return numItems;
}

/*put a new number into the queue and it will be put in based on the priority */
bool PQueue::push(int num){
    if(numItems + 1 > arraySize){
        expandArray(arraySize * 2);
    }
    
    array[numItems] = num;
    percolateUp(numItems);
    numItems++;
    return true;
}
    
/* this will expand our array to the new size, it will be called when the array gets full */
void PQueue::expandArray(int newSize){
    
    int* tempToDelete = array;
    array = new int[arraySize * 2];
    
    for(int i = 0; i < arraySize; i++){
        array[i] = tempToDelete[i];
    }
    
    arraySize *= 2;
    delete tempToDelete;
}

/*when we add a new item to the heap, we'll call this guy on that index and
this guy will travel it up the heap swapping based on priority as necessary */
void PQueue::percolateUp(int index){
    int parent = (index - 1) / 2;
    
    //we'll compare it and swap any of it's children with the parent if the child
    //has a higher priority than it, then we'll keep going up!
    if(array[index] < array[parent]){
        //the child has higher priority than the parent so we'll swap them
        int temp = array[parent];
        array[parent] = array[index];
        array[index] = temp;
        
        if(parent != 0) percolateUp(parent); //if the parent is index 0 then we've swapped the item in and that's as far as we can go
    }
}

/*when we remove an item from the heap and the last item is moved here, this
function will follow it down */
void PQueue::percolateDown(int index){
    int child1Index = index * 2 + 1;
    int child2Index = index * 2 + 2;
    
    
    //now lets compare it and see if it needs to be swapped with any of it's children
    //the code below assumes that the lower the int, the greater the priority
    if(child1Index < numItems && array[child1Index] < array[child2Index]){
        //child1 has higher priority than child2
        if(array[child1Index] < array[index]){
            //child has higher priority than parent so we'll swap
            int temp = array[index];
            array[index] = array[child1Index];
            array[child1Index] = temp;
            
            //let's continue to perculate down
            percolateDown(child1Index);
        }
        
    }else if(child2Index < numItems){
        //they have the same or, child2 has greater priority than child1
        if(array[child2Index] < array[index]){
            //child2 has higher priority than the parent so we'll swap
            int temp = array[index];
            array[index] = array[child2Index];
            array[child2Index] = temp;
            
            //let's continue to perculate down
            percolateDown(child2Index);
        }
    }
    //else{} the kids are outside the array so we hit the bottom
}

void PQueue::printPQueue(){
    std::cout << std::endl << "[";
    for(int i = 0; i < numItems; i++){
        std::cout << array[i];
        if(i + 1 < numItems){
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;
    
    int numForLine = 1;
    int spacing = numItems; //this is just spacing and it isn't super accurate
    
    for(int i = 0, j = 0; i < numItems; i++){
        
        for(int k = 0; k < spacing; k++){
            std::cout << " ";
        }
        
        std::cout << array[i];
        
        j++;
        if(j == numForLine){
            std::cout << std::endl;
            j = 0;
            numForLine *= 2;
            spacing /= 2;
        }
    }
    
    std::cout << std::endl;
    
}