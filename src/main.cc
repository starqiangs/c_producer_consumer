#include <iostream>
#include <thread>
#include <list>
#include <queue>

#include "Product.h"

void Producer(Product &product)
{
    for (int i = 0; i <= 10; i++)
    {
        product.Put(i);
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

void Consumer(Product &product)
{
    for (int i = 0; i <= 10; i++)
    {
        product.Pop();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

int main()
{
    Product product;

    std::thread producer(Producer, std::ref(product));
    std::thread consumer(Consumer, std::ref(product));

    producer.join();
    consumer.join();

    return 0;
}