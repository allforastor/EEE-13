#include <stdio.h>
#include <string.h>

//get minimum element of array from index a to index b, inclusive
int get_min(int *array, int a, int b);

//get maximum element of array from index a to index b, inclusive
int get_max(int *array, int a, int b);

//get sum of odd digits of string number
//example   sum_of_odd_digits("12351") == 10
int sum_of_odd_digits(char *str);

//implement them here

int array[] = {1,4,-1,2,5};

int main()
{
	printf("%d %d %d\n", get_min(array,1,4), get_max(array,0,2), sum_of_odd_digits("12351"));
	//should output "-1 4 10"
}
int get_min(int *array, int a, int b)
{
    int i = array[a];
    do
    {
        if(array[a] < i)
        {
            i = array[a];

        }
        //printf("i: %d\nno: %d\nmin: %d\n", a, array[a], i);
        a++;
    }
    while(a <= b);
    return i;
}
int get_max(int *array, int a, int b)
{
    int i = array[a];
    do
    {
        if(array[a] > i)
        {
            i = array[a];

        }
        //printf("i: %d\nno: %d\nmax: %d\n", a, array[a], i);
        a++;
    }
    while(a <= b);
    return i;
}
int sum_of_odd_digits(char *str)
{
    int k = 0;
	for(int i = 0; i < strlen(str); i++)
    {
        int j = (int) str[i];
        j = j - 48;             //I had to use an ASCII code table for this
        //printf("int: %d\n", j);
        if(j % 2 != 0)
        {
            k = k + j;
        }
    }
    //printf("sum: %d\n", k);
    return k;
}
