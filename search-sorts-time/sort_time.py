"""
This file contains a program to plot the execution time of selection_sort
and insertion_sort over unsorted and sorted arrays.
"""

import time
import random
import matplotlib.pyplot as plt
from sort_algorithms import selection_sort, insertion_sort


def get_sort_time(sort_algorithm, sizes, num_rep, is_sorted=False):
    
    times = []

    for n in sizes:
        print('Sample size: {}\n'.format(n))
        sample = range(n)

        sum_time = 0
        
        for i in range(num_rep):
            print('Iteration {}'.format(i + 1))

            s = []
            
            for j in sample:
                if is_sorted:
                    s.append(j)
                else:
                    s.append(random.choice(sample))

            t0 = time.time()
            sort_algorithm(s)
            t1 = time.time()
            dt = t1 - t0
            print('Execution time: {} seconds'.format(dt))
            sum_time += dt

        times.append((sum_time / num_rep) * 1000)
        print('\n\n')

    return times


if __name__ == '__main__':
    start_k = 10
    num_dups = 5
    num_reps = 5
    ticks = list(range(start_k, start_k + num_dups))
    sizes = [2**k for k in ticks]
    print('Testing selection_sort with unsorted array')
    ss_times = get_sort_time(selection_sort, sizes, num_reps)
    print('Testing insertion_sort with unsorted array')
    is_times = get_sort_time(insertion_sort, sizes, num_reps)
    print('Testing selection_sort with sorted array')
    sss_times = get_sort_time(selection_sort, sizes, num_reps, True)
    print('Testing insertion_sort with sorted array')
    sis_times = get_sort_time(insertion_sort, sizes, num_reps, True)

    plt.xlabel('samples size 2^k')
    plt.ylabel('Execution time (ms)')
    plt.xticks(sizes, ticks)
    plt.plot(sizes, ss_times, label='Selection sort on unsorted arrays')
    plt.plot(sizes, is_times, label='Insertion sort on unsorted arrays')
    plt.plot(sizes, sss_times, label='Selection sort on sorted arrays')
    plt.plot(sizes, sis_times, label='Insertion sort on sorted arrays')
    plt.legend()
    plt.savefig('sort_algorithms_graphic.png')
