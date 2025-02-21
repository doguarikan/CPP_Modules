#include <iostream>
#include <fstream>
#include <string>

void replaceLine(std::ifstream &readfl, std::ofstream &writefl, std::string str1, std::string str2)
{
    std::string line;
    while(getline(readfl, line))
    {
        size_t pos = 0;
        while((pos=line.find(str1, pos)) != std::string::npos)
        {
            line = line.substr(0, pos) + str2 + line.substr(pos + str1.length());
            pos += str2.length();
        }
        writefl << line;
        if (!readfl.eof())
            writefl << std::endl;
    }
}

int main(int argc, char **argv) {
    if(argc != 4)
    {
        std::cout << "Error: invalid number of arguments" << std::endl;
        return 1;
    }
    std::string readFileName = argv[1];
    std::string str1 = argv[2];
    std::string str2 = argv[3];

    std::ifstream readfl(readFileName.c_str());
    if(!readfl.is_open())
    {
        std::cout << "Error: Unable to open  file" << std::endl;
        return 1;
    }

    std::string writeFileName = readFileName + ".replace";
    std::ofstream writefl(writeFileName.c_str());
    if(!writefl.is_open())
    {
        std::cout << "Error: Unable to create  file" << std::endl;
        readfl.close();
        return 1;
    }
    replaceLine(readfl, writefl, str1, str2);
    readfl.close();
    writefl.close();
    return 0;
}
