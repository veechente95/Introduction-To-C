# 1 - Write a python script that could take an array of a file as an input
# 2 - Sort it
# 3 - Calculate the mean
# 4 - Calculate median
# 5 - Calculate standard deviation without using built-in library functions beside square root.

import math 

def read_array_from_file(filename):
    with open(filename, 'r') as file:   # reads file using 'r'
        content = file.read()   # reads contents of file
        split_content = content.split(',')   # splits into list of strings using ','
        array = [float(x) for x in split_content]   # Converts each string in the list to an integer and create a new list
    return array


# Use bubble sort method to sort elements in array
def sort_array(array):
    sorted_array = array[:]   # create copy of original .txt num_file so its not modified. w/o this the input_array and sorted_array are both sorted
    indexing_length = len(sorted_array) - 1   # -1 b/c we cant perform a comparison on last num in list b/c there is no number after it
    
    # loop until sorted list becomes True    
    sorted_list = False
    while not sorted_list:
        sorted_list = True

        # once values are sorted, if statement won't run, sorted_list will remain true, and break out of while loop
        for i in range(0, indexing_length):
            if sorted_array[i] > sorted_array[i + 1]:   # if value on left > right
                sorted_list = False
                sorted_array[i], sorted_array[i + 1] = sorted_array[i + 1], sorted_array[i]   # swap numbers

    return sorted_array


def calculate_mean(array):
    mean = sum(array) / len(array)   # mean = sum of numbers / number of nums
    return mean


def calculate_median(array):
    sorted_array = sort_array(array)   # call sort_array func from above
    array_len = len(sorted_array)   # counts num of arrays
    
    # If the array length is even, take the average of the middle two elements
    if array_len % 2 == 0:
        middle1 = sorted_array[array_len // 2 - 1]   # gets element before middle
        middle2 = sorted_array[array_len // 2]   # gets element at the middle
        median = (middle1 + middle2) / 2   # gets average of middle elements
    else:
        # If the length is odd, take the middle element
        median = sorted_array[array_len // 2]   # gets middle element 

    return median

def calculate_standard_deviation(array):
    mean = calculate_mean(array)
    array_len = len(array)
    sum_squared_diff = sum((num - mean) ** 2 for num in array)   # Calculate the sum of squared differences from the mean
    variance = sum_squared_diff / array_len   # Calculate the variance
    standard_deviation = math.sqrt(variance)   # Calculate the standard deviation as the square root of the variance

    return standard_deviation


# Example usage:
filename = '/home/veechente/Desktop/Code/algorithm/num_file'
input_array = read_array_from_file(filename)
sorted_array = sort_array(input_array)
mean_value = calculate_mean(input_array)
median_value = calculate_median(input_array)
std_deviation_value = calculate_standard_deviation(input_array)

print("Input Array:", input_array)
print("Sorted Array:", sorted_array)
print("Mean:", mean_value)
print("Median:", median_value)
print("Standard Deviation:", std_deviation_value)

