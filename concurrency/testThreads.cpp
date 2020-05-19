#include <thread>
#include <vector>
#include <algorithm>

int main(){
    std::vector<std::thread> threads;

    //start up n threads
    int nthread = 4;
    for(int i=0; i<nthread; i++)
    {
        threads.emplace_back(std::thread([](){
            while(true);
        }));
    }

    //wait for thread to finish before leaving main
    std::for_each(threads.begin(), threads.end(), [](std::thread &t){
        t.join();
    });

    return 0;
}