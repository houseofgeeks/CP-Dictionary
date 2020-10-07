#funtion for selection sort
def selection_sort(A):
    # Traverse through all array elements 
    for i in range(len(A)): 
      
        # Find the minimum element in remaining unsorted array 
        min_idx=i 
        for j in range(i+1, len(A)): 
            if A[min_idx]>A[j]: 
                min_idx=j 
              
        # Swap the found minimum element with the first element         
        A[i], A[min_idx]=A[min_idx], A[i] 
n=int(input("Enter number of element:"))
array=[]
print("Enter array:")
for i in range(0,n):
    e=input()
    #adding element to array
    array.append(e)

#funtion call
selection_sort(array)

print("Sorted array:") 
for i in range(len(array)): 
    print(array[i]) 
