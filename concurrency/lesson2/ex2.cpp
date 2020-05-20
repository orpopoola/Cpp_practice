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
    //std::thread t(Vehicle()); //C++ most vexing parse
    //Solutions
    std::thread t1((Vehicle())); //An extra pair of parenthesis
    std::thread t2 = std::thread(Vehicle()); //using copy initialization
    std::thread t3{Vehicle()}; //Use normal initialization but with braces

    //do sth in main
    std::cout<<"Running sth in the main function \n";

    //wait for thread to complete
    t1.join();
    t2.join();
    t3.join();
    return 0;
}