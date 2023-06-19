import csv

filename = "Book1.csv"
with open(filename) as f:
	rd = csv.reader(f)
	header_row = next(rd)
	print(header_row)
	header_row = next(rd)
	print(header_row)