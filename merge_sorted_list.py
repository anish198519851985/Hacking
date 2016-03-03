import random

def merge_sorted_list(list1, list2, result):
  if not len(list1) and not len(list2):
    return result
  if not len(list1):
    result.extend(list2)
    return result
  if not len(list2):
    result.extend(list1)    
    return result
  if list1[0] >= list2[0]:
    result.append(list2[0])
    list2.pop(0)
    return merge_sorted_list(list1, list2, result)
  if list2[0] >= list1[0]:
    result.append(list1[0])
    list1.pop(0)
    return merge_sorted_list(list1, list2, result)
  return result


for i in range(0, 100):
  list1 = random.sample(range(100), random.randint(0, 50))
  list1 = sorted(list1)
  list2 = random.sample(range(100), random.randint(0, 50))
  list2 = sorted(list2)
  result = []
  sort = merge_sorted_list(list1, list2, result)
  if sort == sorted(sort):
    continue
  print("something wrong")
