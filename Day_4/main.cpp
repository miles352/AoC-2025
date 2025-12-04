#include <iostream>
#include <fstream>
#include <vector>

void pt1()
{
   std::ifstream file{"input.txt"};
   std::vector<std::string> grid;
   std::string temp;
   while (std::getline(file, temp) && !file.eof())
   {
      grid.push_back(std::move(temp));
   }

   int total{};
   for (int i = 0; i < grid.size(); i++)
   {
      for (int j = 0; j < grid[0].size(); j++)
      {
         if (grid[i][j] != '@') continue;
         int adjacent_count{};
         for (int k = -1; k <= 1; k++)
         {
            for (int l = -1; l <= 1; l++)
            {
               if (k == 0 && l == 0) continue;
               if (i + k >= grid.size() || j + l > grid[0].size()
                   || i + k < 0 || j + l < 0) continue;
               if (grid[i+k][j+l] == '@') adjacent_count++;
            }
         }
         if (adjacent_count < 4) total++;
      }
   }
   file.close();
   std::cout << "Part 1 Total: " << total << std::endl;
}

void pt2()
{
   std::ifstream file{"input.txt"};
   std::vector<std::string> grid;
   std::string temp;
   while (std::getline(file, temp) && !file.eof())
   {
      grid.push_back(std::move(temp));
   }

   int total{};
   int last_total = -1;
   while (last_total != total)
   {
      last_total = total;
      for (int i = 0; i < grid.size(); i++)
      {
         for (int j = 0; j < grid[0].size(); j++)
         {
            if (grid[i][j] != '@') continue;
            int adjacent_count{};
            for (int k = -1; k <= 1; k++)
            {
               for (int l = -1; l <= 1; l++)
               {
                  if (k == 0 && l == 0) continue;
                  if (i + k >= grid.size() || j + l > grid[0].size()
                      || i + k < 0 || j + l < 0) continue;
                  if (grid[i+k][j+l] == '@') adjacent_count++;
               }
            }

            if (adjacent_count < 4)
            {
               grid[i][j] = '.';
               total++;
            }
         }
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