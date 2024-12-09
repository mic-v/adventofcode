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


int main()
{
        std::ifstream in_file;
        in_file.open("input.txt");
        int safe_count = 0;
        std::string s;

        int count = 0;
        while(getline(in_file, s)) {
                count++;
                std::vector<int> nums = split_into_vec(s);
                if(nums[0] == nums[1]) continue; 
                bool increasing = nums[0] < nums[1] ? true : false;

                bool safe = false;
                for(int i = 1; i < nums.size(); i++) {
                        uint8_t differ = std::abs(nums[i - 1] - nums[i]);
                        if(increasing) {
                                if(nums[i - 1] < nums[i])
                                {
                                        if(differ > 0 && differ <=3) 
                                                safe = true;
                                        else {
                                                safe = false;
                                                break;
                                        }
                                                
                                } else { 
                                        safe = false;
                                        break; 
                                } 
                        }
                        else {
                                if(nums[i - 1] > nums[i])
                                {
                                        if(differ > 0 && differ <= 3)
                                                safe = true;
                                        else {
                                                safe = false;
                                                break;
                                        }
                                              
                                } else { 
                                        safe = false;
                                        break; 
                                }
                        }
                }
                if(safe) safe_count++;

        }
        printf("Safe levels are %d\n", safe_count);
        printf("Count %d\n", count);
        // 287 should be the correct answer
        return 0;

}
