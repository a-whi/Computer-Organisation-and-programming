#!/usr/bin/env python
import sys
import json

""" Usage: python check_memory.py ../outputs/heaptrack_summary.txt """
""" The heaptrack_summary.txt file is expected to look as follows:
heaptrack stats:
	allocations:          	45004
	leaked allocations:   	2
	temporary allocations:	6000
peak heap memory consumption: 701.91K
"""

def main(memory_stats_filename: str):
    stats = {}

    with open(memory_stats_filename, mode="r") as memory_stats_file:
        print("Memory consumption statistics:")
        try:
            for line in memory_stats_file.readlines():
                words = line.strip().split()

                if words[0] == "leaked":
                    stats["leaked_allocations"] = int(words[2])
                elif words[0] == "peak":
                    size_string = words[4] # looks like "701.91K" or "24.34M" or "0B"
                    float_value = float(size_string[:-1]) # remove last character and convert to float
                    multiplier = 1
                    if size_string[-1] == "K":
                        multiplier = 1000
                    elif size_string[-1] == "M":
                        multiplier = 1000*1000
                    elif size_string[-1] == "G":
                        multiplier = 1000*1000*1000
                    elif size_string[-1] == "T":
                        multiplier = 1000*1000*1000*1000

                    stats["peak_heap_memory_consumption_bytes"] = float_value * multiplier
            print(json.dumps(stats, sort_keys=True, indent=4)) # prints over multiple lines
        except Exception as e:
            print("Failed to read memory statistics. Check that your program runs correctly")
            # print("The error message was: ")
            # print(str(e))


if __name__ == "__main__":
    memory_stats_filename = sys.argv[1]
    main(memory_stats_filename)