import subprocess
import sys

def print_list(items: list):
    for item in items:
        print(item, end=" ")

def run_process(command: list, check:bool = True) -> int:
    print("{:8}running".format("[INFO]"), end=" ")
    print_list(command)
    print()

    result = subprocess.run(command, capture_output=True, text=True)
    print(result.stdout)

    if result.returncode != 0:
        print("{:8}execution failed".format("[ERROR]"))
        print(result.stderr)
        return result.returncode

    return result.returncode

cmake_cmd = ["cmake", ".", "-B", "build"]
cmake_build_cmd = ["cmake", "--build", "build"]
cozy_cmd = ["./build/cozyc"] + sys.argv[1:]

result = run_process(cmake_cmd)

if(result != 0):
    exit(result)

result = run_process(cmake_build_cmd)

if(result != 0):
    exit(result)

result = run_process(cozy_cmd)
    
if(result != 0):
    exit(result)