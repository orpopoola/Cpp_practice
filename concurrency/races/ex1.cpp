#include <thread>
#include <future>
#include <iostream>

class Vehicle
{
public:
    Vehicle(): _id(0)  //default constructor
    {
        std::cout<< "Vehicle #" << _id << " Default constructor called" << std::endl;
    }

    Vehicle(int id) :_id(id)
    {
        std::cout<<"Vehicle #" << _id << " Initializing constructor called" << std::endl;
    }
    //setter and getter
    void setID(int id){ _id = id; }
    int getID(){ return _id; }

private:
    int _id;
};

int main()
{
    //create instances of the vehicle class
    Vehicle v0; //uses default constructor
    Vehicle v1(1); //uses other constructor

    //read and write name in different threads
    std::future<void> ftr = std::async([](Vehicle v){
        std::this_thread::sleep_for(std::chrono::milliseconds(500)); 
        v.setID(2);
    }, v0);

    v0.setID(3);
    ftr.wait();
    std::cout << "Vehicle #" << v0.getID() << std::endl;

    return 0;
}