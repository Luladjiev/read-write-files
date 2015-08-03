#include "../include/writer.h"

#include <iostream>

namespace RW
{
    Writer::Writer(const char *file)
    {
        OpenFile(file, std::ios::out | std::ios::trunc | std::ios::binary);    
    }
    
    Writer::Writer(const char *file, std::ios::openmode mode = std::ios::out | std::ios::trunc | std::ios::binary)
    {
        OpenFile(file, mode);
    }
    
    Writer::~Writer()
    {
        mFile.close();
    }
    
    void Writer::OpenFile(const char *file, std::ios::openmode mode)
    {
        mFile.open(file, mode);
        
        if (!mFile.is_open())
            throw 1;
    }
    
    void Writer::Write(char symbol)
    {
        mFile.write(&symbol, sizeof(char));
    }
    
    void Writer::Write(int number)
    {
        mFile.write((char*)&number, sizeof(int));
    }
    
    void Writer::Write(long int number)
    {
        mFile.write((char*)&number, sizeof(long int));
    }
    
    void Writer::Write(long long int number)
    {
        mFile.write((char*)&number, sizeof(long long int));    
    }
    
    void Writer::Write(double decimal)
    {
        mFile.write((char*)&decimal, sizeof(double));    
    }
    
    void Writer::Write(float decimal)
    {
        mFile.write((char*)&decimal, sizeof(float));
    }
    
    void Writer::Write(std::string text)
    {
        int size = (int)text.size();
        Write(size);
        mFile.write(text.c_str(), text.size());
    }
}