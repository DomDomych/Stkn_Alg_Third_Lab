#pragma once

#include <vector>
#include <string>
#include <deque>

class Task
{
    public:
    int id;
    std::string dscr;
    int prior;
    bool status = false;

    bool operator==(const Task& other) const;
    
    Task()=default;
    Task(int id,std::string dscr,int prior,bool status):id(id),dscr(dscr),prior(prior),status(status){};
    Task(const Task &other):id(other.id),dscr(other.dscr),prior(other.prior),status(other.status){};
    ~Task()=default;

};

class Queue_Task
{
    private:
    int completed=0;
    std::deque <Task> Queue;
    public:
    void enqueue(Task task);
    void dequeue();
    Task* front();
    bool isEmpty();
    int size();
    void clear();
    void print();
    Task* find(int id);
    void erase(int id);
    int comp_count();
    bool check(int id);
    void print_line();

    Queue_Task() = default;
    ~Queue_Task() = default;


};
