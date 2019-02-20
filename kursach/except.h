#pragma once
#include <exception>
class except : std::exception
{
    private:
    const char* string;
    public:
        except(char* str)
        {
            string = str;
        }
        const char* what() const noexcept
        {
            return string;
        }
};
