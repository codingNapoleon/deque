#include <iostream>
class CircularQueue
{
public:
    CircularQueue(int capacity)
    {
        arr = new int[capacity];
        front_idx = 0;
        back_idx = -1;
        size = 0;
        max_capacity = capacity;
    }

    ~CircularQueue()
    {
        delete[] arr;
    }

    // 入队列，若队列已满则不添加d
    void enqueue(int value)
    {
        if (front_idx == (back_idx + 1) % 8 && back_idx != -1)
        {
            return;
        }
        back_idx = (back_idx + 1) % max_capacity;
        arr[back_idx] = value;
    }

    // 出队列
    void dequeue()
    {
        front_idx = (front_idx + 1) % max_capacity;
    }

    // 返回队首元素
    int front()
    {
        return arr[front_idx];
    }

    // 返回队尾元素
    int rear()
    {
        return arr[back_idx];
    }

    // 检查是否为空
    bool isEmpty()
    {
        if (back_idx == -1)
        {
            return true;
        }
        if (front_idx > (back_idx + 1) % max_capacity)
        {
            return true;
        }
        return false;
    }

    // 检查是否已满
    bool isFull()
    {
        if (back_idx == -1)
        {
            return false;
        }
        if (front_idx == (back_idx + 1) % max_capacity)
        {
            return true;
        }
        return false;
    }

private:
    int *arr;
    int front_idx;
    int back_idx;
    int size;
    int max_capacity;
};

#include "tools.h"
