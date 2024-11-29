'''Find The Pairs                  
Problem Description
Dhanya loves earrings that are in various polygonal shapes, but she often loses them because she does not manage them well. One day, as she was getting ready for a party, she searched for a matching pair among her collection. Fortunately, there was exactly one pair of matching earrings among all the pieces.

However, the search and finding a match is a laborious process. She took and examined each earring individually. The orientation of the earrings may not be same as it should be. This made her job of selecting the pairs, tough.

More formally, given the vertices of the earrings placed on a 2D plane, determine the numbers of the matching earrings.

The vertices will appear in anticlockwise order in the input.

Note: An earring A and another earring which is mirrored version of A cannot be pairs.

Constraints
2 < N < 10

2 < K < 10

0 <= x <= 10

0 <= y <= 10

Input
First line consists of an integer N, denoting the number of earring pieces she has.

Next you will have N logical parts where each part represents the shape of each earring pieces.

Each part will start with an integer K denoting the number of sides of the earrings.
Followed by K lines consist of two integers x, y denoting the x and y coordinates of the vertex earring shape in the 2D plane [anticlockwise order].
Output
Print the numbers of the matching earrings in a single line in increasing order of earring number.

Assume earring number to be the same as the order in which they appear in the input. Refer the Examples section for more clarity.

Time Limit (secs)
1

Examples
Example1

Input

4
4
0 0
2 0
2 1
0 1
3
0 0
1 1
0 1
4
0 0
1 0
1 2
0 2
4
0 0
1 0
1 1
0 1

Output

1 3

Explanation

The 4 given earrings when represented on a 2D plane looks like below.


com.tcs.cv.automata.ei.middleware.DocxToHtmlConverter@68ed96ca:image1.png

Earring numbers, as they appear in the input, are depicted in top left to bottom right order i.e., first earring is on the top-left in the picture, second earring is top row, right column, third earring is bottom row, left column and fourth earring is at bottom.

As we can see that the earring one is a rotated version of the earring three, they are the pair. Hence print 1 3 as output as required.

Example 2

Input

6
4
0 0
2 0
2 1
0 1
3
0 0
0 1
1 1
4
0 0
1 0
1 1
0 1
6
0 0
2 0
2 1
1 1
1 3
0 3
6
0 0
1 0
1 2
2 2
2 3
0 3
6
0 0
1 0
1 1
3 1
3 2
0 2

Output

4 6

Explanation

The earrings 4, 5 and 6 are depicted below,

com.tcs.cv.automata.ei.middleware.DocxToHtmlConverter@68ed96ca:image2.png

Earrings 1,2,3 are same as ones given in the example 1.

As we can see that the earring four is a rotated version of the earring six, they are the expected pair. Hence print 4 6 as output.'''
import math

def find_pairs(earrings):
    pairs = []
    earring_signatures = {}

    for i, earring in enumerate(earrings):
        # Calculate side lengths and angles
        n = len(earring)
        side_lengths = [((earring[(j+1) % n][0] - earring[j][0])**2 + (earring[(j+1) % n][1] - earring[j][1])**2)**0.5 for j in range(n)]
        angles = [angle_between(earring[j], earring[(j+1) % n], earring[(j+2) % n]) for j in range(n)]

        # Sort side lengths and angles
        side_lengths.sort()
        angles.sort()

        # Create a signature for the earring
        signature = tuple(side_lengths) + tuple(angles)
        earring_signatures.setdefault(signature, []).append(i+1)

    # Find pairs from the signatures
    for earring_indices in earring_signatures.values():
        if len(earring_indices) > 1:
            pairs.extend(earring_indices)

    return pairs

def angle_between(p1, p2, p3):
    # Calculate angle between three points using dot product and cross product
    x1, y1 = p1
    x2, y2 = p2
    x3, y3 = p3
    v1 = (x2 - x1, y2 - y1)
    v2 = (x3 - x2, y3 - y2)
    dot_product = v1[0] * v2[0] + v1[1] * v2[1]
    cross_product = v1[0] * v2[1] - v1[1] * v2[0]
    return math.atan2(cross_product, dot_product)

def main():
    N = int(input())
    earrings = []

    for _ in range(N):
        K = int(input())
        earring = []
        for _ in range(K):
            x, y = map(int, input().split())
            earring.append((x, y))
        earrings.append(earring)

    pairs = find_pairs(earrings)
    print(*sorted(pairs))

if __name__ == "__main__":
    main() #PARTIALLY EXECUTED
