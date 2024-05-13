#include "volume.h"
#include <algorithm>
using namespace std;

int getMaxVolume(int a, int b, int c, int n, int* arr)
{
    int maxVolume = 0;
    int startIndex = 0;
    for (int i = 0; i + a < n; i++)
        if (min({ arr[i], arr[i + a] }) > maxVolume && min({ arr[i], arr[i + a] }) <= c)
        {
            maxVolume = min({ arr[i], arr[i + a] });
            startIndex = i;
        }
    int i = startIndex;
    int j = min(startIndex + a, n - 1);
    while (i != j)
    {
        int currentMin = min(arr[i], arr[j]);
        if (maxVolume < (j - i) * currentMin && currentMin <= c)
        {
            maxVolume = (j - i) * currentMin;
        }
        if (arr[i] <= arr[j])
        {
            i++;
        }
        else
        {
            j--;
        }
    }
    return b * maxVolume;
}
