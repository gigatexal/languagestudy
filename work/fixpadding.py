import os
import sys
import re

user_path = re.sub('/+','/',sys.argv[1])

if (user_path[len(user_path)-1]) != '/':
   user_path = user_path + '/'

print(user_path)

