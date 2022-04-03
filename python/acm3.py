def title(sen):
	res = 0
	for i in range(len(sen)):
		res *= 26
		res += ord(sen[i]) - ord('A') + 1


	return res
print(title("AAZZAAZZ"))#8661542058
