Manacher's Algorithm
---------------------

[NOTE: This document is with respect to the C++ implementation.]


Reference(HackerEarth): https://www.hackerearth.com/practice/algorithms/string-algorithm/manachars-algorithm/tutorial/

    Assume the given string S has a length of N, S = "abababa". Create a string Q of 
    length 2N + 1, by inserting any letter that doesn't appear in the input string (call 
    it special character), in the spaces between any 2 characters. Also, insert this special 
    character in the beginning and the end of the string. If '#' is chosen as special character 
    then the new string Q would look like "#a#b#a#b#a#b#a#". 

    Calculate the longest palindromic substring in each center. Expand around each character i 
    in the new string, then store the number of letters, in the longest palindromic substring 
    with character i as the center, divided by 2.The stored number is divided by 2 because the 
    palindrome substring has it's 2 same parts around the center. 

    Above process would yield an array 
    P = [0, 1, 0, 3, 0, 5, 0, 7, 0, 5, 0, 3, 0, 1, 0]. 
    Each number m, in the array P, indicates that there are m corresponding letters in both 
    sides around a center i. 
    So the palindromic substring = m letters in the left side + center + m letters in right side.

    Steps: 
    ------

    Let the 2 limits of the first palindrome with center c: a left limit l, a right limit r. 
    l, r have references over the last 2 corresponding letters in the palindrome sub-string. 
    A letter w with index i in a palindrome substring has a corresponding letter wMirror with 
    index iMirror such that c - i = iMirror - c.

    (1) If (P[i] <= r - iMirror), 

        So P[iMirror] = P[i] which means that palindrome with center iMirror can't go beyond the 
        original palindrome, so apply the Mirror Property directly.

    (2) Else (P[iMirror] >= P[i]),

        This means that palindrome with center iMirror goes beyond the original palindrome, so 
        expanding around this center iMirror is needed. 

        Let d = distance r - iMirror, so expanding around center iMirror will start from (iMirror - d) - 1 
        with (iMirror + d) + 1 = (r + 1) and so on... because the interval [iMirror - d : iMirror + d] is 
        already contained in the palindrome with center iMirror.

        The algorithm has 2 nestes loops, outer loop checks if there will be an expanding around current 
        letter or not. This loop takes N steps. 
        Inner loop will be used in case of expanding around a letter, but it is guaranteed that it takes 
        at most N steps.
        So the total time = 2N = O(N).

    (3) Update c, r when a palindrome with center i goes beyond the original 
        palindrome with center c. 

        c = i, r = i + P[i] as the next expanding will be around center i.

        [Note: Insert another 2 different special characters in the front and the end of string Q to avoid
        bound checking.]