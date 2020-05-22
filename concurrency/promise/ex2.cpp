#include <thread>
#include <iostream>
#include <future>

void modifyMessage(std::promise<std::string> &&prms, std::string msg)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(4000)); // simulate work
    std::string modMsg = msg+ " has been modified";
    prms.set_value(modMsg);
}

int main()
{
    // define message
    std::string msg = "Hello world";

    //create promise and future
    std::promise<std::string> prm;
    std::future<std::string> ftr = prm.get_future();

    //start thread with promise moved in  as argument
    std::thread t(modifyMessage, std::move(prm), msg);

    //print out original message to console
    std::cout<<"Original message from main: "<< msg<<std::endl; 

    //retrieve modified message via future link
    std::string messageFromThread = ftr.get();
    std::cout<<"Message from the future link: "<<messageFromThread<<std::endl;

    //wait for thread to complete
    t.join();

    return 0;
}