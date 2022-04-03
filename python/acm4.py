alpha = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
# defined a recursive function here.
# if number is less than "26", simply hash out (index-1)
# There are sub possibilities in possibilities,
# 1.if remainder is zero(if quotient is 1 or not 1) and
# 2. if remainder is not zero
 
def num_hash(num):
    if num < 26:
        return alpha[num-1]
    else:
        q, r = num//26, num % 26
        if r == 0:
            if q == 1:
                return alpha[r-1]
            else:
                return num_hash(q-1) + alpha[r-1]
        else:
            return num_hash(q) + alpha[r-1]
 
 
# Calling the function out here and printing the ALphabets
# This code is robust ,work for any positive integer only.
# You can try as much as you want
print(num_hash(26))
print(num_hash(51))
print(num_hash(52))
print(num_hash(80))
print(num_hash(676))
print(num_hash(702))
print(num_hash(119741))#8869696954435537859955994552