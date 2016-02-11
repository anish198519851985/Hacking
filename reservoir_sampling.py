import random

def reservoir_sampling(bucket_size, total_sample):
        result = [0]*bucket_size
        #just fill the entire bucket
        for i in range(0, bucket_size):
                result[i] = total_sample[i]
        #now insert the element one by one and see
        #if anyone can replace any item in the bucket
        for i in range(bucket_size, len(total_sample)):
                j = random.randint(0, i)
                if j < bucket_size:
                        result[j] = total_sample[i]
        return result

bucket_size = random.randint(5, 30)
total_sample = random.sample(range(100), bucket_size+50)
result = reservoir_sampling(bucket_size, total_sample)
print(result, len(result))
