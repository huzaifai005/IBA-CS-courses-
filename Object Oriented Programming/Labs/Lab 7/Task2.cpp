#include <iostream>
#include <string>

class Base
{
public:
    void identity()
    {
        std::cout << "diamond base" << std::endl;
    };
};
// incorrect way of inheriting
//compiler does not know which path to take, it can go through 2 ways right now, from left to base or right to base.
//  class Left: public Base{
//  };

// class Right: public Base {
// };


// correct way of inheriting
class Left : virtual public Base
{
};

class Right : virtual public Base
{
};

class Final : public Left, public Right
{
};

int main()
{
    Final f;
    Base *base = &f; // duplicate base instances are removed.

    base->identity(); // gives us correct output.
}