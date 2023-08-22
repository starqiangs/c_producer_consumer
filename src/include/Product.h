#include <queue>
#include <iostream>
#include <mutex>
#include <thread>
#include <condition_variable>


class Product
{
public:
    void Put(int val);
    void Pop();
private:
    std::queue<int> que;
    std::mutex mtx;
    std::condition_variable cv;
};