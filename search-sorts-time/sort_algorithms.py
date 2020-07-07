"""
This file contains a colection of sort methods.
"""

def less_to(x, y):
    return x < y

def is_sorted(xs, c=less_to):
    n = len(xs)

    for i in range(0, n - 1):
        if c(xs[i + 1], xs[i]):
            return False

    return True


def selection_sort(xs, c=less_to):
    n = len(xs)
    
    for i in range(0, n - 1):
        m = i

        for j in range(i + 1, n):
            if c(xs[j], xs[m]):
                m = j

        xs[i], xs[m] = xs[m], xs[i]

    return xs


def insertion_sort(xs, c=less_to):
    n = len(xs)

    for i in range(1, n):

        j = i

        while j > 0 and c(xs[j], xs[j - 1]):
            xs[j], xs[j - 1] = xs[j - 1], xs[j]
            j -= 1

    return xs

