#ifndef _PARSER_H
#define _PARSER_H

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <queue>
#include <string>

using std::istream;
using std::ifstream;
using std::string;
using std::queue;
using std::atoi;

class Parser {
public:
    //Constructors / Destructor
    Parser() = default;
    ~Parser() = default;

    //Functions
    void parse(string input_file_name);

    //Getters / Setters
    int get_bin_pack_size(void);
    queue<int> get_objects_list(void);

private:
    int bin_pack_size = 0;
    queue<int> objects_list;

};

#endif //_PARSER_H