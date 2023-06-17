#!/usr/bin/env python
import sys
import csv
import os

""" Usage: python check_time.py ../outputs/search_times.tsv 
Where search_times.tsv has the following form:

time
0.024
0.023
0.023
0.023
0.024
0.023
"""

def main(search_times_filename):
    try:
        with open(search_times_filename, mode="r") as search_times_file:
            times_reader = csv.DictReader(search_times_file, delimiter='\t')

            times = [float(row['time']) for row in times_reader]
            run_count = len(times)
            average_time = sum(times)/run_count
            print(f"Search took {average_time:.4} seconds")

    except KeyError:
        print("Error: Unable to read search_times.tsv file. Check that it exists and is in the correct format.")


if __name__ == "__main__":
    search_times_filename = sys.argv[1]
    main(search_times_filename)