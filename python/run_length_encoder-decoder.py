

def run_length_encoder(in_string):
    sLen = len(in_string)
    encode = []
    ch = ""
    count = 0
    for i in range(1, sLen):
        if (in_string[i] != in_string[i - 1]):
            encode.append(in_string[i - 1])
            if (count != 0):  
                encode.append(count + 1)
            count = 0
        elif (in_string[i] == in_string[i - 1]):
            count += 1
            if (count == 1):
                encode.append(in_string[i])
        if (count != 0 and i == sLen - 1):
            encode.append(in_string[i])
            encode.append(count + 1)
            count = 0
    if (sLen > 2):  
        if (in_string[sLen - 1] != in_string[sLen - 2]):
            encode.append(in_string[sLen - 1])
    if (sLen == 1):
        encode.append(in_string[0])

    return encode


def run_length_decoder(in_list):
    length = len(in_list)
    decode = ""
    i = 0
    if (length > 1):
        while(i < length - 1):
            if (in_list[i] != in_list[i + 1]):
                decode += in_list[i]
                i += 1
            elif (in_list[i] == in_list [i + 1]):
                num = in_list[i + 2]
                for j in range(0, num):
                    decode += in_list[i]
                i += 3
        if (isinstance(in_list[length - 1], str)):
            decode += in_list[length - 1]
    else:
        for i in range(0, length):
            decode += in_list[i]
    return decode


print(run_length_decoder(['a', 'b', 'b', 4, 'a', 'a', 2]))
            
