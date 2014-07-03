# CSE305
# Assignment 6 Problem 2a
# Thomas Waring III

def qsort(a):
	left=[]
	right=[]
	if a == []:
		return[]

	for x in a[1:]:
		if x < a[0]:
			left = left + [x]
	for x in a[1:]:
		if x >= a[0]:
			right = right + [x]
	
	return qsort(left) + [a[0]] + qsort(right)	

print(qsort([5,4,6,3,7,9,2,8,1,0]))
