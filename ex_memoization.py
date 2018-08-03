arr = []
g = 0
cache = {}

def indianJob(index, a, b):
    
    if (a,b,index) in cache :
        return cache[(a,b,index)]
    
    if (a > g or b > g):
        return 0
    
    if index == len(arr) :
        return 1
    
    v = arr[index]
    
    r = (indianJob(index+1, a+v, b) | indianJob(index+1, a, b+v))

    cache[(a,b,index)] = r
    cache[(b,a,index)] = r
    
    return r