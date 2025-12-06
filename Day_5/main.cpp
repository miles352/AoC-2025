#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <unordered_set>

void pt1()
{
    std::ifstream file{"input.txt"};
    long n1, n2;
    char dash;

    std::string temp;
    std::vector<std::pair<long, long>> fresh_ranges;
    while (std::getline(file, temp) && !temp.empty())
    {
        std::istringstream line{std::move(temp)};

        line >> n1 >> dash >> n2;
        fresh_ranges.emplace_back(n1, n2);
    }

    long total{};
    while (file >> n1 && !file.eof())
    {
        for (auto p : fresh_ranges)
        {
            if (n1 >= p.first && n1 <= p.second)
            {
                total++;
                break;
            }
        }
    }
    file.close();
    std::cout << "Part 1 Total: " << total << std::endl;
}

void pt2()
{
    std::ifstream file{"input.txt"};
    long n1, n2;
    char dash;

    std::string temp;
    std::vector<std::pair<long, long>> fresh_ranges;
    while (std::getline(file, temp) && !temp.empty())
    {
        std::istringstream line{std::move(temp)};

        line >> n1 >> dash >> n2;

        fresh_ranges.emplace_back(std::tuple{n1, n2});
    }
    file.close();

    std::ranges::sort(fresh_ranges.begin(), fresh_ranges.end(), [](const std::pair<long, long>& r1, const std::pair<long, long>& r2)
    {
        return r1.first < r2.first;
    });

    auto it = fresh_ranges.begin();
    while (it != fresh_ranges.end())
    {
        auto it2 = it + 1;
        while (it2 != fresh_ranges.end() && it2->first <= it->second)
        {
            if (it2->second <= it->second)
            {
                it2 = fresh_ranges.erase(it2);
            }
            else
            {
                if (it->second + 1 <= it2->second) it2->first = it->second + 1;
                it2++;
            }
        }
        it++;
    }

    long total{};
    for (auto p : fresh_ranges)
    {
        total += p.second - p.first + 1;
    }

    std::cout << "Part 2 Total: " << total << std::endl;
}

int main()
{
    pt1();
    pt2();
}
