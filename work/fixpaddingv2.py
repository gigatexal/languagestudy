import os
import sys
import re
import fileinput


def get_path():
   path = sys.argv
   if path is not None: 
      user_path = re.sub('/+','/',path[1])
      if (user_path[len(user_path)-1]) != '/':
         user_path = user_path + '/'
      return(user_path)
   else:
      print("Please enter in a path or -? --help for help")
      get_path()

def get_files(path):
   all_files = os.walk(path)
   target_files = ((dir + '/' + file) for (dir, middir, files) in all_files for file in files)
   return (target_files)

def get_files_to_edit(all_files,extension='sch'):
   expr = re.compile('\.')
   for file in all_files:
      if re.split(expr,file)[-1] == extension:
         yield (file)

def find_in_files_and_replace(files_to_edit,string_to_search,string_to_replace):
   for line in fileinput.input(files_to_edit,inplace=True, backup='.bak'):
      sys.stdout.write(line.replace(string_to_search,string_to_replace)) 

def main():
   path = get_path()
   raw_files = get_files(path)
   files_to_edit = get_files_to_edit(raw_files)
   find_in_files_and_replace(files_to_edit,'SET ANSI PADDING OFF','SET ANSI PADDING ON')

        
def UI():
   help_flags = ['--?','-?','--help','-help']
   path = get_path()
   while True and path is not None:
     if path.replace('/','') in help_flags:
        print("Replaces the line SET ANSI PADDING OFF to SET ANSI PADDING ON in .SCH files")
        print("Usage: fixpadding.exe <path> or fixpadding.py <path> e.g fixpadding.exe \\unc\\snapshots\\")
        break
   
   raw_files = get_files(path)
   files_to_edit = get_files_to_edit(raw_files)
   for file in files_to_edit:
       find_in_files_and_replace(file,'SET ANSI PADDING OFF','SET ANSI PADDING ON')
       print("Edited " + str(file))      


UI()
#main()
