//Javascript code to linearly search x in arr[]. If x is present then return its location, otherwise return -1
 
function search(arr, n, x)
{
    let i;
    for (i = 0; i < n; i++)
        if (arr[i] == x)
            return i;
    return -1;
}
 
// Driver code
 
    let arr = [ 2, 3, 4, 10, 40 ];
    let x = 10;
    let n = arr.length;
 
    // Function call
    let result = search(arr, n, x);
    (result == -1)
        ? document.write("Element is not present in array")
        : document.write("Element is present at index " + result);

