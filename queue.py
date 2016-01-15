class queue:
	def __init__(self, size):
		#make sure size is power of 2
		if (size & (size-1)) == 0:
			print("size of the queue is %d" % size)
		else:
			raise ValueError('size %d not power of 2' % (size))
		self.queue = [0]*size
		self.size = size
		self.read_pointer = 0
		self.write_pointer = 0
		self.size_mask = size - 1
	
	def enqueue(self, data):
		if ((self.write_pointer+1) & self.size_mask) == self.read_pointer:
			print("queue is full")
			return "sentinel"
		self.queue[self.write_pointer] = data
		self.write_pointer += 1
		self.write_pointer &= self.size_mask
	
	def dequeue(self):
		if self.read_pointer == self.write_pointer:
			print("queue is empty")
			return "sentinel"
		removed_data = self.queue[self.read_pointer]
		self.read_pointer += 1
		self.read_pointer &= (self.size-1)		
		return removed_data
		
	def isempty(self):
		return self.read_pointer == self.write_pointer
