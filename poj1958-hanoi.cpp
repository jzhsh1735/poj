#include <iostream>
#include <algorithm>
using namespace std;

int hanoi3[15], hanoi4[15];

int
main()
{
    hanoi3[1] = 1;
    for (int i = 2; i < 15; i++) hanoi3[i] = 2 * hanoi3[i - 1] + 1;
    hanoi4[1] = 1;
    for (int i = 2; i < 15; i++)
    {
        hanoi4[i] = 2 * hanoi4[1] + hanoi3[i - 1];
        for (int j = 2; j < i; j++) hanoi4[i] = min(hanoi4[i], 2 * hanoi4[j] + hanoi3[i - j]);
    }
    for (int i = 1; i <= 12; i++) cout << hanoi4[i] << endl;
    return 0;
}
