#include "../include/writer.h"
#include "../include/reader.h"

#include <iostream>

int main(int argc, const char *argv[])
{
    if (argc < 2) 
    {
        std::cout << "Usage: read-write-files <filename>" << std::endl;
        return 0;
    }
    
    RW::Writer *writer = new RW::Writer(argv[1]);
    
    writer->Write('a');
    writer->Write('b');
    writer->Write(5);
    writer->Write(2.2);
    writer->Write("Test message");
    
    delete writer;
    
    RW::Reader *reader = new RW::Reader(argv[1]);
    
    std::cout << reader->ReadChar() << std::endl;
    std::cout << reader->ReadChar() << std::endl;
    std::cout << reader->ReadInt16() << std::endl;
    std::cout << reader->ReadDouble() << std::endl;
    std::cout << reader->ReadString() << std::endl;
    
    delete reader;
    
    return 0;
}