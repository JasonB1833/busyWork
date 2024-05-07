import csv
import sys

def clean_names(input_file, output_file):
    try:
        with open(input_file, 'r', newline='') as csvfile:
            reader = csv.reader(csvfile)
            with open(output_file, 'w', newline='') as outfile:
                writer = csv.writer(outfile)
                for row in reader:
                    # Splitting the name into first and last name
                    first_name, last_name = row[0].strip('"').split(', ')
                    writer.writerow([first_name, last_name, row[1]])
    except FileNotFoundError:
        sys.exit("Error: Input file not found.")
    except Exception as e:
        sys.exit("An error occurred: " + str(e))

if __name__ == "__main__":
    if len(sys.argv) != 3:
        sys.exit("Usage: python scourgify.py <input_file.csv> <output_file.csv>")
    
    input_file = sys.argv[1]
    output_file = sys.argv[2]

    clean_names(input_file, output_file)
