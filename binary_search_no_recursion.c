int BinSearch(const int a[],int len, int key)
{
    int left = 0,right = len-1;
    while (left <= right)
    {
        int mid = (left + right)/2;
        if(key == a[mid])
            return mid;
        if(key < a[mid])
            right = mid-1;
        if(key > a[mid])
            left = mid+1;
    }
    return -1;
}