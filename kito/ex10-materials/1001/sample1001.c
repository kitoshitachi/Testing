#include <stdio.h>
#define MAX 10
int get_min_element_index(int array[], int left, int right)
{
    int current_index;
    int min_position;
    min_position = left;
    for (current_index = left + 1; current_index <= right; current_index++)
    {
        if (array[current_index] < array[min_position])
            min_position = current_index;
    }
    return min_position;
}
void selection_sort(int array[], int right)
{
    int left, current_index, min_position;
    for (left = 0; left < right; left++)
    {
        current_index = get_min_element_index(array, left, right - 1);
        if (current_index != left)
        {
            min_position = array[current_index];
            array[current_index] = array[left];
            array[left] = min_position;
        }
    }
}
int main(void)
{
    int current_index, n, array[MAX];
    scanf("%d", &n);
    if (n <= 0)
    {
        printf("[ERROR] data count must be positive!\n");
        return 1;
    }
    if (n > MAX)
    {
        printf("[ERRRO] too many data!\n");
        return 1;
    }
    for (current_index = 0; current_index < n; current_index++)
        scanf("%d", &array[current_index]);
    printf("before: ");
    for (current_index = 0; current_index < n; current_index++)
        printf("%d ", array[current_index]);
    printf("\n");
    selection_sort(array, n);
    printf("after:  ");
    for (current_index = 0; current_index < n; current_index++)
        printf("%d ", array[current_index]);
    printf("\n");
    return 0;
}
