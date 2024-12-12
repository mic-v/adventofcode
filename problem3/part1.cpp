#include <fstream>
#include <regex>
#include <string>

int calculate_line(std::string line, std::regex exp)
{
        int total = 0;

        std::smatch res;
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
                total += calculate_line(line, exp);
        }
        printf("%d\n", total);
        return 0;
}
