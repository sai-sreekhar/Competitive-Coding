def maximum_squareness(n, set):
    left, right = 0, n - 1
    current_squareness = 0
    max_squareness = 0
    while left <= right:
        # check if the current element is a perfect square
        if int(set[left] ** 0.5) ** 2 == set[left]:
            current_squareness += 1
            left += 1
        elif int(set[right] ** 0.5) ** 2 == set[right]:
            current_squareness += 1
            right -= 1
        else:
            if int(set[right] - set[left]) >= int(set[left] ** 0.5) + 1:
                current_squareness += int(set[right] - set[left]) - int(
                    set[left] ** 0.5
                )
            max_squareness = max(max_squareness, current_squareness)
            current_squareness -= 1
            left += 1
            right -= 1
    max_squareness = max(max_squareness, current_squareness)
    return max_squareness


print(maximum_squareness(5, (1, 6, 13, 22, 97)))
