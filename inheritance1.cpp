#include<iostream>
#include<string>

using namespace std;


class Animal{
    
    protected:
        std::string name;
        int age;
    
    public:
        Animal(std::string n, int a): name(n), age(a) {}
        
    
};

class Cat: private Animal {
    
    private:
        std::string furColour;
    
    
    public:
        
        Cat(std::string n, int a, std::string furC): Animal(n, a), furColour(furC) {}
        
        
        void meow(){
            
            std::cout << "Meow" << endl;
            
        }
        
    
    
};

int main()
{
    Cat* mycat = new Cat("Tom", 10, "Blue");
    
    
    return 0;
}
