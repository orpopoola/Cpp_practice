#include <thread>
#include <string>
#include <iostream>

void printID (int id)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    std::cout<<"The ID is: "<<id<<std::endl;
}

void printIDandName(int id, std::string name)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    std::cout<<"The ID is: "<<id<<" and the name is: "<<name<<std::endl;
}

int main(){
    int id=0;
    std::thread t1(printID, id);
    t1.join();
    std::thread t2(printIDandName, ++id, "Eight");
    t2.join();
    //std::thread t3(printIDandName, ++id);
    std::thread t4(printID, ++id);
    //std::thread t5(printID);

    //t3.join();
    t4.join();
    //t5.join();
}