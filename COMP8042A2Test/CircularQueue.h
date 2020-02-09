#include <iostream>
#include <vector>

using namespace std;

template <typename Object>
class queue
{
public:
    queue(int s) { }
    queue () { }
    ~queue() { }
    void enque(Object obj)
    {
    }
    
    Object deque()
    {
        return (Object)0;
    }
    
    bool empty() {return true;}
    
    bool full() { return false;}
    
    void print() {
    }
    
private:
};

