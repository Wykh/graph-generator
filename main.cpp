#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include <math.h>
#include <iomanip>

#define GRID_SIZE 99
#define OUTPUT_WIDTH 3

typedef std::pair<int, int> iPair;
typedef std::vector<iPair> iPairs;
typedef std::vector<std::vector<int> > iMatrix;

iPair GenerateDot();

int findLenBetweeenDots(iPair dot1, iPair dot2);

int main(int argc, char *argv[])
{
    // arg1, arg2... - vertexes count for each graph

    // example: ./main 2 3 5
    // print graph with 2, 3 and 5 vertexes

    srand(time(0));

    std::vector<int> vertsCnt;

    for (int i = 1; i < argc; i++)
    {
        int arg = atoi(argv[i]);
        vertsCnt.push_back(arg);
    }

    std::cout << argc - 1 << std::endl;

    for (std::vector<int>::iterator it = vertsCnt.begin(); it != vertsCnt.end(); it++)
    {
        std::cout << *it << std::endl; // vertexes count
        iPairs dotsOnGrid;

        for (int i = 0; i < *it; i++)
        {
            iPair dot = GenerateDot();
            dotsOnGrid.push_back(dot);
        }

        int i = 0;

        for (iPairs::iterator it = dotsOnGrid.begin(); it != dotsOnGrid.end(); it++, i++)
        {
            for (int j = 0; j < i; j++)
            {
                std::cout << std::setw(OUTPUT_WIDTH) << std::left << ' ';
            }
            
            std::cout << std::setw(OUTPUT_WIDTH - 1) << std::left << 0;
            for (iPairs::iterator it2 = it + 1; it2 != dotsOnGrid.end(); it2++)
            {
                int lenBetweenDots = findLenBetweeenDots(*it, *it2);
                std::cout << std::setw(OUTPUT_WIDTH) << std::left  << lenBetweenDots;
            }
            std::cout << std::endl;
        }
    }

    return 0;
}

iPair GenerateDot()
{
    int x = rand() % GRID_SIZE + 1;
    int y = rand() % GRID_SIZE + 1;

    iPair dot;
    dot.first = x;
    dot.second = y;

    return dot;
}

int findLenBetweeenDots(iPair dot1, iPair dot2)
{
    int fstSquare = (dot1.first - dot2.first) * (dot1.first - dot2.first);
    int sndSquare = (dot1.second - dot2.second) * (dot1.second - dot2.second);
    int sumSquare = fstSquare + sndSquare;
    double dSqrt = sqrt(sumSquare);
    int squareRoot = dSqrt;
    return squareRoot;
}