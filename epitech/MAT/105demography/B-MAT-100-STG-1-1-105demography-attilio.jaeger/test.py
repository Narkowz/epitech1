#!/bin/python
import csv
import sys

# buffer = open('105demography_data.csv', 'r')
# for i in buffer:
#     for a in range(len(i)):
#         if i[a] == ';':
#             for a in range(a, len(i)):
#                 a = a + 1
#                 print(i[a])
#                 if i[a] == ';':
#                     sys.exit(0)

file_path = '105demography_data.csv'
with open(file_path, 'r') as file:
    for line in file:
        data = line.strip().split(';')
        three_letter_code = data[1]
        if data[1] == sys.argv[1]:
            print(data[0])

# def main():# Open the CSV file in read mode
#     csv_file_path = sys.argv[1]
#     with open(csv_file_path, 'r') as csv_file:
#         # Create a CSV reader object
#         csv_reader = csv.reader(csv_file)
    
#         # Iterate through rows in the CSV file
#         for row in csv_reader:
#             # Each row is a list of values
#             print(row)

# if __name__ == "__main__":
#     main()