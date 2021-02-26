from statistics import mode 
def get_most_popular_foods(file_path):
    f = open(file_path, "r")
    d = {}
    keys = []
    vals = []
    for x in f:
        key = ''
        val = ''
        keyTrig = True
        for i in range(0, len(x)):
            if (x[i] != ':' and keyTrig == True):
                key += x[i]
            if (x[i] != ':' and keyTrig == False):
                if (x[i] != '\n' and x[i] != ','):
                    val += x[i]
            elif (x[i] == ':'):
                keyTrig = False
            if (x[i] == ',' or x[i] == '\n' or i == len(x) - 1):
                val = val[1::]
                if (key[0] == ' '):
                    key = key[1::]
                keys.append(key)
                vals.append(val)
                key = ''
                val = ''
                keyTrig = True
    #print("keys: {} \n vals: {}".format(keys, vals))
    
    for i in range(0, len(vals)):
        indices = []
        for j in range(0, len(vals)):
            if (vals[i] == vals[j]):
                indices.append(j)
        test = []
        for x in indices:
            test.append(keys[x])
        test.sort()
        best = mode(test)
        d[vals[i]] = best
    return d


print(get_most_popular_foods("pptest.txt"))