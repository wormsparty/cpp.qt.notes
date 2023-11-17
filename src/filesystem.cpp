#include <filesystem>
#include <fstream>
#include <iostream>

int main() {
    const std::filesystem::path path{"/home/mob/mytest"};
	
    if (!std::filesystem::exists(path)) {
	    std::filesystem::create_directory(path);
    } else if (!std::filesystem::is_directory(path)) {
        throw "Failed to create folder: is a file.";
    }

    std::ofstream out{path/"file.txt"};
    out << "I'm testing";
    out.close();

    std::ifstream in{path/"file.txt"};
    std::stringstream strstream;
    strstream << in.rdbuf();
    std::string content = strstream.str();

    std::cout << "I read: " << content << std::endl;

    return 0;
}