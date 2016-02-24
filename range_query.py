class range:
	def __init__(self, val):
		self.low = val[0]
		self.high = val[1]
	
class Node:
  def __init__(self, val):
    self.l_child = None
    self.r_child = None
    self.max_value = val.high
    self.data = val
    
def update(root, node):
	if root.max_value < node.max_value:
		root.max_value = node.max_value

def insert(root, node):
  if root is None:
    root = node
  else:
    update(root, node)
    if root.data.low > node.data.low:
      if root.l_child is None:
          root.l_child = node
      else:
					update(root.l_child, node)
					insert(root.l_child, node)
    else:
      if root.r_child is None:
        root.r_child = node
      else:
					update(root.r_child, node)
					insert(root.r_child, node)

def intersects(root, node):
	if not node and not root:
		return False
	if node.data.high >= root.data.low and node.data.low <= root.data.high:
		return True
	return False
	
def search(root, node):
	if not root:
		return -1
	print(root.data.low, root.data.high)
	if intersects(root, node):
		print(root.data.low, root.data.high)
		return
	else:
		if root.l_child and root.l_child.max_value >= node.data.low:
			return search(root.l_child, node)
		return search(root.r_child, node)

root = Node(range((1, 3)))
insert(root, Node(range((2, 7))))
insert(root, Node(range((3, 14))))
search(root, Node(range((8, 9))))
