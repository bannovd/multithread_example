#include <iostream>
#include <mutex>
#include <thread>
#include <vector>
#include <atomic>
#include <logger.h>


static std::atomic_int counter;
static const int MAX_COUNTER = 100;
bridge::logger *console;


void add_counter(int thread_num, std::mutex& mtx)
{
    std::string message;
    while (true)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));

        if (counter == MAX_COUNTER)
            break;
        int ctrl_val = ++counter;

        message = "thread: " + std::to_string(thread_num) + ", counter: " + std::to_string(counter);
        std::lock_guard<std::mutex> lock(mtx);
        console->log(message);
    }
}

int main()
{
    console = new bridge::console_logger();

    std::mutex mtx;
    std::cout << "Multithread..." << std::endl;
    std::vector<std::thread> threads(10);
    for(int i = 1; i <= 10; ++i)
    {
        std::thread thr(add_counter, i, std::ref(mtx));
        threads.emplace_back(std::move(thr));
    }

    for(auto &thr : threads)
    {
        if (thr.joinable())
            thr.join();
    }

    std::cout << "done" << std::endl;

    delete console;
    return 0;
}
