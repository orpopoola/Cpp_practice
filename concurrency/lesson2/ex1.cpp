#include <iostream>
#include <thread>

class Vehicle
{
    public:
    void operator()(){
        std::cout<<"Vehicle object has been created \n";
    }
};

int main()
{
    //creat thread
    std::thread t(Vehicle()); //C++ most vexing parse

    //do sth in main
    std::cout<<"Running sth in the main function \n";

    //wait for thread to complete
    t.join();
    return 0;
}