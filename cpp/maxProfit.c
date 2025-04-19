#include <stdio.h>
int maxProfit1(int* prices, int pricesSize) {
    int bestBuyPrice = 1000000000, bestSellyPrice = -1000000000, lowIdx = 0, maxDifference = 0;
    for (int i = 0, j = pricesSize - 1; i < pricesSize && j > 0; i++, j--)
    {
        if (prices[j] > bestSellyPrice && lowIdx < j)
        {
            bestSellyPrice = prices[j];
        }
        if (prices[i] < bestBuyPrice && bestSellyPrice - prices[i] > maxDifference)
        {
            bestBuyPrice = prices[i];
            maxDifference = bestSellyPrice - bestBuyPrice;
            lowIdx = i;
        }
    }

    
    return maxDifference;
}

int maxProfit2(int* prices, int pricesSize) {
    int heighstLeft = -1000000000, highIdx = pricesSize - 1, i, maxDifference = 0;
    while (highIdx > 0)
    {
        heighstLeft = prices[highIdx];
        i = highIdx - 1;
        while (i >= 0)
        {
            if (heighstLeft - prices[i] > maxDifference)
            {
                maxDifference = heighstLeft - prices[i];
            }
            i--;
            
        }
        highIdx--;
    }
    
    return maxDifference;
}



int findMiddleIndex(int* nums, int numsSize) {
    int middleIndex = numsSize / 2;
    int lastMiddleIndex = middleIndex;
    int found = 0;
    int allZeros = 1;
    int leftSum = 0;
    int i;
    int j;
    int rightSum = 0;
    for (i = 0; i < numsSize; i++) {
        if (allZeros && nums[i] == 0)
        {
            allZeros = 1;
        } else {
            allZeros = 0;
            break;
        }
    }
    if (allZeros) {
        return 0;
    }
    while (!found) {
        leftSum = 0;
        rightSum = 0;
        for (i = 0; i < middleIndex; i++) {
            leftSum += nums[i];
        }
        for (j = numsSize - 1; j > middleIndex; j--) {
            rightSum += nums[j];
        }
        if (leftSum > rightSum) {
            if (lastMiddleIndex == middleIndex - 1) {
                break;
            }
            lastMiddleIndex = middleIndex;
            middleIndex--;
        } else if (leftSum < rightSum) {
            if (lastMiddleIndex == middleIndex + 1) {
                break;
            }
            lastMiddleIndex = middleIndex;
            middleIndex++;
        } else if (leftSum == rightSum) {
            found = 1;
        }
        if (middleIndex - 1 < -1 || middleIndex >= numsSize) {
            break;
        }
    }
    if (!found) {
        middleIndex = numsSize / 2;
        lastMiddleIndex = middleIndex;
    }
    while (!found) {
        
        leftSum = 0;
        rightSum = 0;
        for (i = 0; i < middleIndex; i++) {
            leftSum += nums[i];
        }
        for (j = numsSize - 1; j > middleIndex; j--) {
            rightSum += nums[j];
        }
        if (leftSum > rightSum) {
            if (lastMiddleIndex == middleIndex + 1) {
                break;
            }
            lastMiddleIndex = middleIndex;
            middleIndex++;
        } else if (leftSum < rightSum) {
            if (lastMiddleIndex == middleIndex - 1) {
                break;
            }
            lastMiddleIndex = middleIndex;
            middleIndex--;
        } else if (leftSum == rightSum) {
            found = 1;
        }
        if (middleIndex - 1 < -1 || middleIndex >= numsSize) {
            break;
        }
    }
    if (!found) {
        return -1;
    }
    return middleIndex;
}

int main () {
    // int prices[] = {2, 1, 2, 1, 0, 1, 2};
    // int prices2[] = {3,3,5,0,0,3,1,4};

    // printf("max profit %d\n", maxProfit1(prices, 7));
    // printf("max profit %d\n", maxProfit1(prices2, 8));
    int items[] = {3,-2,2,1,0};
    printf("findMiddleIndex %d", findMiddleIndex(items, 4));
    return 0;
}
