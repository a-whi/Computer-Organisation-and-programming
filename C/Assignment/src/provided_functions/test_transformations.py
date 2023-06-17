# Program to test various transformations
# Copyright © 2023 Copyright, Monash University

import subprocess

def get_output(command: str, filepath: str, stdinput: str="") -> str:
    """Gets the terminal output of an executable file

    Args:
        exeName (str): The name of the executable, with any arguments separated by spaces afterwards
        filepath (str): The path to the directory containing the executable
        stdinput (str, optional): The input to feed to the stdin stream. Defaults to "".

    Returns:
        str: The terminal output of running the executable
    """
    proc = subprocess.Popen(f"cd {filepath} && ./{command}", stdout=subprocess.PIPE,
                            stdin=subprocess.PIPE, stderr=subprocess.PIPE, shell=True)

    return proc.communicate(input=stdinput.encode())[0].decode().strip()


original = [
    0, 0, 0, 0, 0, 0,
    0, 0, 0, 8, 0, 0,
    0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0,
    9, 0, 0, 0, 0, 0
]

rot90clock = [
    9, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 8, 0,
    0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0,
]

rot180 = [
    0, 0, 0, 0, 0, 9,
    0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0,
    0, 0, 8, 0, 0, 0,
    0, 0, 0, 0, 0, 0,
]

rot270clock = [
    0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0,
    0, 8, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 9
]

flip = [
    9, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0,
    0, 0, 0, 8, 0, 0,
    0, 0, 0, 0, 0, 0
]

mirror = [
    0, 0, 0, 0, 0, 0,
    0, 0, 8, 0, 0, 0,
    0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 9
]

def rot90_works():
    image_height = 6
    operation = "n" # ninety degrees
    input = "".join([str(char) + " " for char in original])
    expected_output = "".join([str(char) + " " for char in rot90clock]).strip()
    raw_output = get_output(f"test_transformations {operation} {image_height} {input}", "../outputs")

    succeeded = expected_output == raw_output
    if not succeeded:
        print(f"Input:    {input}")
        print(f"Expected: {expected_output}")
        print(f"Actual:   {raw_output}")
    return succeeded

def rot180_works():
    image_height = 6
    operation = "o" # one-eighty degrees
    input = "".join([str(char) + " " for char in original])
    expected_output = "".join([str(char) + " " for char in rot180]).strip()
    raw_output = get_output(f"test_transformations {operation} {image_height} {input}", "../outputs")

    succeeded = expected_output == raw_output
    if not succeeded:
        print(f"Input:    {input}")
        print(f"Expected: {expected_output}")
        print(f"Actual:   {raw_output}")
    return succeeded

def rot270_works():
    image_height = 6
    operation = "t" # two-seventy degrees
    input = "".join([str(char) + " " for char in original])
    expected_output = "".join([str(char) + " " for char in rot270clock]).strip()
    raw_output = get_output(f"test_transformations {operation} {image_height} {input}", "../outputs")

    succeeded = expected_output == raw_output
    if not succeeded:
        print(f"Input:    {input}")
        print(f"Expected: {expected_output}")
        print(f"Actual:   {raw_output}")
    return succeeded

def flip_works():
    image_height = 6
    operation = "f" # flip
    input = "".join([str(char) + " " for char in original])
    expected_output = "".join([str(char) + " " for char in flip]).strip()
    raw_output = get_output(f"test_transformations {operation} {image_height} {input}", "../outputs")
    
    succeeded = expected_output == raw_output
    if not succeeded:
        print(f"Input:    {input}")
        print(f"Expected: {expected_output}")
        print(f"Actual:   {raw_output}")

    return succeeded

def mirror_works():
    image_height = 6
    operation = "m" # mirror
    input = "".join([str(char) + " " for char in original])
    expected_output = "".join([str(char) + " " for char in mirror]).strip()
    raw_output = get_output(f"test_transformations {operation} {image_height} {input}", "../outputs")

    succeeded = expected_output == raw_output
    if not succeeded:
        print(f"Input:    {input}")
        print(f"Expected: {expected_output}")
        print(f"Actual:   {raw_output}")
    return succeeded

if __name__ == "__main__":
    if rot90_works():
        print("Test 1 - Passed - 90 degree rotation")
    else:
        print("Test 1 - Failed - 90 degree rotation")
    if rot180_works():
        print("Test 2 - Passed - 180 degree rotation")
    else:
        print("Test 2 - Failed - 180 degree rotation")
    if rot270_works():
        print("Test 3 - Passed - 270 degree rotation")
    else:
        print("Test 3 - Failed - 270 degree rotation")
    if flip_works():
        print("Test 4 - Passed - Flipped image")
    else:
        print("Test 4 - Failed - Flipped image")
    if mirror_works():
        print("Test 5 - Passed - Mirrored image")
    else:
        print("Test 5 - Failed - Mirrored image")
