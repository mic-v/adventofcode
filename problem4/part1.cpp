#include <iostream>
#include <fstream>
#include <vector>

template <typename T>
void print_2d_vec(const std::vector<std::vector<T>>& vec)
{
        for(const auto& row: vec)
        {
                for(const auto& elem: row)
                {
                        std::cout << elem;
                }
                std::cout << "\n";
        }
}

u_int8_t check_word(const std::vector<std::vector<char>>& vec, int x, int y)
{
        u_int8_t count = 0;
        auto width = vec[0].size();
        auto height = vec.size();

        
        //check up and down
        if(x+3 < height && vec[x][y] == 'X' && vec[x+1][y] == 'M' && vec[x+2][y] == 'A' && vec[x+3][y] == 'S') 
                count++; 
        if(x-3 >= 0 && vec[x][y] == 'X' && vec[x-1][y] == 'M' && vec[x-2][y] == 'A' && vec[x-3][y] == 'S') 
                count++;
        //check across
        if(y+3 < width && vec[x][y] == 'X' && vec[x][y+1] == 'M' && vec[x][y+2] == 'A' && vec[x][y+3] == 'S') 
                ++count;
        if((y-3 >= 0) && (vec[x][y] == 'X') && (vec[x][y-1] == 'M') && (vec[x][y-2]) == 'A' && (vec[x][y-3] == 'S')) 
                ++count;
        //left diagonal
        if(x-3 >= 0 && y-3 >=0 && vec[x][y] == 'X' && vec[x-1][y-1] == 'M' && vec[x-2][y-2] == 'A' && vec[x-3][y-3] == 'S') 
                ++count;
        
        //bottom left diagonal
        if(x+3 < height && y-3 >= 0 && vec[x][y] == 'X' && vec[x+1][y-1] == 'M' && vec[x+2][y-2] == 'A' && vec[x+3][y-3] == 'S') 
                ++count;

        //right diagonal
        if(x-3 >= 0 && y+3 < width && vec[x][y] == 'X' && vec[x-1][y+1] == 'M' && vec[x-2][y+2] == 'A' && vec[x-3][y+3] == 'S') 
                ++count;

        //bottom right diagonal
        if(x+3 < height && y+3 < width && vec[x][y] == 'X' && vec[x+1][y+1] == 'M' && vec[x+2][y+2] == 'A' && vec[x+3][y+3] == 'S') 
                ++count;


        return count;
}

uint16_t word_search(const std::vector<std::vector<char>>& vec)
{
        u_int16_t count = 0;

        for(int i = 0; i < vec.size(); i++)
        {
                for(int j =0; j < vec[i].size();j++)
                {
                        if(vec[i][j] == 'X')
                                count+= check_word(vec, i, j);
                }
        }
        return count; 
}

int main()
{
        std::ifstream in_file("input.txt");


        std::vector<std::vector<char>> data;

        std::string line;
        while(std::getline(in_file, line))
        {
                std::vector<char> row;
                for(char &c: line)
                {
                        if(c != '\n')
                                row.push_back(c);
                }
                data.push_back(row);
        }

       
        in_file.close(); 
        print_2d_vec(data);
        u_int16_t count = word_search(data);


        printf("Count: %d\n", count);
}
