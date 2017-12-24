#include "parser.h"

void Parser::parse(string input_file_name)
{
    ifstream input_file;
    input_file.open(input_file_name);
    if (!input_file) {
        std::cout << "Couldn't open file \"" << input_file_name << "\"." << std::endl;
    } else {
        string line;
        getline(input_file, line);
        getline(input_file, line);
        int digits = line.size() + 1;
        bin_pack_size = atoi(line.c_str());
        getline(input_file, line);
        char* string = new char[digits];
        objects_list = queue<int>();
        while (input_file.getline(string, digits, ',')) {
            objects_list.push(atoi(string));
            input_file.get();
        }
        delete[] string;
    }
}

int Parser::get_bin_pack_size(void)
{
    return bin_pack_size;
}

queue<int> Parser::get_objects_list(void)
{
    return objects_list;
}