def subset_sum(numbers, target, partial=[], partial_sum=0):
    if partial_sum >= target[0] and partial_sum <= target[1]:
        yield partial
    if partial_sum >= target[1]:
        return
    for i, n in enumerate(numbers):
        remaining = numbers[i + 1:]
        yield from subset_sum(remaining, target, partial + [n], partial_sum + n)

boxes, wanted_boxes =  list(map(int, input().split()))
list_boxes =  list(map(int, input().split()))
target = list(map(int, input().split()))

list_boxes = list(filter(lambda x: x <= target[1], list_boxes)).sort()

combinations = subset_sum(list_boxes, target)
r = 0
for combination in combinations:
    r += 1 if len(combination) == wanted_boxes else 0
print(r)