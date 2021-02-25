def encode_keyword(string, keyword):
    alpha = "abcdefghijklmnopqrstuvwxyz"
    result = "".join(dict.fromkeys(keyword))
    desult = ""
    for i in range(0, len(result)):
        if (result[i] != " "):
            desult += result[i]
    result = desult
    for i in range(0, len(alpha)):
        trigger = False
        for k in range(0, len(result)):
            if (alpha[i] == result[k]):
                trigger = True
                break
        if (trigger == False):
            result += alpha[i]
    out = ""
    for i in range(0, len(string)):
        ch = string[i]
        index = 0
        isChar = False
        for j in range(0, len(alpha)):
            if (ch == alpha[j]):
                index = j
                isChar = True
                break
        if (isChar == True):
            out += result[index]
        else:
            out += ch
    return out

print(encode_keyword("perl rocks", "my key"))
