#include <iostream>
#include <thread>
#include <mutex>
#include <vector>


struct Counter {
    std::mutex maimu;
    unsigned int value;

    Counter() : value(0) {}
    void increment() {
        std::lock_guard<std::mutex> l(maimu);
        ++value;
    }
};


int main()
{
    Counter counter;
    std::vector<std::thread> threads;
    for (int i = 0; i < 10; ++i) {

        threads.push_back(std::thread(
                    [&counter] () {
                    for (int j = 0; j < 10000; ++j) {
                        counter.increment();
                    }
                    }));

    }

    for(auto& thread : threads) {
        thread.join();
    }

    std::cout << counter.value << std::endl;
    
    return 0;
}
