#include <vector>
#include <string>

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
    std::vector<int>
};
