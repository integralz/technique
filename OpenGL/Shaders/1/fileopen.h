#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

namespace file{
    std::string read(const char* path){
        std::string code;
        std::ifstream File;
        File.exceptions (std::ifstream::failbit | std::ifstream::badbit);
        std::stringstream Filestream;
        try{
            File.open(path);
            Filestream << File.rdbuf();
            File.close();
            code = Filestream.str();
            return code;
        }
        catch (std::ifstream::failure& e)
        {
            std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
            return "a";
        }
    }
}
