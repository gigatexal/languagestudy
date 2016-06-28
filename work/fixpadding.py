"""Usage: FixAnsiPadding [-h | --help] INPUT ...]

-h --help      show this
INPUT          FILES to edit or DIRECTORIES to search recursively for files to edit 

"""
import os
from docopt import docopt 

def replace_in_file(input_file,replace_text,with_this_text): #having fun with argument names
   with open(input_file,"r") as curr_file:
      contents = curr_file.read().replace(replace_text,with_this_text)
   
   with open(input_file,"w") as curr_file:
      curr_file.write(contents)
   

if __name__ == '__main__':
   args           = docopt(__doc__)
   quiet          = args['--quiet']
   verbose        = args['--verbose']
   user_input     = args['INPUT']
   extension      = '.sch' 
   
   files = []
   #for each element in user_input check for if its a path or a full file
   for elem in user_input:
      if os.path.isdir(elem):
         for dir,subdir,file in os.walk(os.path.abspath(elem)):
            for f in file: 
               rel_path = os.path.join(dir,f)
               files.append(os.path.abspath(rel_path))
 
      elif os.path.isfile(elem):
         if os.path.splitext(elem)[1] == extension:
            files.append(os.path.abspath(elem)) 

   #actually edit the files
   for file in files:
      replace_in_file(file,"SET ANSI PADDING OFF","SET ANSI PADDING ON")

   print(str(len(files)) + ' file(s) updated.')

   




 
      





 
