## kasai’s Algorithm

The algorithm constructs LCP array from suffix array and input text in O(n) time. The idea is based on below fact:

Let lcp of suffix beginning at txt[i[ be k. If k is greater than 0,  then lcp for suffix beginning at txt[i+1] will be at-least k-1. The  reason is, relative order of characters remain same. If we delete the  first character from both suffixes, we know that at least k characters  will match. For example for substring “ana”, lcp is 3, so for string  “na” lcp will be at-least 2. Refer [this](http://www.mi.fu-berlin.de/wiki/pub/ABI/RnaSeqP4/suffix-array.pdf) for proof.



### Example with illustration:

```
txt[]     = "banana",  suffix[]  = {5, 3, 1, 0, 4, 2| 

Suffix array represents
{"a", "ana", "anana", "banana", "na", "nana"}

Inverse Suffix Array would be 
invSuff[] = {3, 2, 5, 1, 4, 0}
```

We first compute LCP of first suffix in text which is “**banana**“. We need next suffx in suffix array to compute LCP (Remember lcp[i] is  defined as Longest Common Prefix of suffix[i] and suffix[i+1]).  **To find the next suffix in suffixArr[], we use SuffInv[]**. The next suffix is “na”. Since there is no common prefix between  “banana” and “na”, the value of LCP for “banana” is 0 and it is at index 3 in suffix array, so we fill **lcp[3]** as 0.

Next we compute LCP of second suffix which “**anana**“.  Next suffix of “anana” in suffix array is “banana”. Since there is no  common prefix, the value of LCP for “anana” is 0 and it is at index 2 in suffix array, so we fill **lcp[2]** as 0.

Next we compute LCP of third suffix which “**nana**“. Since there is no next suffix, the value of LCP for “nana” is not defined. We fill **lcp[5]** as 0.

Next suffix in text is “ana”. Next suffix of “**ana**” in suffix array is “anana”. Since there is a common prefix of length 3, the value of LCP for “ana” is 3. We fill **lcp[1]** as 3.

Now we lcp for next suffix in text which is “**na**“.  This is where Kasai’s algorithm uses the trick that LCP value must be at least 2 because previous LCP value was 3. Since there is no character  after “na”, final value of LCP is 2. We fill **lcp[4]** as 2.

Next suffix in text is “**a**“. LCP value must be at  least 1 because previous value was 2. Since there is no character after  “a”, final value of LCP is 1. We fill **lcp[0]** as 1.



**Reference:** https://www.geeksforgeeks.org/%C2%AD%C2%ADkasais-algorithm-for-construction-of-lcp-array-from-suffix-array/