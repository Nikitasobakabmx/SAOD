#pragma once
#include <ostream>
#include <istream>
class doctor
{
public:
    char *FIO = nullptr;
    char* job = nullptr;
    int room = 0;
    char* schedule = nullptr;//raspisanie
    friend std::ostream operator << (std::ostream &os, const doctor &item);
    friend std::istrean operator >> (std::istrean &is, const doctor &item);
};
std::ostream operator << (std::ostream &os, const doctor &item)
{
    if(FIO == nullptr || job == nullptr || schedule == nullptr || room == 0)
        throw except((char*)"doctor is NULL");
    os << "FIO = " << FIO << std::endl;
    os << "job = " << job << std::endl;
    os << "room = " << room << std::endl;
    os << "schedule = " << schedule << std::endl;
    return os;
}

std::istrean operator >> (std::istrean &is, const doctor &item)
{
    std::cout << "FIO = "<< std::endl; os >> FIO;
    std::cout << "job = " << std::endl; os >> job;
    std::cout << "room = " << std::endl;os >> room;
    std::cout << "schedule = " << std::endl; os >> schedule;
    if(FIO == nullptr || job == nullptr || schedule == nullptr || room == 0)
        throw except((char*)"doctor is NULL");
    return os;
}