#include "HeshTable.h"
#include "sick.h"
#include <iostream>


int main()
{
    sick b("76-665773", "Khmelev Nikita Anatolevich", 20, "jukova 24", "python developer");
    sick c("76-665774", "Alekseev Pavel Igorevich", 21, "lenena 12", "java developer");
    sick d("76-665775", "Turgeniev Vicheslav Victorovich", 44, "jukova 24", "c++ developer");
    sick e("76-665776", "Fedotov Vasiliy Viktorovich", 11, "jukova 24", "go developer");
    //std::cout << b;
    //std::cout << b.key() << std::endl;
    //only this method to append in hash
    HeshTable<int, sick> a(sick::to_key("76-665773"), b);  
   
    // std::cout << a << std::endl;
    
    a.add(sick::to_key("76-665773"), b);
    a.add(sick::to_key("76-665773"), b);
    a.add(sick::to_key("76-665773"), b);
    a.add(sick::to_key("76-665773"), b);
    a.add(sick::to_key("76-665774"), c);
    std::cout << a.size() << std::endl;
    a.rm(sick::to_key("76-665773"));
    std::cout << a.size() << std::endl;
    // a.add(22, e);
    // a.add(32, c);
    // // a.add(42, 5);
    // std::cout << "Second!" << std::endl;
    std::cout << a << std::endl;
    return 0;
}