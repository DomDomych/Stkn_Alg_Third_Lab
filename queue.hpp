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

    Task()=default;
    ~Task()=default;

    void done();
};

class Queue_Task
{
    std::deque <Task> Queue;

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
    
};
