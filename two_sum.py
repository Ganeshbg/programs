def two_sum(arr,sum):
    arr.sort()
    x=0
    y=len(arr)-1
    if(sum<arr[0]):
        return "No"
    while(x<y):
        tot = arr[x]+arr[y]
        if(tot==sum):
            return "Yes"
        elif(tot>sum):
            y=y-1
        else:
            x=x+1
    return "No"        

arr = [0,3,5,7,9,11,45,76]
print (two_sum(arr,3))
