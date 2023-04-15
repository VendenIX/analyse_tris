#pragma once

#include <iostream>
#include <fstream>
#include <filesystem>
#include <vector>

#define FOLDER "include/model/"

void writeFileNames(std::string path);
std::vector<std::string> readSortNames(void);