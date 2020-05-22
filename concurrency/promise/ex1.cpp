#include <thread>
#include <iostream>

void printMsg(std::string msg)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(7));
    std::cout<<"Thread 1: "<<msg<<std::endl;
}

int main()
{
    std::string mesg = "My Message";
    std::thread t1(printMsg, mesg);//parse by variate function
    std::thread t2([mesg]
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
        std::cout<<"Thread 2: "<<mesg<<std::endl;
    });

    t1.join();
    t2.join();
    return 0;
}