#include "Product.h"

void Product::Put(int val)
{
    // std::lock_guard<std::mutex> lock_guard(this->mtx);
    std::unique_lock<std::mutex> lck(mtx);
    while (!this->que.empty())
    {
        // unlock and send message to consumer
        // producer will block and util consumer consume, producer will product
        cv.wait(lck);

    }
    que.push(val);
    // send other thread
    cv.notify_all();
    std::cout << "producer product:" << val << " store" << std::endl;
}

void Product::Pop()
{
    // std::lock_guard<std::mutex> lock_guard(this->mtx);
    std::unique_lock<std::mutex> lck(mtx);
    while (que.empty())
    {
        cv.wait(lck);
    }

    auto val = que.front();
    this->que.pop();
    cv.notify_all();
    std::cout << "consumer consume:" << val << " store" << std::endl;
}