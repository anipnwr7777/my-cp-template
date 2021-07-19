f = open("1.txt", "r")
data = f.read()
sum = 0
li = []
li1 = []

for item in data:
	if(item.isdigit() == True):
		li.append(item)
		li1.append(item)


li.sort()
if(li1 == li):
	print("they are same")
else:
	print("they are not same")
# print(sum)

f.close


# f.read() --> reads the entire data.
# f.readline() --> reads one line at a time.
# f.readlines() --> reads all the lines at the same time.

# just iterate through the entire data and store the data that you need in some 
# container like  list or something else. now you have filtered the data that is 
# imp to you and apply your logic on that data. you can ignore the file now.

# data is read index by index from the file, (digit by digit)




# if the file contains:
# 	1 2 3 4 5 this is text
# 	this is a line



# then the data will contain:
# 	1

# 	2

# 	3

# 	4

# 	5

# 	t
# 	h.....

# 	this is how it will be stored.