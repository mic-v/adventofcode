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
// we found the letter A, so the corners of it should contain some combo of
// M and S that form MAS in both diagonals in the shape of X.
// It can be top to bottom, bottom to top, left to right, or righ to left
u_int8_t check_xmas(const std::vector<std::vector<char>>& vec, int x, int y)
{
        u_int8_t count = 0;
        auto width = vec[0].size();
        auto height = vec.size();

        //look within boundaries 
        if(x - 1 >= 0 && y - 1 >= 0 && x + 1 < height && y + 1 < width)
        {
                if((vec[x-1][y-1] == 'M' && vec[x-1][y+1] == 'M' && vec[x+1][y-1] == 'S' && vec[x+1][y+1] == 'S') || //top down
                (vec[x+1][y-1] == 'M' && vec[x+1][y+1] == 'M' && vec[x-1][y-1] == 'S' && vec[x-1][y+1] == 'S') || //bottom up
                (vec[x+1][y-1] == 'M' && vec[x+1][y+1] == 'S' && vec[x-1][y-1] == 'M' && vec[x-1][y+1] == 'S') || //left to right
                (vec[x+1][y-1] == 'S' && vec[x+1][y+1] == 'M' && vec[x-1][y-1] == 'S' && vec[x-1][y+1] == 'M'))  // right to lef
                {
                        count++; printf("%c.%c\n", vec[x-1][y-1], vec[x-1][y+1]); printf(".%c.\n", vec[x][y]); printf("%c.%c\n", vec[x+1][y-1], vec[x+1][y+1]);

                }

        }

        return count;
}

//better function name would be letter search
//we search for the letter A this time as thats the most important letter
//to find the X shaped X-MAS and check if its a viable shape
uint16_t word_search(const std::vector<std::vector<char>>& vec)
{
        u_int16_t count = 0;

        for(int i = 0; i < vec.size(); i++)
                for(int j =0; j < vec[i].size();j++)
                        if(vec[i][j] == 'A')
                                count+= check_xmas(vec, i, j);
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
                        if(c != '\n')
                                row.push_back(c);
                data.push_back(row);
        }

       
        in_file.close(); 
        print_2d_vec(data);
        u_int16_t count = word_search(data);

        printf("Count: %d\n", count);
}
