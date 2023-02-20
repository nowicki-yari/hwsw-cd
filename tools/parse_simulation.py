#!/usr/bin/env python3

from sys import argv

fname = argv[1]
string = ""
with open(fname, "r") as fh:

    for line in fh:
        line = line.rstrip()
        line_int = int(line,2)
        string += chr(line_int)
        print("%s - %03d - %s - %s" % (line, line_int, hex(line_int), chr(line_int)))
    print(string)
