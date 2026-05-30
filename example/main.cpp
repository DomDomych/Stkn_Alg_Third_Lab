#include "queue.hpp"
#include <string>
#include <iostream>

int main()
{

    std::cout<<"Пример Работы Очереди Задач\n";

    // Создадим 2 задачи, каждая невыполненная 
    Task lab(1,"Сделать Лабу",10,false),Cpp(2,"Сделать Плюсы",8,false);
    //Создадим Очередь Задач
    Queue_Task Tasks;
    // Добавляем Задачи в Очередь
    Tasks.enqueue(lab);
    Tasks.enqueue(Cpp);
    //Проверим, что Очередь теперь содержит эти задачи
    Tasks.print();
    //Добавим еще одну задачу
    Task sleep(3,"Поспать",3,false);
    Tasks.enqueue(sleep);
    //Проверяем, что добавление в непустую очередь работает корректно
    Tasks.print();
    //Проверим, что задача с таким id, т.е. задача Сделать Плюсы находится в очереди
    if(Tasks.find(2))
    {
        std::cout<<"Задача с id 2 и правда присутствует в очереди!\n";
    }
    //Убедимся, что там нет задачи со случайным id 4
    if(!Tasks.find(4)){
        std::cout<<"А вот с id 4 уже нет\n";
    }
    // Удалим задачу с id 1
    Tasks.erase(1);
    Tasks.print();

    //Проверка вывода очереди в строку
    Task bot(5,"Ботать",20,false);  
    Tasks.enqueue(bot);
    Tasks.print_line();

    //Проверим Размер
    std::cout<<"Размер Очереди - "<<Tasks.size()<<'\n';

    //Очистим Всю Очередь
    Tasks.clear();
    //Убедимся, что она пустая
    Tasks.print();
    if(Tasks.isEmpty())
    {
        
        std::cout<<"Да, она пустая\n";
        std::cout<<"----------------------\n";
    }

    //Мы не добавляли завершенные задачи, так что их должно быть 0
    std::cout<<"Количество Завершенных Заданий: "<<Tasks.comp_count()<<'\n';

    //Добавить завершенную задачу
    Task coffee(5,"Бахнуть Кофейка",25,true);
    Tasks.enqueue(coffee);
    std::cout<<"Количество Завершенных Заданий: "<<Tasks.comp_count()<<'\n';

    //Удалим Первую На Выполнение Задачу
    Tasks.print();
    Tasks.dequeue();
    Tasks.print();

    //Проверим, что нельзя добавить задачи с одинаковым id
    Task algem(23,"Поботать Алгем",15,false);
    Task mathan(23,"Поботать Матан",15,false);

    Tasks.enqueue(algem);
    Tasks.enqueue(mathan);
    Tasks.print();


    //И наконец, воспользуемся front()
    Tasks.enqueue(coffee);
    Tasks.enqueue(lab);
    if(*Tasks.front()==algem    )
    {
        std::cout<<"Первой задачей является поботать алгем!\n";
    }
    return 0;
}