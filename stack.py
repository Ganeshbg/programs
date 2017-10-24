class Stack:
    def __init__(self):
        self.items=[]
    
    def push(self,item):
        self.items.append(item)
    
    def pop(self):
       return self.items.pop(0)
    
    def size(self):
        return len(self.items)
        
        
s=Stack()
s.push(10)
s.push(20)
s.push(30)
print (s.pop())
print (s.pop())
print (s.size())
    
