#include <iostream>
#include <thread>

//this program prints the id of the main thread
int main(){
    std::cout<<"The ID of the main thread is: "<<std::this_thread::get_id()<<std::endl;
    return 0;
}