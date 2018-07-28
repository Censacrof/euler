def get_days_in_month(year, month):
    if month in [3, 5, 8, 10]:
        return 30
    elif month == 1:
        if year % 100 == 0:
            if year % 400 == 0:
                return 29
            else:
                return 28
        else:
            if year % 4 == 0:
                return 29
            else:
                return 28
    else:
        return 31


count = 0
days = 2 #1901/01/01 is tuesday = 2
for year in range(1901, 2001):
    for month in range(12):
        days += get_days_in_month(year, month)
        if days % 7 == 0:
            count += 1

print(count)


