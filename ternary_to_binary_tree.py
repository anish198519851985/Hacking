class Node:
    def __init__(self, val):
        self.l_child = None
        self.r_child = None
        self.data = val

def in_order_print(root):
    if not root:
        return
    in_order_print(root.l_child)
    print root.data
    in_order_print(root.r_child)

def bst_t(s, i, root, stack):
    for i in range(1, len(s), 2):
        if s[i] == "?":
            root.l_child = Node(s[i+1])
            stack.append(root.l_child)
            root = root.l_child
        elif s[i] == ":":
            while stack[len(stack)-1].r_child != None:
                print(stack.pop(len(stack)-1).data)
            stack[len(stack)-1].r_child = Node(s[i+1])

s = "3?2?5?6:7:8:9"
x = Node(s[0])
stack = []
stack.append(x)
bst_t(s, 1, x, stack)
in_order_print(x)
