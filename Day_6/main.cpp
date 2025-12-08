#include <algorithm>
#include <cmath>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

void pt1()
{
    std::ifstream file{"input.txt"};
    std::string temp;
    std::vector<std::vector<long>> numbers;
    while (std::getline(file, temp) && !file.eof())
    {
        std::istringstream line{temp};
        std::vector<long> nums;
        long num;
        while (!line.eof() && line >> num && !line.fail())
        {
            nums.push_back(num);
        }

        if (!nums.empty()) numbers.push_back(std::move(nums));

        if (line.fail())
        {
            line = std::istringstream{std::move(temp)}; // had to reset line because if it started with a + it got eaten
            line.clear();
            char operation{};
            long total{};
            int col_num{};
            while (!line.eof() && line >> operation)
            {
                if (operation == ' ') continue;
                long subtotal = operation == '*' ? 1 : 0;
                for (int i = 0; i < numbers.size(); i++)
                {
                    switch (operation)
                    {
                    case '+':
                        {
                            subtotal += numbers[i][col_num];
                            break;
                        }
                    case '*':
                        {
                            subtotal *= numbers[i][col_num];
                            break;
                        }
                    }
                }
                total += subtotal;
                col_num++;
            }
            std::cout << "Part 1 Total: " << total << std::endl;
        }
    }
    file.close();
}

void pt2()
{
    std::ifstream file{"input.txt"};
    std::vector<std::string> lines;
    while (!file.eof())
    {
        std::string temp;
        std::getline(file, temp);
        if (!temp.empty()) lines.push_back(std::move(temp));
    }

    char operation;
    long subtotal{};
    long total{};
    int num_len{};
    int num{};
    for (int i = 0; i < lines[lines.size() - 1].size(); i++)
    {
        char operation_char = lines[lines.size()-1][i];
        if (operation_char != ' ')
        {
            operation = operation_char;
            total += subtotal;
            if (operation == '+')
            {
                subtotal = 0;
            }
            else
            {
                subtotal = 1;
            }
        }
        for (int j = lines.size()-2; j >= 0; j--)
        {
            if (lines[j][i] != ' ')
            {
                num += std::pow(10, num_len++) * (lines[j][i] - '0');
            }
        }
        if (num == 0) continue;
        if (operation == '+')
        {
            subtotal += num;
        }
        else
        {
            subtotal *= num;
        }
        num = 0;
        num_len = 0;
    }

    total += subtotal;

    std::cout << "Part 2 Total: " << total << std::endl;

    file.close();
}

int main()
{
    pt1();
    pt2();
}