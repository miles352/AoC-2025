#include <cmath>
#include <fstream>
#include <iostream>

void pt1()
{
    std::ifstream file{"input.txt"};

    long min, max;
    unsigned long long total{};
    while (file >> min >> max)
    {
        file.get();
        max = -max;
        for (long num = min; num <= max; num++)
        {
            int len = std::to_string(num).size();
            if (len % 2 != 0) continue;
            long right = num % static_cast<long>(std::pow(10, len / 2));
            if (right + right * std::pow(10, len/2) == num)
            {
                total += num;
            }

        }
    }
    file.close();
    std::cout << "Part 1 Total: " << total << std::endl;
}

void pt2()
{
    std::ifstream file{"input.txt"};

    long min, max;
    unsigned long long total{};
    while (file >> min >> max)
    {
        file.get();
        max = -max;
        for (long num = min; num <= max; num++)
        {
            int len = std::to_string(num).size();
            bool invalid = false;
            for (int subnum_width = 1; subnum_width <= len / 2; subnum_width++)
            {
                if (len % subnum_width != 0) continue;
                long subnumber = num % static_cast<long>(std::pow(10, subnum_width));
                int invalid_count{};
                for (int i = 0; i < len / subnum_width - 1; i++) // check if all subnums are the same
                {
                    // get subnum from [((i+1) * subnum_width), (i * subnum_width)] and check if equal to subnum
                    if (num % static_cast<long>(std::pow(10, subnum_width + (i+1) * subnum_width))
                        / static_cast<long>(std::pow(10, subnum_width + i * subnum_width)) == subnumber)
                    {
                        invalid_count++;
                    }
                }
                if (invalid_count == len / subnum_width - 1)
                {
                    invalid = true;
                    break;
                }
            }
            if (invalid) total += num;
        }
    }
    file.close();
    std::cout << "Part 2 Total: " << total << std::endl;
}


int main()
{
    pt1();
    pt2();
}
