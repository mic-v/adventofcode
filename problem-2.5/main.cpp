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
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <cmath>

void print_vec(const std::vector<int>& vec) {
        for(int i : vec) {
                printf("%d ", i);
        }
        printf("\n");
}

std::vector<int> split_into_vec(std::string level)
{
        std::stringstream ss(level);
        std::vector<int> nums;
        std::string num;
        while(getline(ss , num, ' ')) {
                int value = std::stoi(num);
                nums.push_back(value);
        }

        return nums;
}

bool adj_nums_in_range(const std::vector<int>& vec, int low, int high) 
{
        for(int i = 0; i < vec.size() - 1; i++) 
                if( !((vec[i] - vec[i + 1]) >= low && (vec[i] - vec[i+1]) <= high)) return false;
        return true;
}

bool level_safe(const std::vector<int>& vec)
{
        if(adj_nums_in_range(vec, -3, -1) || adj_nums_in_range(vec, 1, 3))
                return true;
        return false;
}

int main()
{
        //expect a input.txt file in the main directory
        std::ifstream in_file;
        in_file.open("input.txt");
        int safe_count = 0;
        std::string s;
        while(getline(in_file, s)) {
                std::vector<int> nums = split_into_vec(s);   
                if(level_safe(nums)) 
                        safe_count++;
                else {
                        for(int i = 0; i < nums.size(); i++) 
                        {
                                std::vector<int> temp_nums = nums;
                                temp_nums.erase(temp_nums.begin() + i);
                                if(level_safe(temp_nums))
                                {
                                        safe_count++;
                                        break;
                                }
                        }
                }
        }
        printf("%d\n", safe_count);
        // 287 should be the correct answer
        // 354 should be the correct answer for part 2
        return 0;

}
