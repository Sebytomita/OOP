#ifndef NUMBERLIST_H
#define NUMBERLIST_H

class NumberList
{
    int *numbers; 
    int count;    
    int capacity; 
public:
    NumberList();          // Constructor
    ~NumberList();         // Destructor
    void Init();           
    bool Add(int x);       
                           
    void Sort();           
    void Print();          
};

#endif
