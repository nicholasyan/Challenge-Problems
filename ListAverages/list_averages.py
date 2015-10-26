def find_highest_average(lists):
    max_average = None
    max_index = None
    for index, list in enumerate(lists):
        average = float(sum(list)) / float(len(list))
        if max_average is None or average > max_average:
            max_average = average
            max_index = index

    return max_index
