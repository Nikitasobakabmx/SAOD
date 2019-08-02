#include <string>
#include <ostream>
#include "except.h"

class sick
{
    private:
        std::string *regNumber = nullptr;
        std::string *FIO = nullptr;
        int *year;
        std::string *ardres = nullptr;
        std::string *job = nullptr;
        sick(){};
    public:
        //sick(std::string& regNum, std::string& fio, int yr, std::string& adr, std::string& job)
        sick(const char* regNum, const char* fio, int yr, const char* adr, const char* job)
        {
            this->regNumber = new std::string(regNum);
            this->FIO = new std::string(fio);
            this->year = new int(yr);
            this->ardres = new std::string(adr);
            this->job = new std::string(job);
        }
        sick(const sick& item)
        {
            this->regNumber = new std::string(*item.regNumber);
            this->FIO = new std::string(*item.FIO);
            this->year = new int(*item.year);
            this->ardres = new std::string(*item.ardres);
            this->job = new std::string(*item.job);
        }
        inline friend std::ostream& operator<<(std::ostream &os, const sick &item)
        {
            os << "reg number : " << *item.regNumber << std::endl;
            os << "FIO : " << *item.FIO << std::endl;
            os << "Full year : " << *item.year << std::endl;
            os << "adress : " << *item.ardres << std::endl;
            os << "Job : " << *item.job << std::endl;
            return os;
        }

        int key()
        {
            if (regNumber == nullptr)
                throw except((char*)"key is not defiend!");
            int key = 0;
            for(std::string::iterator it = regNumber->begin(); it != regNumber->end(); ++it)
            {
                if(*it == '-')
                    continue;
                key += *it - 48;
                key *= 10;
            }
            key /= 10;
            return key;
        }
        static int to_key(std::string item)
        {
            int key = 0;
            for(std::string::iterator it = item.begin(); it != item.end(); ++it)
            {
                if(*it == '-')
                    continue;
                key += *it - 48;
                key *= 10;
            }
            key /= 10;
            return key;
        }
};