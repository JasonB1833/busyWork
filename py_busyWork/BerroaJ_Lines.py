import sys

def count_lines_of_code(file_name):
    try:
        with open(file_name, 'r') as file:
            lines = file.readlines()
            code_lines = 0
            for line in lines:
                line = line.strip()
                if line.startswith('#') or len(line) == 0:
                    continue
                code_lines += 1
            return code_lines
    except FileNotFoundError:
        sys.exit("File does not exist.")
        

def main():
    if len(sys.argv) != 2:
        if len(sys.argv) < 2:
            sys.exit("Too few command-line arguments")
        else:
            sys.exit("Too many command-line arguments")
    file_name = sys.argv[1]
    if not file_name.endswith('.py'):
        sys.exit("Not a Python file")
    try:
        loc = count_lines_of_code(file_name)
        print(f"Lines of code in {file_name}: {loc}")
    except FileNotFoundError:
        sys.exit("File does not exist.")

if __name__ == "__main__":
    main()
