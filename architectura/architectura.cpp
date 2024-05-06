#include <iostream>
#include <string>
#include <vector>
#include <filesystem>

namespace fs = std::filesystem;

void countFiles(const std::string& directory, const std::vector<std::string>& filePatterns) {
    int totalFileCount = 0;
    for (const auto& filePattern : filePatterns) {
        int fileCount = 0;
        for (const auto& entry : fs::recursive_directory_iterator(directory)) {
            if (fs::is_regular_file(entry) && entry.path().extension() == filePattern) {
                if (entry.path().filename().string().front() == '.') continue;
                fileCount++;
            }
        }
        std::cout << "Total files with pattern '" << filePattern << "' and appropriate attributes: " << fileCount << std::endl;
        totalFileCount += fileCount;
    }
    std::cout << "Total files in all patterns: " << totalFileCount << std::endl;
}

int main() {
    std::string directory;
    std::vector<std::string> filePatterns;

    // Запитати користувача про шлях до каталогу
    std::cout << "Enter the directory path: ";
    std::getline(std::cin, directory);

    // Запитати користувача про шаблони файлів, поки він не введе "done"
    std::string filePattern;
    std::cout << "Enter file patterns (type 'done' when finished): ";
    while (std::cin >> filePattern && filePattern != "done") {
        filePatterns.push_back(filePattern);
    }

    // Викликати функцію для підрахунку файлів
    countFiles(directory, filePatterns);

    return 0;
}


