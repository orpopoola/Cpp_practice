#include <string>
#include <cstring>
#include <iostream>
using std::string;

class Car {
    // TODO: Declare private attributes
    private:
    int car_id;
    std::string car_brand;
    int horsepower;
    int weight;
        
    // TODO: Declare getter and setter for brand
    public:
    void sCar_id(int car_id_);
    void sCar_brand(string car_brand_);
    void sHorsepower(int horsepower_);
    void sWeight(int weight_);
    //getters
    int gCar_id() const;
    std::string gCar_brand() const;
    int gHorsepower() const;
    int gWeight() const;
};

// Define setters
void Car::sCar_id(int car_id_){Car::car_id = car_id_;}
void Car::sCar_brand(string car_brand_){Car::car_brand = car_brand_;}
void Car::sHorsepower(int horsepower_){Car::horsepower = horsepower_;}
void Car::sWeight(int weight_){Car::weight = weight_;}
// Define getters
int Car::gCar_id() const{return Car::car_id;}
std::string Car::gCar_brand() const{return Car::car_brand;}
int Car::gHorsepower() const{return Car::horsepower;}
int Car::gWeight() const{return Car::weight;}
// Test in main()
int main() 
{
    Car car;
    car.sCar_brand("Peugeot");
    std::cout << car.gCar_brand() << "\n";   
}