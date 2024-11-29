'''Problem Description
Amelia arrived at the Gamble House on a stormy evening, clutching her notebook filled with equations and strategies.

"Welcome, Amelia," Eliot greeted with a slow drawl. "I hear you're here to beat the odds. Care to join me for a game?"

Amelia responded, "What's the game?"

"It's called Maximum Area," Eliot replied. The game involves N sticks of varying lengths, which are dropped onto the table simultaneously. The objective is to find the largest area of all the enclosed shapes formed, which determines your winning probability. Since Amelia excels in mathematics, she'll provide the coordinates (x1, y1, x2, y2) for each stick, treating them as the start and end points of line segments.

Assist Amelia in calculating the maximum enclosed area formed by these sticks given their coordinates.

Note:

It is given that every shaped formed will always be a polygon with sticks as it sides.

It may form more than one polygon, consider the polygon with maximum area.

The coordinates of all the polygons and their area will always be integers.

Constraints
3 < N < 10

0 <= x1, y1, x2, y2 <= 10

Input
First line consists of an integer N, denoting the number of line segments.

Next N lines consist of four space separated integers (x1, y1, x2, y2) denoting the x, y coordinates of starting and ending points of the line segments.

Output
Print a single integer representing the maximum closed area.

Time Limit (secs)
1

Examples
Example 1

Input

5

2 1 2 6

5 1 5 6

0 2 6 2

0 5 6 5

0 0 6 6

Output

9

Explanation

The five lines when visualized looks like below.

com.tcs.cv.automata.ei.middleware.DocxToHtmlConverter@35038141:image1.png

Maximum closed area is formed between the four lines segments, with area of 9. Hence print 9 as output.

Example 2

Input

6

5 0 1 4

1 2 5 6

0 0 3 1

5 2 5 5

3 2 3 4

4 1 4 5

Output

4

Explanation

The six lines when visualized looks like below. Here multiple closed shapes are formed. However, the maximum closed area formed here is 4. Hence print 4 as output.'''
import itertools
import math

def orientation(p, q, r):
    val = (q[1] - p[1]) * (r[0] - q[0]) - (q[0] - p[0]) * (r[1] - q[1])
    if val == 0:
        return 0
    elif val > 0:
        return 1
    else:
        return 2

def on_segment(p, q, r):
    if min(p[0], r[0]) <= q[0] <= max(p[0], r[0]) and min(p[1], r[1]) <= q[1] <= max(p[1], r[1]):
        return True
    return False

def do_intersect(p1, q1, p2, q2):
    o1 = orientation(p1, q1, p2)
    o2 = orientation(p1, q1, q2)
    o3 = orientation(p2, q2, p1)
    o4 = orientation(p2, q2, q1)
    
    if o1 != o2 and o3 != o4:
        return True
    
    if o1 == 0 and on_segment(p1, p2, q1):
        return True
    if o2 == 0 and on_segment(p1, q2, q1):
        return True
    if o3 == 0 and on_segment(p2, p1, q2):
        return True
    if o4 == 0 and on_segment(p2, q1, q2):
        return True
    
    return False

def find_intersection(p1, q1, p2, q2):
    x1, y1 = p1
    x2, y2 = q1
    x3, y3 = p2
    x4, y4 = q2

    denom = (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4)
    if denom == 0:
        return None

    intersect_x = ((x1 * y2 - y1 * x2) * (x3 - x4) - (x1 - x2) * (x3 * y4 - y3 * x4)) / denom
    intersect_y = ((x1 * y2 - y1 * x2) * (y3 - y4) - (y1 - y2) * (x3 * y4 - y3 * x4)) / denom
    return (round(intersect_x, 2), round(intersect_y, 2))

def calculate_area(polygon):
    n = len(polygon)
    area = 0
    for i in range(n):
        j = (i + 1) % n
        area += polygon[i][0] * polygon[j][1]
        area -= polygon[i][1] * polygon[j][0]
    area = abs(area) / 2
    return area

def maximum_area(segments):
    intersections = set()
    
    for (x1, y1, x2, y2), (x3, y3, x4, y4) in itertools.combinations(segments, 2):
        p1, q1 = (x1, y1), (x2, y2)
        p2, q2 = (x3, y3), (x4, y4)
        
        if do_intersect(p1, q1, p2, q2):
            intersection = find_intersection(p1, q1, p2, q2)
            if intersection:
                intersections.add(intersection)
    
    if not intersections:
        return 0
    
    centroid = (sum(x for x, y in intersections) / len(intersections), 
                sum(y for x, y in intersections) / len(intersections))
    
    def angle_from_centroid(point):
        x, y = point
        cx, cy = centroid
        return math.atan2(y - cy, x - cx)
    
    sorted_intersections = sorted(intersections, key=angle_from_centroid)
    
    return calculate_area(sorted_intersections)

N = int(input())
segments = []
for _ in range(N):
    x1, y1, x2, y2 = map(int, input().split())
    segments.append((x1, y1, x2, y2))

result = maximum_area(segments)
print(int(result))
#PARTIALLY EXECUTED

