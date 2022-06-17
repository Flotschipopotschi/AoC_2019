#include <iostream>
#include <string>

#pragma warning(disable : 4996) //_CRT_SECURE_NO_WARNINGS

using namespace std;

#define MAX 500

void part1(void);
void part2(void);

int ints[MAX] = { 0 };
uint64_t intsNum = 0;

int main()
{
    while (1)
    {
        string line;
        getline(cin, line);

        if (line.length())
        {
            int lastComma = -1;
            for (uint32_t i = 0; i < line.length() + 1; i++)
            {
                if (i == line.length() || line.c_str()[i] == ',')
                {
                    ints[intsNum] = stoi(line.substr(lastComma + 1, i - lastComma - 1));
                    intsNum++;

                    lastComma = i;
                }
            }
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
    ints[1] = 12;
    ints[2] = 2;

    int stack = 0;

    while (1)
    {
        int val = ints[stack];
        if (val == 1)
        {
            ints[ints[stack + 3]] = ints[ints[stack + 1]] + ints[ints[stack + 2]];
        }
        else if (val == 2)
        {
            ints[ints[stack + 3]] = ints[ints[stack + 1]] * ints[ints[stack + 2]];
        }
        else if (val == 99)
        {
            printf("%d", ints[0]);
            return;
        }

        stack += 4;
    }
   
}

void part2(void)
{
    int helpInts[MAX] = { 0 };

    for (uint32_t noun = 0; noun < 100; noun++)
    {
        for (uint32_t verb = 0; verb < 100; verb++)
        {
            for (uint32_t i = 0; i < intsNum; i++)
            {
                helpInts[i] = ints[i];
            }


            helpInts[1] = noun;
            helpInts[2] = verb;

            int stack = 0;

            while (1)
            {
                int val = helpInts[stack];
                if (val == 1)
                {
                    helpInts[helpInts[stack + 3]] = helpInts[helpInts[stack + 1]] + helpInts[helpInts[stack + 2]];
                }
                else if (val == 2)
                {
                    helpInts[helpInts[stack + 3]] = helpInts[helpInts[stack + 1]] * helpInts[helpInts[stack + 2]];
                }
                else if (val == 99)
                {
                    if (helpInts[0] == 19690720)
                    {
                        printf("%d", 100 * noun + verb);
                        return;
                    }
                    break;
                }

                stack += 4;
            }
        }
    }

}
