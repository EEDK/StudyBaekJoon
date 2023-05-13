def solution(want, number, discount):
    answer = 0
    myDict = {}
    for i in range(len(want)):
        myDict[want[i]] = number[i]
        
    for i in range(len(discount)):
        if i + 10 <= len(discount):
            tmp = discount[i:i+10]
            discountDict = {}
            for item in tmp:
                try:
                    discountDict[item] += 1
                except:
                    discountDict[item] = 1
            
            keys = list(discountDict)
            isOk = True
            
            for key in keys:
                try:
                    if myDict[key] != discountDict[key]:
                        isOk = False
                except:
                    isOk = False
                    
            if isOk:
                answer += 1
                
    
    return answer