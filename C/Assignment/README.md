**Assignment**

Task Description:

You are a researcher in a hospital's radiology department and you are tasked with developing a program to identify patient IDs for X-ray scans whose identification information has been lost. The identification will be done by comparing the "unknown" scans with a set of "known" scans. Some of the unknown images are transformed versions of the known images, having been flipped or rotated.

The task is divided into several parts:

Task 1: Helper Functions

- This involves creating two C functions that calculate the mean and variance of a given array of integers. You will also need to write functions that flip, mirror, and rotate images by modifying the order of pixels in the array.

Task 2: Database Creation

- You will write a program to compute and store the filename, statistics, and the appropriate hashes of each known image. This will speed up the search and comparison of images in Task 3. The program should print the database to the console.

Task 3: Efficient Search

- In this task, you will report the file names from the known set that appear in the unknown set. Your program should read in the database file from Stage 1, storing the information in a data structure. For each unknown image, it should compute the hash, mean, and/or variance and use this information to identify the correct match from the known set.
- The task also requires you to write a maximum 500-word short report discussing the merits of the search algorithm you choose to use, and comparing it to one other search algorithm discussed in this unit. Resources referred to from outside the unit must be referenced.
