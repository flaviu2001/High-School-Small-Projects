import requests
import json
import random
prb = requests.get('http://codeforces.com/api/problemset.problems').json()
gots = set()
n = int(input("How many users? "))
ok = []
for i in range(10000):
	ok.append(False)
for i in range(n):
	name = str(input("User number "+str(i+1)+": "))
	response = requests.get("https://codeforces.com/api/user.status?handle="+name+"&from=1&count=10000").json()
	if response['status'] == 'FAILED':
		print('Handle not found')
		i = i-1
		continue
	ln = len(response['result'])
	for j in range(ln):	
		if not 'contestId' in response['result'][j]:
			continue
		if response['result'][j]['contestId'] < 10000:
			gots.add(ok[response['result'][j]['name'])
			ok[response['result'][j]['contestId']] = True
contests = requests.get("https://codeforces.com/api/contest.list?gym=false").json()
ln = len(contests['result'])
goods = []
for j in range(ln):
	if contests['result'][j]['id'] < 10000 and \
	   not ok[contests['result'][j]['id']] and \
	   contests['result'][j]['phase'] == 'FINISHED' and \
	   'Div. 2' in contests['result'][j]['name']:
		
		goods.append(contests['result'][j])
for i in range(3):
	print(goods[i]['id'])
goods.pop(0)
goods.pop(0)
goods.pop(0)
rando = random.sample(goods, 7)
#for i in rando:
	#print(i['id'])
for x in gots:
	print(x)
