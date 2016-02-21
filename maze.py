from random import shuffle, randrange
 
def make_maze(w = 3, h = 3):
    vis = [[0] * w + [1] for _ in range(h)] + [[1] * (w + 1)]
    ver = [["|  "] * w + ['|'] for _ in range(h)] + [[]]
    hor = [["+--"] * w + ['+'] for _ in range(h + 1)]
    print(ver)
 
    def walk(x, y):
        print(x, y)		
        vis[y][x] = 1
 
        d = [(x, y-1), (x, y + 1), (x-1, y), (x+1, y)]
        shuffle(d)
        for (xx, yy) in d:								
            if vis[yy][xx]: continue					
            if xx == x: 
              hor[max(y, yy)][x] = "+  "
            if yy == y: 
              ver[y][max(x, xx)] = "   "
            walk(xx, yy)					
 
    walk(randrange(w), randrange(h))
 
    s = ""
    for (a, b) in zip(hor, ver):
        s += ''.join(a + ['\n'] + b + ['\n'])
    return s
 
if __name__ == '__main__':
    print(make_maze())
