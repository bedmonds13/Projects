#pragma once
#include <vector>
/*Vector manipulation*/

int alternating_sum(std::vector<int>a)
{
    int sum = a[0];
    for (int i = 1; i < a.size(); i++)
    {
        if (i % 2 != 0)
        {
            sum -= a[i];
        }
        else
        {
            sum += a[i];
        }
    }
    return sum;
}
std::vector<int> reverse(std::vector<int>a)
{
    std::vector<int> reverse;

    for (int i = a.size() - 1; i >= 0; i--)
    {
        reverse.push_back(a[i]);
    }

    return reverse;
}

std::vector<int> append(std::vector<int>a, std::vector<int>b)
{
    std::vector<int> appended = a;

    for (int i = 0; i < b.size(); i++)
    {
        appended.push_back(b[i]);
    }
    return appended;
}

std::vector<int> merge(std::vector<int>a, std::vector<int>b)
{
    std::vector<int> merged;

    for (int i = 0; i < a.size() || i < b.size(); i++)
    {
        if (i < a.size())
            merged.push_back(a[i]);
        if (i < b.size())
            merged.push_back(b[i]);
    }

    return merged;
}

std::vector<int>merge_sorted(std::vector<int>sorted1, std::vector<int>sorted2)
{
    std::vector<int>merge_sorted;
    int a_index = 0, b_index = 0;
    while (a_index < sorted1.size() && b_index < sorted2.size())
    {
        if (a_index < sorted1.size() && b_index < sorted2.size())
        {
            if (sorted1[a_index] < sorted2[b_index])
            {
                merge_sorted.push_back(sorted1[a_index]);
                a_index++;
            }
            else
            {
                merge_sorted.push_back(sorted2[b_index]);
                b_index++;
            }
        }
        else if (a_index < sorted1.size())
        {
            merge_sorted.push_back(sorted1[a_index]);
            a_index++;
        }
        else
        {
            merge_sorted.push_back(sorted2[b_index]);
            b_index++;
        }
    }
    return merge_sorted;
}

bool equals(std::vector<int>a, std::vector<int>b)
{
    if (a.size() != b.size())
        return false;
    else
    {
        for (int i = 0; i < a.size(); i++)
        {
            if (a[i] == b[i])
                continue;
            else
                return false;
        }
    }
    return true;
}

/*Pointers*/


