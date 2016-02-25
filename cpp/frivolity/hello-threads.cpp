#include <iostream>
#include <thread>
#include <vector>


void hello() {
    std::cout << "hello from thread " << std::this_thread::get_id() << "\n";
}


int main()
{
    std::vector<std::thread> threads;

    for (int i = 0; i < 5; i++) {
        // threads.push_back(std::thread(hello));
        threads.push_back(std::thread([] () {
                    std::cout << "Hello from thread " << std::this_thread::get_id() << std::endl;
                    }));
    }

    for(auto& thread: threads) {
        thread.join();
    }
    
    return 0;
}
