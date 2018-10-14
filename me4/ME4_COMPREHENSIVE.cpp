#include <iostream>

using namespace std;

int ave(int n, int nums[], int m);
void sort(int n, int nums[], int order[]);
void group(int n, int nums[], int mean, int order[], int bins[]);
void assign(int n, int nums[], int m, int bins[]);

int main()
{
    int m, n;
    cin >> n;
    int nums[n];
    int print[n];
    for(int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    for(int i = 0; i < n; i++)
    {
        print[i] = nums[i];
    }
    cin >> m;
    int bins[n] = {0};

    assign(n, nums, m, bins);

    printf("\nitems:\t ");
    for(int i = 0; i < n; i++)
    {
        printf("%d  ", print[i]);
    }
    printf("\nbins:\t");
    for(int i = 0; i < n; i++)
    {
        printf("[%d]", bins[i]);
    }
    printf("\n");

    return 0;
}

void assign(int n, int nums[], int m, int bins[])
{
    int mean = ave(n, nums, m);
    if(mean != 0)
    {
        int order[n];
        for(int i = 0; i < n; i++)
        {
            order[i] = i;
        }
        printf("\nbin size: %d\n\n", mean);

        sort(n, nums, order);

        printf("unsorted:\t");
        for(int i = 0; i < n; i++)
        {
            printf("%d ", nums[i]);
        }
        printf("\nsorted:\t\t");
        for(int i = 0; i < n; i++)
        {
            printf("%d ", nums[order[i]]);
        };
        printf("\n\n");

        group(n, nums, mean, order, bins);
    }
}

int ave(int n, int nums[], int m)
{
    int total = 0;
    for(int i = 0; i < n; i++)
    {
        total = total + nums[i];
    }

    if(total % m != 0)      //for checking
    {
        cout << endl << "ERROR: cannot equally divide " << total << " into " << m << " bins" << endl << endl;
        return 0;
    }
    else
    {
        total = total / m;
        return total;
    }

}

void sort(int n, int nums[], int order[])   //insertion sort
{
    for(int leading = 1; leading < n; leading++)
    {
        int current = order[leading];
        int trailing = leading - 1;
        while((trailing >= 0) && (nums[order[trailing]] < nums[current]))
        {
            order[trailing + 1] = order[trailing];
            trailing = trailing - 1;
        }
        order[trailing + 1] = current;
    }
}

void group(int n, int nums[], int mean, int order[], int bins[])
{
    int bin = 1;
    int sum = 0;
    int error = 0;
    for(int i = 0; i < n; i++)
    {
        printf("For bin %d:\ti = %d\n ", bin, i);
        for(int i = 0; i < n; i++)
        {
            printf("%d  ", nums[i]);
        }
        printf("\n");
        for(int i = 0; i < n; i++)
        {
            printf("[%d]", bins[i]);
        }
        printf("\n\n");

        if(nums[order[i]] != -1)    //prevents overlap
        {
            if(nums[order[i]] > mean)      //for checking
            {
                cout << "ERROR: an item is larger than the bin size" << endl << endl;
                error = 1;  //allows loop to end
                break;
            }
            else if(sum < mean)
            {
                sum = sum + nums[order[i]];
                bins[order[i]] = bin;
                if(sum == mean)
                {
                    for(int k = 0; k < n; k++)
                    {
                        if(bins[order[k]] == bin)
                        {
                            nums[order[k]] = -1;    //prevents overlap
                        }
                    }
                    sum = 0;    //resets sum for the next bin
                    error = 0;  //resets error counter
                    bin++;
                }
                else if(sum > mean)
                {
                    sum = sum - nums[order[i]];
                    bins[order[i]] = 0;
                }
            }
        }

        if((i == (n - 1)) && (error == 0))
        {
            for(int l = 0; l < n; l++)
            {
                if(bins[order[l]] == 0)
                {
                    i = l - 1;  //lets the loop start from the first item that is not put in a bin
                    sum = 0;
                    error = 1;  //if it doesn't solve after one more loop, then it really cannot divide
                    break;
                }
            }
        }
    }
    for(int o = 0; o < n; o++)      //for checking
    {
        if(bins[o] == 0)
        {
            cout << "ERROR: unable to equally divide all items into bins" << endl << endl;
            break;
        }
    }
}

//REFERENCES:
/*
    https://www.toptal.com/developers/sorting-algorithms
    https://www.geeksforgeeks.org/insertion-sort/
*/
