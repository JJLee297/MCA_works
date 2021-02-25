def encode_caesar(string, shift_amt):
    alpha = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"
    beta = alpha[shift_amt::]
    beta += alpha[:shift_amt]
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
            print(index)
            out += beta[index]
        else:
            out += ch
    return out

print(encode_caesar('CogWorks 2018', 5))
