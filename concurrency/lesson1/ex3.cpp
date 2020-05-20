#include <thread>
#include <iostream>

void threadFunction()
{
    std::this_thread::sleep_for(std::chrono::milliseconds(100)); // simulate work
    std::cout<<"Finished running a 100ms work on this thread"<<std::endl;
}

int main()
{
    //create thread
    std::thread t(threadFunction);

    //do someother work here -could be threads
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    std::cout<<"Finished work in main function"<<std::endl;

    //wait for the thread to end
    t.join();

    //end main
    return 0;
}