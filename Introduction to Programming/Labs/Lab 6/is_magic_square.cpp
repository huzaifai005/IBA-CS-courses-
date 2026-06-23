#include <iostream>
int main()
{
    int a[3][3] = {{2, 7, 6},
                   {9, 5, 1},
                   {4, 3, 8}};
    int x = std::size(a);
    int y = std::size(a[0]);
    int msum = 0;
    int rsum = 0;
    int csum = 0;
    bool square = true;

    for (int i = 0; i < x; i++)
    {
        msum += a[0][i];
    }

    if (x == y)
    {

        for (int i = 0; i < x; i++)
        {
            rsum = 0;
            for (int j = 0; j < y; j++)
            {
                rsum += a[i][j];
            }

            if (rsum != msum)
            {
                square = false;
                break;
            }
        }

        for (int i = 0; i < x; i++)
        {
            csum = 0;
            for (int j = 0; j < y; j++)
            {
                csum += a[j][i];
            }
            if (rsum != msum)
            {
                square = false;
                break;
            }
        }

        int diagsum = 0;
        for (int i = 0; i < x; i++)
        {
            diagsum += a[i][i];
        }
        if (diagsum != msum)
        {
            square = false;
        }
        int sdiagsum = 0;
        for (int i = 0; i < 3; i++)
        {
            sdiagsum += a[i][2 - i];
        }
        if (sdiagsum != msum)
        {
            square = false;
        }
    }
    else
    {
        square = false;
    }

    if (!square)
    {
        std::cout << "false";
    }
    else
    {
        std::cout << "true";
    }
}
