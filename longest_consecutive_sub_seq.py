def Longestconsecutivesubseq(list1):
    list_set=set(list1)
    ans=0
    for i in list_set:
        if i-1 in list_set:
            continue
        else:
            j=i
            while (1):
                if j in list_set:
                    j=j+1
                else:
                    break
            ans=max(ans,j-i)
    return ans
    
print (Longestconsecutivesubseq([8,4,1,5,7,6,2]))
