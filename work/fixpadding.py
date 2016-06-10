import os
import sys
import re


def get_path(path=sys.argv[1]):
    
    user_path = re.sub('/+','/',path)

    if (user_path[len(user_path)-1]) != '/':
       user_path = user_path + '/'

    return(user_path)


def get_files(path):
   
   all_files = os.walk(path)
   target_files = ((dir + '/' + file) for (dir, middir, files) in all_files for file in files)
   return (target_files) #TODO make a generator?

def get_files_to_edit(all_files,extension='sch'):
   #TODO use yeild from in this funtion
   expr = re.compile('\.')
   for file in all_files:
      if re.split(expr,file)[-1] == extension:
         yield (file)



def main():
   path = get_path()
   raw_files = get_files(path)
   files = get_files_to_edit(raw_files,'sch')
   for file in files:
      with open(file,'r+') as curr_file:
         for line in curr_file:
            print(line)
            re.sub('SET ANSI PADDING OFF','SET ANSI PADDING ON',line)#fix
            print(line)
      

main()
