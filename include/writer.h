#ifndef __WRITER_H_
#define __WRITER_H_

#include <fstream>
#include <string>

namespace RW 
{
    class Writer
    {
    private:
        std::ofstream mFile;
        void OpenFile(const char *file, std::ios::openmode mode);
    public:
        Writer(const char *file);
        Writer(const char *file, std::ios::openmode mode);
        ~Writer();
        void Write(char symbol);
        void Write(int number);
        void Write(long int number);
        void Write(long long int number);
        void Write(double decimal);
        void Write(float decimal);
        void Write(std::string text);
    };   
}

#endif