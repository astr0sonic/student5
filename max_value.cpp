#include "max_value.h"

double calculateMaxValue(double* nums, int n) {
    double minV = nums[0], maxV = nums[0];
    for (int i = 1; i < n; ++i)
    {
        if (nums[i] < 0)
        {
            double maxVv = maxV;
            maxV = max({ maxV - nums[i], minV * nums[i], minV / nums[i] });
            minV = min({ minV + nums[i], maxVv * nums[i], maxVv / nums[i] });
        }
        else if (nums[i] > 0)
        {
            maxV = max({ maxV + nums[i], maxV * nums[i], maxV / nums[i] });
            minV = min({ minV - nums[i], minV * nums[i], minV / nums[i] });
        }
        else
        {
            minV = min(0.0, minV);
            maxV = max(0.0, maxV);
        }
    }
    return maxV;
}
