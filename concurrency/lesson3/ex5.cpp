#include <iostream>
#include <string>
#include <thread>

class Vehicle
{
    public:
    Vehicle():_id(0){}
    void addID(int id){ _id = id;}
    void printID()
    {
        std::cout<< "Vehicle ID is: "<<_id<<std::endl;
    }
    void setName(std::string name)
    {
        _name = name;
    }
    void printName()
    {
        std::cout<<"The name is: "<<_name<<std::endl;
    }
    private:
    int _id;
    std::string _name;
};

int main()
{
    std::shared_ptr<Vehicle> v(new Vehicle);
    std::thread t1 = std::thread(&Vehicle::addID,v,1);

    std::thread t2 = std::thread(&Vehicle::setName, v, "Ade");

    //wait for thread to finish
    t1.join();
    t2.join();
    //print vehicle id
    v->printID();
    v->printName();
    return 0;
}