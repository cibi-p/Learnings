#include <iostream>
#include <thread>
#include <deque>
#include <mutex>
#include <chrono>
#include <condition_variable>
#include <random> // For thread-safe random number generation

using std::deque;
std::mutex mu, cout_mu;
std::condition_variable cond;

// Global random number generator initialization for thread safety
std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
std::uniform_int_distribution<int> dist100(0, 99); // For produced number (0-99)

class Buffer
{
public:
    void add(int num)
    {
        // The 'while(true)' loop here is redundant with cond.wait
        // but keeping it as it was in the original structure (though typically unnecessary).
        while (true)
        {
            std::unique_lock<std::mutex> locker(mu);

            // Wait while the buffer is full
            cond.wait(locker, [this]() { return buffer_.size() < size_; });

            // FIX: Add to the back (Standard queue behavior)
            buffer_.push_back(num);

            locker.unlock();
            // Notify consumers that an item is available
            cond.notify_all();
            return;
        }
    }
    int remove()
    {
        while (true)
        {
            std::unique_lock<std::mutex> locker(mu);

            // Wait while the buffer is empty
            cond.wait(locker, [this]() { return buffer_.size() > 0; });

            // FIX: Retrieve from the front (Standard queue behavior)
            int front = buffer_.front();
            // FIX: Remove from the front (Standard queue behavior)
            buffer_.pop_front();

            locker.unlock();
            // Notify producers that space is available
            cond.notify_all();
            return front;
        }
    }
    Buffer() {}

private:
    deque<int> buffer_;
    const unsigned int size_ = 10;
};

class Producer
{
public:
    Producer(Buffer *buffer, std::string name)
    {
        this->buffer_ = buffer;
        this->name_ = name;
    }
    void run()
    {
        while (true)
        {
            // FIX: Use thread-safe random number generation
            int num = dist100(rng);

            buffer_->add(num);

            // FIX: Use thread-safe random number generation for sleep
            int sleep_time = dist100(rng);

            cout_mu.lock();
            std::cout << "Name: " << name_ << "   Produced: " << num << "   Sleep time: " << sleep_time << std::endl;
            cout_mu.unlock(); // Unlock cout_mu BEFORE sleep, as recommended

            std::this_thread::sleep_for(std::chrono::milliseconds(sleep_time));
        }
    }

private:
    Buffer *buffer_;
    std::string name_;
};

class Consumer
{
public:
    Consumer(Buffer *buffer, std::string name)
    {
        this->buffer_ = buffer;
        this->name_ = name;
    }
    void run()
    {
        while (true)
        {
            int num = buffer_->remove();

            // FIX: Use thread-safe random number generation for sleep
            int sleep_time = dist100(rng);

            cout_mu.lock();
            std::cout << "Name: " << name_ << "   Consumed: " << num << "   Sleep time: " << sleep_time << std::endl;
            cout_mu.unlock(); // Unlock cout_mu BEFORE sleep, as recommended

            std::this_thread::sleep_for(std::chrono::milliseconds(sleep_time));
        }
    }

private:
    Buffer *buffer_;
    std::string name_;
};

int main()
{
    Buffer b;
    Producer p1(&b, "producer1");
    Producer p2(&b, "producer2");
    Producer p3(&b, "producer3");
    Consumer c1(&b, "consumer1");
    Consumer c2(&b, "consumer2");
    Consumer c3(&b, "consumer3");

    std::thread producer_thread1(&Producer::run, &p1);
    std::thread producer_thread2(&Producer::run, &p2);
    std::thread producer_thread3(&Producer::run, &p3);

    std::thread consumer_thread1(&Consumer::run, &c1);
    std::thread consumer_thread2(&Consumer::run, &c2);
    std::thread consumer_thread3(&Consumer::run, &c3);

    producer_thread1.join();
    producer_thread2.join();
    producer_thread3.join();
    consumer_thread1.join();
    consumer_thread2.join();
    consumer_thread3.join();

    getchar();
    return 0;
}
