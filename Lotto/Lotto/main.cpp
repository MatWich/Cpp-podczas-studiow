#include <iostream> 
#include<time.h>
using namespace std;

void lotto(int, int);

int main()
{

    lotto(49, 6);
    system("pause");
    return 0;
}
void lotto(int total_balls, int balls_to_allot)
{
    if (total_balls < balls_to_allot)
        return;

    srand(time(NULL));

    int* balls = new int[balls_to_allot];

    for (int i = 0; i < balls_to_allot; i++) // i = 1; 
    {
        balls[i] = rand() % total_balls + 1;

        for (int j = 0; j < i + 1; j++) //j = 1; warunek = 2;
        {
            if (balls[i] == balls[j] && i != j)
            {
                i--;
                break;
            }
            else if (j == i)
                cout << "Kulka [" << i + 1 << "] = " << balls[i] << endl;

        }
    }
    delete[] balls;
}
