from urllib2 import Request, urlopen, URLError
import json
req=Request('https://api.cdnjs.com/libraries')
response=urlopen(req)
content=response.read()
#print type(content)
#print (content)
x=json.loads(content)
for i in x.keys():
    print i
    if(type(x[i])!=type(1)):
        for j in x[i]:
            print j["name"]
