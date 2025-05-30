def my_max_segments(n):
    if n == 0:
        return 0
    elif n == 1:
        return 1
    elif n % 2 == 1:  # n is odd
        return (n + 1) // 2
    else:  # n is even
        return (n // 2) + 1

# Read the number of test cases
t = int(input())
for _ in range(t):
    n = int(input())
    print(my_max_segments(n))