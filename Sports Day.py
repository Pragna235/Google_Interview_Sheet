"""

An elementary school is conducting many games on annual sports day. Chintu wanted to participate and win in at least one of the games. Currently, he is attending puzzle solving and IQ testing games.

In the first round he is provided with N integers consisting of both positive and negative numbers, and asked to select as many as he want such that the resulting efficiency of all the numbers should be maximum.

Rules for calculating the efficiency of the numbers are as follows:

Select as many numbers you want from the provided numbers (one, few or all).
Assign a priority for all those numbers. Priority should range from one to K where K is the count of numbers he selected.
Efficiency is the sum of all the numbers multiplied with their respective priorities.
Help Chintu in calculating the maximum efficiency he can make using the given numbers.

Constraints
1 <= number of elements he is given <= 10^3

-10^3 <= each element <= 10^3

Input
Single line consisting of all the numbers that Chintu is provided with.

Output
Print the maximum efficiency that he can make using the given numbers. Print zero in case if the maximum efficiency is negative.

Time Limit (secs)
1

Examples
Example 1

Input

-7 -8 -5 5 -1 -2 0 3

Output

33

Explanation

Select 5, -1, -2, 0, 3 and give the priorities, -2 = 1, -1 = 2, 0 = 3, 3 = 4, 5 = 5, then efficiency will be, -2*1 + -1*2 + 0*3 + 3*4 + 5*5 = 33 which is the maximum than all possible efficiencies.

Example 2

Input 2

4 2 0 -3 -7

Output

19

Select 4, 2, 0, -3 and give the priorities, -3 = 1, 0 = 2, 2 = 3, 4 = 4, then efficiency will be -3*1 + 0*2 + 2*3 + 4*4 = 19, which is the maximum than all possible efficiencies.

"""

lst=list(map(int,input().split()))
lst.sort(reverse=True)
ans=0
for k in range(1,len(lst)+1):
    sub=lst[:k]
    j=k
    sum1=0
    #print(sub)
    for i in range(len(sub)):
        sum1=sum1+sub[i]*j
        j=j-1
    #print(sum1)
    if(sum1>ans):
        ans=sum1
    else:
        break
print(ans)
