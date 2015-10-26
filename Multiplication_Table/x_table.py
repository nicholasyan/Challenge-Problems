table = [[x * y for y in range(13)] for x in range(13)]
for line in table:
    for entry in line:
        print entry,
    print
