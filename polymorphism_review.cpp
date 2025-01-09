#include<iostream>
#include<string>



using namespace std;


class Car{
    
    private:
        std::string name;
        int year;
        
    
    public:
        
        static int carCount;
        
        Car(std::string s, int i): name(s), year(i) {
            carCount++;
            
        }
        
        Car(std::string s): name(s) {
            
            year = 1;
            carCount++;
            
        }
        
        // Getters member functions
        std::string getName(){
            
            return name;
            
        }
        
        int getYear(){
            
            return year;
        }
        
        // Setter member functions
        void setName(const std::string& nameNew){
            
            name = nameNew;
        }
        
        void setYear(int y){
            
            year = y;
        }
        
    
};


// Definition of static variable
int Car::carCount = 0;

int main()
{
    
    Car* mycar = new Car("Honda", 2012);  // heap allocation for object instantiation
    Car* mycar2 = new Car("BMW", 2020);  // heap allocation for object instantiation
    Car* mycar3 = new Car("BMW", 2023);  // heap allocation for object instantiation
    
    std::cout << mycar -> getYear() << endl;
    std::cout << mycar -> getName() << endl;
    
    mycar -> setName("Toyota"); 
    std::cout << mycar -> getName() << endl;
    
    std::cout << "Total cars created: " << Car::carCount << endl;
    
    return 0;
}
