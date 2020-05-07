/* #include <iostream>
#include <string>
using std::string;

class Vehicle {
public:
    int wheels = 0;
    string color = "blue";
    int seats = 0;
    string name = "vehicle";
    
    void Print() const
    {
        std::cout << "This " << color << " "<< name<<" has " << wheels << " wheels and "<<seats<<" Number of seats!\n";
    }
};
class Truck:public Vehicle{
    public:
    bool fourwd = true;
};

class Car : public Vehicle {
public:
    bool sunroof = false;
};

class Bicycle : public Vehicle {
public:
    bool kickstand = true;
};

int main() 
{
    Car car;
    car.wheels = 4;
    car.sunroof = true;
    car.Print();
    if(car.sunroof)
        std::cout << "And a sunroof!\n";
    Truck truck;
    truck.name = "truck";
    truck.wheels = 8;
    truck.seats = 7;
    truck.Print();

    
}; */

// This example demonstrates the privacy levels
// between parent and child classes
#include <iostream>
#include <string>
using std::string;

class Vehicle {
public:
    int wheels = 0;
    string color = "blue";
    
    void Print() const
    {
        std::cout << "This " << color << " vehicle has " << wheels << " wheels!\n";
    }
};

class Car : public Vehicle {
public:
    bool sunroof = false;
};

class Bicycle : public Vehicle {
public:
    bool kickstand = true;
    //color = "yellow";
    Print();
};

class Scooter : private Vehicle {
public:
    bool electric = false;
};

int main() 
{
    Car car;
    Bicycle bicycle;
    Scooter scooter;
    car.color = "green";
    //scooter.color = "Pink";
    car.Print();
    //scooter.Print();
};