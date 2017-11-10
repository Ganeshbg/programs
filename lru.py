class LRU:
    def __init__(self):
        self.size=5
        self.lru=[]
        
    def set(self,key,val):
        dic = {}
        dic[key]=val
        val=0
        for i in range(0,len(self.lru)):
            if key in self.lru[i]:
                del self.lru[i]
                self.lru.insert(0,dic)
                val=1
                break
        if(val==0):
            if(len(self.lru)<self.size):
                self.lru.insert(0,dic)
            else:
                del self.lru[len(self.lru)-1]
                self.lru.insert(0,dic)

obj = LRU()
obj.set(1,2)
obj.set(3,4)
obj.set(5,6)
obj.set(7,8)
obj.set(9,10)
obj.set(11,15)
#obj.set(1,3)
#obj.set(9,10)
print(obj.lru)
        
