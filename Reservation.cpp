#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <vector>
#include <string>
#include <stdexcept>



class Restaurant {
    static inline const std::string LAYOUT_FILE = "layout.txt";
public:
    std::map<std::string, std::vector<std::string>> readLayout() {
        std::map<std::string, std::vector<std::string>> layout;
        try {
            std::ifstream reader(LAYOUT_FILE);
            if (!reader) {
                throw std::runtime_error("File not found.");
            }
            std::string line;
            while (std::getline(reader, line)) {
                std::istringstream ss(line);
                std::string part;
                std::vector<std::string> parts;
                while (std::getline(ss, part, ',')) {
                    parts.push_back(part);
                }
                layout[parts[0]] = { parts[1], parts[2] };
            }
        }
        catch (const std::exception& e) {
            std::cerr << e.what() << std::endl;
        }
        return layout;
    }

public:
    void updateLayout(const std::map<std::string, std::vector<std::string>>& layout) {
        try {
            std::ofstream writer(LAYOUT_FILE);
            if (!writer) {
                throw std::runtime_error("File not found.");
            }
            for (const auto& entry : layout) {
                writer << entry.first << "," << entry.second[0] << "," << entry.second[1] << "\n";
            }
        }
        catch (const std::exception& e) {
            std::cerr << e.what() << std::endl;
        }
    }

};

int main() {
    Restaurant r;

    std::map<std::string, std::vector<std::string>> writeTest;
    writeTest["1"] = { "3", "null" };
    writeTest["2"] = { "2", "null" };
    writeTest["3"] = { "6", "null" };
    writeTest["4"] = { "2", "null" };
    writeTest["5"] = { "4", "null" };

    r.updateLayout(writeTest);

    std::map<std::string, std::vector<std::string>> readTest = r.readLayout();
    for (const auto& entry : readTest) {
        std::cout << "Key: " << entry.first << ", Value: [" << entry.second[0]
            << ", " << entry.second[1] << "]" << std::endl;
    }

    return 0;
};