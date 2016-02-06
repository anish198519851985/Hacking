import random
def divide(numbers, start, end):
        pivot = numbers[end]
        end_copy = end
        end -= 1
        while start <= end:
                if numbers[start] >= pivot:
                        numbers[start], numbers[end] = numbers[end], numbers[start]
                        end -= 1
                elif numbers[start] < pivot:
                        start += 1
        numbers[start], numbers[end_copy] = numbers[end_copy], numbers[start]
        return start

def quick_select(numbers, start, end):
        k = (start + end)/2
        while start <= end:
                pivot = divide(numbers, start, end)
                if pivot-start == k:
                        return numbers[pivot]
                elif (pivot - start + 1) > k:
                        end = pivot - 1
                else:
                        k = k - (pivot-start + 1)
                        start = pivot+1
        return -1

def alternate_list(numbers):
        odd = 1; even = 0
        result = [0]*len(numbers)
        median = quick_select(numbers, 0, len(numbers)-1)
        for i in range(0, len(numbers)):
                if numbers[i] <= median:
                        #put in even position
                        result[even] = numbers[i]
                        even += 2
                else:
                        #put in odd position
                        result[odd] = numbers[i]
                        odd += 2
        return result

print(alternate_list(random.sample(range(100), 20)))
