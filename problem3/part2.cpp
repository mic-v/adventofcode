#include <fstream>
#include <regex>
#include <string>
#include <iostream>

std::string remove_disabled_mul(std::string line)
{
        std::regex exp("((don't\\(\\).*?)do\\(\\))");
        std::cout << line << std::endl;
        line = std::regex_replace(line, exp, "");
        std::cout << line << std::endl;
        return line;
}

int calculate_line(std::string line, std::regex exp)
{
        int total = 0;

        std::smatch res;
        bool enabled = true;
        while(regex_search(line, res, exp))
        {
                // multiply captured group 1 and 2
                total+= std::stoi(res[1]) * std::stoi(res[2]); 
                // go to the next captured match
                line = res.suffix().str();
        }
        return total;
}

int main() 
{
        //captures the two numbers in mul(***,***) and drops everything else
        std::regex exp("(?:mul\\()(\\d{1,3})(?:,)(\\d{1,3})(?:\\))");
        int total = 0;

        std::ifstream fs;
        fs.open("input.txt");

        std::string line;
        while(getline(fs, line)) 
        {
                line = remove_disabled_mul(line);
                total += calculate_line(line, exp);
        }
        printf("%d\n", total);
        return 0;
}
