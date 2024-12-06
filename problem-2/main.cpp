/*
 Pseudocode
        get input file
        keep track of safe reports      
        while looping through file until the end of file
                bool increasing
                previous number = 0
                while looping through line
                        if increasing
                                check curr number from previous number
                                if lesser, 
                                        safe--;
                                else if < 0 or greater)
                                        safe--;
                                        break
                        else     
                                check curr number from previous number 
                
                        
   
 */
#include <iostream>
#include <fstream>
#include <string>

int main()
{
        std::ifstream in_file;
        in_file.open("input.txt");
        int i = 0;
        std::string s;
        while(getline(in_file, s))
                std::cout << s << "\n";
        return 0;
}
