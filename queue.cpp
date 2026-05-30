#include "queue.hpp"
#include <iostream>

void Task::done(){
    status = true;
    return;
}



void Queue_Task::dequeue()
{
    if(Queue.empty())return;
    Queue.pop_front();
}

Task* Queue_Task::front()
{
    if(Queue.empty())return nullptr;
    return &Queue.front();
}

bool Queue_Task::isEmpty()
{
    return Queue.empty();
}

int Queue_Task::size()
{
    return Queue.size();
}

void Queue_Task::clear()
{
    Queue.clear();
    return;
}

void Queue_Task::print()
{
    for(int i=0;i<Queue.size();i++){
        std::cout<<Queue[i].id<<' '
                 <<Queue[i].dscr<<' '
                 <<Queue[i].prior<<' '
                 <<((Queue[i].status)?"Done":"Not Done")<<'\n';
    }
    return;
}

Task* Queue_Task::find(int id)
{
    for(int i=0;i<Queue.size();i++)
    {
        if(Queue[i].id==id)
        {
            return &Queue[i];
        }
    }
    return nullptr;
}

void Queue_Task::erase(int id)
{
    for(int i=0;i<Queue.size();i++)
    {
        if(Queue[i].id==id)
        {
            Queue.erase(Queue.begin()+i);
            return;
        }
    }
    return;
}

int Queue_Task::comp_count()
{
    return completed;
}

bool Queue_Task::check(int id)
{
    for(int i=0;i<Queue.size();i++){
        if(Queue[i].id==id){
            return true;
        }
    }
    return false;
}

void Queue_Task::enqueue(Task task)
{
    if(check(task.id))return;
    if(task.status)completed++;
    Queue.push_back(task);
}