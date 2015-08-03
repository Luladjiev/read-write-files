#ifndef __READER_H__
#define __READER_H__

#include <fstream>

namespace RW
{
    class Reader
    {
    private:
        std::ifstream mFile;
        void OpenFile(const char *file, std::ios::openmode mode);
    public:
        Reader(const char *file);
        Reader(const char *file, std::ios::openmode mode);
        ~Reader();
        char ReadChar();
        int ReadInt16();
        long int ReadInt32();
        long long int ReadInt64();
        double ReadDouble();
        float ReadFloat();
        std::string ReadString();
    };
}

#endif