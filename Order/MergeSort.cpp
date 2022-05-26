int partition(vector<vector<int>>& a, int start, int end)
{
    int piviot = a[end];
    int pind = start;
    int temp;

    for (int i = start; i < end; i++) {
        if (a[i] <= piviot) {
            temp = a[i];
            a[i] = a[pind];
            a[pind] = temp;
            pind++;
        }
    }

    temp = a[end];
    a[end] = a[pind];
    a[pind] = temp;

    return pind;
}

void quicksort(vector<vector<int>>& a, int start, int end)
{
    if (start < end) {
        int pind = partition(a, start, end);
        quicksort(a, start, pind - 1);
        quicksort(a, pind + 1, end);
    }
}