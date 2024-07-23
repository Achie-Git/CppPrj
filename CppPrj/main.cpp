#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <memory>

#include "utility.h"

class DynamicInt
{
public:
    DynamicInt() : intPtr{ new int {0} }
    {

    }

    DynamicInt(const DynamicInt& other) : intPtr{ new int {other.getValue()}}
    {
        std::cout << "Copy con\n";
    }

    DynamicInt(int value) : intPtr{ new int {value} }
    {
        std::cout << "One param constructor" << std::endl;
    }

    void setValue(int newVal)
    {
        *intPtr = newVal;
    }
    int getValue() const { return *intPtr; }

    ~DynamicInt()
    {
        std::cout << "Destructor got called" << std::endl;
        delete intPtr;
        intPtr = nullptr;
    }
private:
    int* intPtr;
};

DynamicInt ConstructorDynaInt(int val)
{
    DynamicInt dInt{ val };
    return dInt;
}

int main() {
    
    DynamicInt intCOne = ConstructorDynaInt(20);

    std::cout << intCOne.getValue() << std::endl;

    return 0;
}