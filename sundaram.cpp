#include "sundaram.h"

std::vector<int> sieve(int n) {
    std::vector<int> primes;
    primes.push_back(2);
    std::vector<bool> compos(((n - 2) / 2) + 1, false);
    for (int i = 1; i <= (n - 2) / 2; i++)
    {
        for (int j = i; (i + j + 2 * i * j) <= (n - 2) / 2; j++)
        {
            compos[i + j + 2 * i * j] = true;
        }
    }
    for (int i = 1; i <= (n - 2) / 2; i++)
    {
        if (!compos[i])
        {
            primes.push_back(2 * i + 1);
        }
    }
    return primes;
}
