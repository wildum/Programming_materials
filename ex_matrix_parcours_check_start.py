#*******
#* Read input from STDIN
#* Use echo or print to output your result, use the /n constant at the end of each result line.
#* Use:
#*      local_print (variable ); 
#* to display simple variables in a dedicated area.
#* ***/
import sys

lines = []
for line in sys.stdin:
	lines.append(line.rstrip('\n'))
	
lines = lines[1:]
u = set()
c = 0
for i in range(len(lines)):
    l = lines[i]
    for j in range(len(l)):
        if l[j] == "X":
            if j > 0 and l[j-1] != "X" and (i, j-1) not in u:
                u.add((i, j-1))
                c +=1
            if j < len(l) -1  and l[j+1] != "X" and (i, j+1) not in u:
                u.add((i, j+1))
                c +=1
            if i > 0 and lines[i-1][j] != "X" and (i-1, j) not in u:
                u.add((i-1, j))
                c +=1
            if i < len(l) -1  and lines[i+1][j] != "X" and (i+1, j) not in u:
                u.add((i+1, j))
                c +=1
            if i < len(l) -1 and j < len(l) - 1  and lines[i+1][j+1] != "X" and (i+1, j+1) not in u:
                u.add((i+1, j+1))
                c +=1
            if i > 0 and j < len(l) - 1  and lines[i-1][j+1] != "X" and (i-1, j+1) not in u:
                u.add((i-1, j+1))
                c +=1
            if i < len(l) -1 and j > 0  and lines[i+1][j-1] != "X" and (i+1, j-1) not in u:
                u.add((i+1, j-1))
                c +=1
            if i >0 and j >0  and lines[i-1][j-1] != "X" and (i-1, j-1) not in u:
                u.add((i-1, j-1))
                c +=1
print(c)
                
                
                
                
                