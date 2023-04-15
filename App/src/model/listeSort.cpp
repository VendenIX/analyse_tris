#include "../../include/model/listeSort.hpp"

void writeFileNames(std::string path) {
    std::ofstream file;
    file.open(FOLDER "listeSort.txt");
    for (const auto & entry : std::filesystem::directory_iterator(path)) {
        if (entry.path().extension() == ".hpp" 
            && entry.path().filename() != "Sorting.hpp"
            && entry.path().filename() != "listeSort.hpp"
            && entry.path().filename() != "MainPage.hpp"
        ) {
            std::string name = entry.path().filename();
            name = name.substr(0, name.size() - 4);
            file << name << std::endl;
        }
    }
    file.close();
}

std::vector<std::string> readSortNames(void) {
    std::vector<std::string> names;
    std::ifstream file;
    file.open(FOLDER "listeSort.txt");
    std::string name;
    while (std::getline(file, name)) {
        names.push_back(name);
    }
    file.close();
    return names;
}