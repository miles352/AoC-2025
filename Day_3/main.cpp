#include <fstream>
#include <iostream>

void pt1()
{
    std::ifstream file{"input.txt"};
    int total{};
    do
    {
        std::string bank;
        std::getline(file, bank);
        if (bank.empty()) continue;

        int max = -1;
        for (int i = 0; i < bank.size(); i++)
        {
            for (int j = i + 1; j < bank.size(); j++)
            {
                int num = (bank[i] - '0') * 10 + bank[j] - '0';
                if (num > max) max = num;
            }
        }
        total += max;
    } while (!file.eof());
    file.close();
    std::cout << "Part 1 Total: " << total << std::endl;
}

void pt2()
{
    std::ifstream file{"input.txt"};
    unsigned long long total{};
    do
    {
        std::string bank;
        std::getline(file, bank);
        if (bank.empty()) continue;

        std::string num;
        int max_index = 0;
        for (int i = 1; i <= 12; i++)
        {
            for (int j = max_index; j < bank.size() - (12 - i); j++)
            {
                if (bank[j] > bank[max_index]) max_index = j;
            }
            num += bank[max_index++];
        }
        total += std::stoll(num);
    } while (!file.eof());
    file.close();
    std::cout << "Part 2 Total: " << total << std::endl;
}

int main()
{
    pt1();
    pt2();
}
