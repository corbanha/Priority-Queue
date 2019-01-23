#ifndef PQUEUE_H
#define PQUEUE_H

class PQueue{
  public:
    PQueue();
    PQueue(int optimSize);
    ~PQueue();
  
    /*read the thing that is most front from the queue, doesn't take it off though */
    int top();
    
    /*read the thing that is most in front from the queue, and also takes it off the front */
    int pop();
    
    /*returns the number of items in the PQueue */
    int size();
    
    /*put a new number into the queue and it will be put in based on the priority */
    bool push(int num);
    
    void printPQueue();
  
  private:
  
  /* this will expand our array to the new size, it will be called when the array gets full */
  void expandArray(int newSize);
  
  /*when we add a new item to the heap, we'll call this guy on that index and
  this guy will travel it up the heap swapping based on priority as necessary */
  void percolateUp(int index);
  
  /*when we remove an item from the heap and the last item is moved here, this
  function will follow it down */
  void percolateDown(int index);
  
 
  
  int *array;
  int numItems;
  int arraySize;
 
  
};

#endif