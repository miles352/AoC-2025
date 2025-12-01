#include <fstream>
#include <iostream>

void pt1()
{
    std::ifstream in{"input.txt"};
    int times_at_zero{};
    int rotation = 50;

    char direction;
    int distance;
    while (in >> direction >> distance)
    {
        int dir = direction == 'L' ? -1 : 1;

        int res = rotation + dir * distance;

        rotation = (res % 100 + 100) % 100;
        if (rotation == 0) times_at_zero++;
    }
    in.close();
    std::cout << "Part 1: " << times_at_zero << std::endl;
}

void pt2()
{
    std::ifstream in{"input.txt"};
    int times_at_zero{};
    int rotation = 50;

    char direction;
    int distance;
    while (in >> direction >> distance)
    {

        int dir = direction == 'L' ? -1 : 1;

        int res = rotation + dir * distance;

        int new_rotation = (res % 100 + 100) % 100;

        times_at_zero += distance / 100;
        if (new_rotation == 0)
        {
            times_at_zero++;
        }
        else if (rotation != 0)
        {
            if ((dir < 0 && new_rotation > rotation) || (dir > 0 && new_rotation < rotation)) times_at_zero++;
        }

        rotation = new_rotation;
    }
    in.close();
    std::cout << "Part 2: " << times_at_zero << std::endl;
}

int main()
{
    pt1();
    pt2();
}