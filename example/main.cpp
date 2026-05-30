#include "queue.hpp"
#include <string>
#include <iostream>

int main()
{
    Task lab(1,"Сделать Лабу",10,false),Cpp(2,"Сделать Плюсы",8,false);
    Queue_Task Tasks;
    Tasks.enqueue(lab);
    Tasks.enqueue(Cpp);
    Tasks.print();
    Task sleep(3,"Поспать",3,false);
    Tasks.enqueue(sleep);
    Tasks.print();
    if(Tasks.find(2))
    {
        std::cout<<"Задача с id 2 и правда присутствует в очереди!\n";
    }
    if(!Tasks.find(4)){
        std::cout<<"А вот с id 4 уже нет\n";
    }

    Tasks.erase(1);

    Tasks.print();

    Task bot(5,"Ботать",20,false);  

    Tasks.enqueue(bot);

    Tasks.print();

    Tasks.print_line();

    std::cout<<"Размер Очереди - "<<Tasks.size()<<'\n';

    Tasks.clear();

    Tasks.print();

    std::cout<<"Количество Завершенных Заданий: "<<Tasks.comp_count()<<'\n';

    Task coffee(5,"Бахнуть Кофейка",25,true);

    Tasks.enqueue(coffee);

    std::cout<<"Количество Завершенных Заданий: "<<Tasks.comp_count()<<'\n';

    Tasks.dequeue();

    Tasks.print();
}