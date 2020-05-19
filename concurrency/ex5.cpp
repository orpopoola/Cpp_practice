#include <iostream>
#include <thread>

void threadFunctionEven()
{
    std::this_thread::sleep_for(std::chrono::milliseconds(1)); // simulate work
    std::cout << "Even thread\n";
}

/* Student Task START */
void threadFunctionOdd()
{
    std::this_thread::sleep_for(std::chrono::milliseconds(1));
    std::cout << "Odd thread \n";
}

/* Student Task END */

int main()
{
    /* Student Task START */
    int nthread = 6;
    for (int i = 0; i<nthread; ++i)
    {
        if (i%2==0){std::thread t(threadFunctionEven);t.detach();}
        else if(i%2==1){std::thread t(threadFunctionOdd);t.detach();}
    }

    /* Student Task END */
    // ensure that main does not return before the threads are finished
    //std::this_thread::sleep_for(std::chrono::milliseconds(1)); // simulate work

    std::cout << "End of main is reached" << std::endl;
    return 0;
}
