#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations)
    {
        int n = citations.size();

        // record the number of papers for each citation count( 0 - n)
        vector<int> compute_table(n + 1, 0);

        int h = 0;
        int r = 0, l = n - 1;

        while (r <= l)
        {
            int mid = (r + l) / 2;

            // For all the papers whole citation counts larger than the total number of papers,
            // add the number to the largest citation count n.
            if (citations[mid] >= n)
            {
                compute_table[n] = (n - mid);
                l = mid - 1;
            }
            else
            {
                compute_table[citations[mid]] = (n - mid);

                if (compute_table[citations[mid]] == citations[mid])
                {
                    h = citations[mid];
                    break;
                }
                else if (compute_table[citations[mid]] < citations[mid])
                {
                    // get the best h-index so far
                    if (h < compute_table[citations[mid]])
                    {
                        h = compute_table[citations[mid]];
                    }

                    l = mid - 1;
                }
                else
                {
                    // get the best h-index so far
                    if (h < citations[mid])
                    {
                        h = citations[mid];
                    }

                    r = mid + 1;
                }
            }
        }

        // Get the best h-index by checking the last record
        if (compute_table[n] == n)
        {
            h = n;
        }
        else if(h < compute_table[n])
        {
            h = compute_table[n];
        }

        return h;

    }
};