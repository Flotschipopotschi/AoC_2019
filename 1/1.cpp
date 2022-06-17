#include <iostream>
#include <string>

#pragma warning(disable : 4996) //_CRT_SECURE_NO_WARNINGS

using namespace std;

#define MAX 500

void part1(void);
void part2(void);

uint32_t mass[MAX] = { 0 };
uint32_t massNum = 0;

int main()
{
    while (1)
    {
        string line;
        getline(cin, line);

        if (line.length())
        {
            mass[massNum] = stoi(line);
            massNum++;
        }
        else
        {
            break;
        }
    }

    //part1();
    part2();
}

void part1(void)
{
    uint64_t sum = 0;
    for (uint32_t i = 0; i < massNum; i++)
    {
        sum += mass[i] / 3 - 2;
    }

    printf("%llu", sum);
}

void part2(void)
{
    uint64_t sum = 0;

    for (uint32_t i = 0; i < massNum; i++)
    {
        int64_t lastFuel = mass[i] / 3 - 2;
        uint64_t fuel = 0;
        
        while (1)
        {
            fuel += lastFuel;
            int64_t curFuel = lastFuel / 3 - 2;
            if (curFuel <= 0)
            {
                break;
            }
            lastFuel = curFuel;
        }

        sum += fuel;
    }

    printf("%llu", sum);
}
