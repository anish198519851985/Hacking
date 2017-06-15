def pow_of_2(n):
    return 1 << (n - 1).bit_length()

def intersect(a, b, c, d):
    if c >= a and c <= b:
        return True
    if d >= a and d <= b:
        return True
    if a >= c and a <= d:
        return True
    if b >= c and b <= d:
        return True
    return False

class segment_tree(object):
    def __init__(self, n, data):
        self.n = pow_of_2(n)
        self.tree = [0]*self.n + data + [0]*(self.n - n)
        self.bound_left = self.n 
        self.bound_right = (self.n*2) - 1
        self.root = 1

    def build_tree(self):
        return self._build_tree(self.n, self.n*2-1, self.root)

    def _build_tree(self, left, right, root):
        if left == right:
            return self.tree[left]
        s = self._build_tree(left, (left+right)/2, 2*root) + self._build_tree(1+(left+right)/2, right, 2*root+1)
        self.tree[root] = s
        return s

    def modify_range(self, left, right, value):
        return self._modify_range(left+self.n, right+self.n, value, self.bound_left, self.bound_right, self.root)

    def _modify_range(self, left, right, value, bound_left, bound_right, root):
        s = 0
        if bound_left == bound_right and intersect(left, right, bound_left, bound_right):
            self.tree[root] += value
            return self.tree[root]
        elif intersect(left, right, bound_left, bound_right):
            s += self._modify_range(left, right, value, bound_left, (bound_left+bound_right)/2, 2*root)\
                    + self._modify_range(left, right, value, 1+(bound_left+bound_right)/2, bound_right, 2*root+1)
            self.tree[root] = s
        return self.tree[root]

    def modify_single(self, pos, val):
        return self._modify_single(pos+self.n, val, self.bound_left, self.bound_right, self.root)

    def _modify_single(self, pos, val, bound_left, bound_right, root):
        s = 0
        if bound_left == bound_right and pos == bound_left:
            self.tree[bound_left] = val
            return self.tree[bound_left]
        elif pos >= bound_left and pos <= bound_right:
            s += self._modify_single(pos, val, 1+(bound_left+bound_right)/2, bound_right, 2*root+1) +\
                    self._modify_single(pos, val, bound_left, (bound_left+bound_right)/2, 2*root)
            self.tree[root]= s
        return self.tree[root]

    def query_range(self, left, right):
        return self._query_range(left+self.n, right+self.n, self.bound_left, self.bound_right, self.root)

    def _query_range(self, left, right, bound_left, bound_right, root):
        s = 0
        if bound_left == bound_right and intersect(left, right, bound_left, bound_right):
            return self.tree[root]
        elif intersect(left, right, bound_left, bound_right):
            s += self._query_range(left, right, bound_left, (bound_left+bound_right)/2, 2*root)\
                    + self._query_range(left, right, 1+(bound_left+bound_right)/2, bound_right, 2*root+1)
        return s

    def __repr__(self):
        return " ".join(str(i) for i in self.tree)

data = [-2, 4, -1, 7, 5]
sg = segment_tree(len(data), data)
sg.build_tree()
print("query_range 0 to end", sg.query_range(0, len(data)-1))
sg.modify_single(2, 100)
print("modified index 2 with 100", sg)
sg.modify_range(1, 3, 8)
print("modified range 1,3 with 8", sg)        
        
