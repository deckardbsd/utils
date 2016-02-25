#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <stdarg.h>
#include <stdlib.h>



template <typename T>
class container {
    private:
        std::recursive_mutex _lock; 
        std::vector<T> _elements;

    public:
        void add(T element) {
            std::lock_guard<std::recursive_mutex> locker(_lock);
            _elements.push_back(element);
        }

        void addrange(int num, ...) {
            va_list arguments;
            va_start(arguments, num);

            for (int i = 0; i < num; ++i) {
                std::lock_guard<std::recursive_mutex> locker(_lock);
                add(va_arg(arguments, T));
            }

            va_end(arguments);
        }

        void dump() {
            std::lock_guard<std::recursive_mutex> locker(_lock);
            for(auto e: _elements)
                std::cout << e << std::endl;
        }

};


void func(container<int>& my_container, unsigned int num) {
    srand((unsigned int ) time(0));

    for (unsigned int i = 0; i < num; ++i) {
        my_container.addrange(1, rand());
    }
}


int main()
{
    container<int> g;

    g.add(10);
    g.add(11);
    g.add(15);

    std::thread t1(func, std::ref(g), 3);
    std::thread t2(func, std::ref(g), 8);
    std::thread t3(func, std::ref(g), 2);

    t1.join();
    t2.join();
    t3.join();

    g.dump();
    
    return 0;
}



