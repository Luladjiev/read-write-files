#include "../include/reader.h"

#include <iostream>

namespace RW
{
    Reader::Reader(const char *file)
    {
        OpenFile(file, std::ios::in | std::ios::binary);
    }
    
    Reader::Reader(const char *file, std::ios::openmode mode = std::ios::in | std::ios::binary)
    {
        OpenFile(file, mode);
    }
    
    Reader::~Reader()
    {
        mFile.close();
    }
    
    void Reader::OpenFile(const char *file, std::ios::openmode mode) 
    {
        mFile.open(file, mode);
        
        if (!mFile.is_open())
            throw 1;
    }
    
    char Reader::ReadChar()
    {
        char result;
        mFile.read(&result, sizeof(char));
        return result;
    }
    
    int Reader::ReadInt16()
    {
        int result;
        mFile.read((char*)&result, sizeof(int));
        return result;
    }
    
    long int Reader::ReadInt32()
    {
        long int result;
        mFile.read((char*)&result, sizeof(long int));
        return result;
    }
    
    long long int Reader::ReadInt64()
    {
        long long int result;
        mFile.read((char*)&result, sizeof(long long int));
        return result;
    }
    
    double Reader::ReadDouble()
    {
        double result;
        mFile.read((char*)&result, sizeof(double));
        return result;
    }
    
    float Reader::ReadFloat()
    {
        float result;
        mFile.read((char*)&result, sizeof(float));
        return result;
    }
    
    std::string Reader::ReadString()
    {
        int length = ReadInt16();
        if (length <= 0)
            throw 2;
        char *buffer = new char[length + 1]();
        mFile.read(buffer, length);
        std::string result = buffer;
        delete[] buffer;
        return result;
    }
}