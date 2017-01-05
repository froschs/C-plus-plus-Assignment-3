
#include "./reader.h"

namespace config_reader {

    std::string* read_config(std::string config_file_path) {
        int file_size = 0;
        std::string line;
        std::ifstream inputFile;

        // Method will return file at the path passed to it
        inputFile.open(config_file_path);

        // While loop will iterate for each line of text in the file and file_size will accumulate total of lines
        while (inputFile >> line) {
            file_size++;
        }

        inputFile.clear(); // Clears the end of file
        inputFile.seekg(0L, std::ios::beg); // Starts over at the beginning of the file

        // Had to use dynamic array to save information through scope of function with size dictated by file_size.
        std::string *config_lines = new std::string[file_size];

        // For loop to store each line from the file to an array in config_lines
        for (int i = 0; i < file_size; i++) {
            inputFile >> config_lines[i];
        }

        inputFile.close();

        return config_lines;
    }
}