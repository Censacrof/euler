import bisect


names = []


with open('./22/names.txt', 'r') as f:
    
    quote_opened = False
    name = ''
    while True:
        c = f.read(1)

        if not c:
            break

        
        if c == '"':
            if quote_opened:
                i = bisect.bisect(names, name)
                names.insert(i, name)

                quote_opened = False
            else:
                name = ''
                quote_opened = True
        elif c == ',':
            continue
        else:            
            name += c
        


    f.close()

tot_score = 0

for i in range(len(names)):
    score = 0
    for c in names[i]:
        score += ord(c) - 64
    
    tot_score += score * (i + 1)
    pass


print(tot_score)