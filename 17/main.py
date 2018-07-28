import math


digit_names = [
    {        
        0: 'zero',
        1: 'one',
        2: 'two',
        3: 'three',
        4: 'four',
        5: 'five',
        6: 'six',
        7: 'seven',
        8: 'eight',
        9: 'nine',
        10: 'ten',
        11: 'eleven',
        12: 'twelve',
        13: 'thirteen',
        14: 'fourteen',
        15: 'fifteen',
        16: 'sixteen',
        17: 'seventeen',
        18: 'eighteen',
        19: 'nineteen',
    },
    {
        2: 'twenty',
        3: 'thirty',
        4: 'forty',
        5: 'fifty',
        6: 'sixty',
        7: 'seventy',
        8: 'eighty',
        9: 'ninety'
    }
]

def get_nth_digit(number, n):
    return number // 10**n % 10

def number_to_string(n, zero_counts = True):
    if n == 0 and not zero_counts:
        return ''

    if n < 20:
        return digit_names[0][n]
    
    n_digits = int(math.floor(math.log10(n)) + 1)
    

    if n < 100:
        rmd = get_nth_digit(n, 0)

        if rmd == 0:
            rmd_str = ''
        else:
            rmd_str = digit_names[0][rmd]

        return digit_names[1][get_nth_digit(n, 1)] + rmd_str
    

    if n < 1000:
        lmd = int(str(n)[-2:])
        
        lmd_str = ''
        if lmd != 0:
            lmd_str = 'and' + number_to_string(lmd, False)

        return digit_names[0][get_nth_digit(n, 2)] + 'hundred' + lmd_str

    if n == 1000:
        return 'onethousand'


        



_str = ''
for i in range(1, 1001):
    _str += number_to_string(i)

    #print(number_to_string(i))

print(len(_str))