**Write a program that outputs all possibilities to put + or - or nothing between the numbers 1, 2, ..., 9 (in this order) such that the result is always 100. For example: 1 + 2 + 34 – 5 + 67 – 8 + 9 = 100.**

Credit:

This problem is from Question #5 on this [site](https://www.shiftedup.com/2015/05/07/five-programming-problems-every-software-engineer-should-be-able-to-solve-in-less-than-1-hour).

Though the title of the article is a bit gimmicky, I nonetheless found the problem quite interesting.

Answer:
```
1 + 23 - 4 + 56 + 7 + 8 + 9
12 + 3 - 4 + 5 + 67 + 8 + 9
1 + 2 + 34 - 5 + 67 - 8 + 9
1 + 2 + 3 - 4 + 5 + 6 + 78 + 9
123 - 4 - 5 - 6 - 7 + 8 - 9
123 + 45 - 67 + 8 - 9
1 + 23 - 4 + 5 + 6 + 78 - 9
12 - 3 - 4 + 5 - 6 + 7 + 89
12 + 3 + 4 + 5 - 6 - 7 + 89
123 - 45 - 67 + 89
123 + 4 - 5 + 67 - 89
1 + 23 - 4 + 56 + 7 + 8 + 9
12 + 3 - 4 + 5 + 67 + 8 + 9
1 + 2 + 34 - 5 + 67 - 8 + 9
1 + 2 + 3 - 4 + 5 + 6 + 78 + 9
123 - 4 - 5 - 6 - 7 + 8 - 9
123 + 45 - 67 + 8 - 9
1 + 23 - 4 + 5 + 6 + 78 - 9
12 - 3 - 4 + 5 - 6 + 7 + 89
12 + 3 + 4 + 5 - 6 - 7 + 89
123 - 45 - 67 + 89
123 + 4 - 5 + 67 - 89
1 + 23 - 4 + 56 + 7 + 8 + 9
12 + 3 - 4 + 5 + 67 + 8 + 9
1 + 2 + 34 - 5 + 67 - 8 + 9
1 + 2 + 3 - 4 + 5 + 6 + 78 + 9
123 - 4 - 5 - 6 - 7 + 8 - 9
123 + 45 - 67 + 8 - 9
1 + 23 - 4 + 5 + 6 + 78 - 9
12 - 3 - 4 + 5 - 6 + 7 + 89
12 + 3 + 4 + 5 - 6 - 7 + 89
123 - 45 - 67 + 89
123 + 4 - 5 + 67 - 89
```
