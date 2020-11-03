nums = list(map(lambda expr: sum(map(int, expr.split('+'))), input().split('-')))
print(nums[0] - sum(nums[1:]))