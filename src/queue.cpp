#include "queue.hpp"
#include <iostream>


void Queue_Task::dequeue()
{
    if(Queue.empty())return;
    if(Queue.front().status)completed--;
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
    completed=0;
    Queue.clear();
    return;
}

void Queue_Task::print()
{
    std::cout<<"================\n";
    for(int i=0;i<Queue.size();i++){
        std::cout<<Queue[i].id<<' '
                 <<Queue[i].dscr<<' '
                 <<Queue[i].prior<<' '
                 <<((Queue[i].status)?"Done":"Not Done")<<'\n';
    }
    if(Queue.empty())std::cout<<"Очередь Пустая\n";
    std::cout<<"================\n";
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
            if(Queue[i].status)completed--;
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
    if(check(task.id)){
        return;
    }

    if(task.status){
        completed++;
    }

    Queue.push_back(task);
}

void Queue_Task::print_line()
{
    std::cout<<"*************************\n";
    for(int i=0;i<Queue.size();i++)
    {
        std::cout<<i+1<<". "<<Queue[i].dscr<<' ';
    }
    std::cout<<"\n*************************";
    std::cout<<'\n';
    return;
}