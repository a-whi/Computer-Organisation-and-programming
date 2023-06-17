import sys

def main():
    # get the input from the command line:
    if len(sys.argv) < 3:
        print("Not enough command line arguments given!")
        exit(0)
    programOutput = sorted(sys.argv[1].split("\n"))  # sorting allows us to ignore the order of the output
    expectedOutput = sorted(sys.argv[2].split("\n"))

    # compare program output with expected output:
    if programOutput == expectedOutput:
        print(f"Test with input passed!")
    else:
        print(f"Program produced {sys.argv[1]}. Expected {sys.argv[2]}")

if __name__ == "__main__":
    main()