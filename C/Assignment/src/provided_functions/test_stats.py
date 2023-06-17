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

    return proc.communicate(input=stdinput.encode())[0].decode()

def mean_works():
    expected_output = 4.0
    raw_input = "4 5 3 6 2"
    raw_output = get_output("test_stats_mean " + raw_input, "../outputs")
    try:
        output = float(raw_output)
        tolerance = 0.001
        succeeded = abs(output - expected_output) < tolerance
    except:
        succeeded = False
    
    if not succeeded:
        print(f"Input:    {raw_input}")
        print(f"Expected: {expected_output}")
        print(f"Actual:   {raw_output}")
    return succeeded

def mean_single_item():
    expected_output = 2.0
    raw_input = "2"
    raw_output = get_output("test_stats_mean " + raw_input, "../outputs")
    try:
        output = float(raw_output)
        tolerance = 0.001
        succeeded = abs(output - expected_output) < tolerance
    except:
        succeeded = False
    
    if not succeeded:
        print(f"Input:    {raw_input}")
        print(f"Expected: {expected_output}")
        print(f"Actual:   {raw_output}")
    return succeeded

def variance_works():
    expected_output = 4854.44
    raw_input = "5 3 8 12 45 120 230 17 34 0"
    raw_output = get_output("test_stats_variance " + raw_input, "../outputs")
    try:
        output = float(raw_output)
        tolerance = 0.001
        succeeded = abs(output - expected_output) < tolerance
    except:
        succeeded = False
    
    if not succeeded:
        print(f"Input:    {raw_input}")
        print(f"Expected: {expected_output}")
        print(f"Actual:   {raw_output}")
    return succeeded

def variance_single_item():
    expected_output = 0.0
    raw_input = "255"
    raw_output = get_output("test_stats_variance " + raw_input, "../outputs")
    try:
        output = float(raw_output)
        tolerance = 0.001
        succeeded = abs(output - expected_output) < tolerance
    except:
        succeeded = False
    
    if not succeeded:
        print(f"Input:    {raw_input}")
        print(f"Expected: {expected_output}")
        print(f"Actual:   {raw_output}")
    return succeeded

    

if __name__ == "__main__":
    if mean_single_item():
        print("Test 1 - Passed - Calculation of mean value of single number")
    else:
        print("Test 1 - Failed - Calculation of mean value of single number")

    if mean_works():
        print("Test 2 - Passed - Calculation of mean value of list of numbers")
    else:
        print("Test 2 - Failed - Calculation of mean value of list of numbers")

    if variance_single_item():
        print("Test 3 - Passed - Calculation of variance value of single number")
    else:
        print("Test 3 - Failed - Calculation of variance value of single number")

    if variance_works():
        print("Test 4 - Passed - Calculation of variance value of list of numbers")
    else:
        print("Test 4 - Failed - Calculation of variance value of list of numbers")

