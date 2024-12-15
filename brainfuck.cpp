#include <fstream>
#include <iostream>
#include <map>

void generateCpp(std::ifstream& src, std::ofstream& dst) {
    char c;

    std::map<char, std::string> converter = {
        {'>', "ptr++;"},
        {'<', "ptr--;"},
        {'+', "++*ptr;"},
        {'-', "--*ptr;"},
        {'[', "while(*ptr) {"},
        {']', "}"},
        {'.', "putchar(*ptr);"},
        {',', "*ptr=getchar();"}
    };


    dst << "#include <iostream>\n"
        << "int main() {\n"
        << "char a[30000];\n"
        << "char *ptr = a;\n";

    while (src.get(c))
        if (converter.find(c) != converter.end())
            dst << converter[c] << '\n';
        else
            std::cerr << "Warning: Skipping unhandled character '" << c << "'. \n";

    dst << "return 0; \n"
        << "} \n";
}

int main(int argc, char *argv[]) {
    std::ifstream source;
    std::ofstream destination;

    if (argc < 3) {
        std::cerr << "Usage: " << argv[0] << " <source file> <destination file>\n";
        return 1;
    }

    source.open(argv[1]);
    destination.open(argv[2]);

    if (!source.is_open())
        std::cerr << "Unable to read " << argv[1];
    
    else if (!destination.is_open()) 
        std::cerr << "Unable to read " << argv[2]; 
    
    else 
        generateCpp(source, destination);

    return 0;
}