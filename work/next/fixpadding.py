"""
Usage: FixPadding [-h | --help] (INPUT ...)

Options:
-h --help                Show this
INPUT                    FILES to edit or DIRECTORIES to search recursively for files to edit

"""
import os
import itertools
from docopt import docopt

def files_by_dir(dirs):
   for dir in dirs:
      for _dir,subdir,files in os.walk(dir):
         for file in files:
            curr_file_path = os.path.join(_dir,file)
            yield os.path.abspath(curr_file_path)   


def files_from_input(files):
   for item in files:
      if os.path.isfile(item):
         yield os.path.abspath(item)


def combine_iterators(*args):
   yield from itertools.chain(args)
  

def _replace_in_file(file_to_edit,replace_this,with_this):
   with open(file_to_edit,'r') as curr_file:
      contents = curr_file.read()
      contents = contents.replace(replace_this,with_this)
   
   with open(file_to_edit,'w+') as curr_file:
      curr_file.write(contents)  

def _get_file_hash(file):
   with open(file,'r') as curr_file:
      return hash(curr_file.read())

def replace_in_files(file_to_edit,replace_this,with_this):
   before_hash    = _get_file_hash(file_to_edit)
   _replace_in_file(file_to_edit,replace_this,with_this)
   after_hash     = _get_file_hash(file_to_edit)
   if before_hash == after_hash:
      return False
   else:
      return True


if __name__ == '__main__':
   args = docopt(__doc__)
   user_input = args['INPUT']
  
   dirs           = files_by_dir(user_input)
   files_from_cli = files_from_input(user_input)
   
  
   files             = itertools.chain(dirs,files_from_cli)
   replication_files = (file for file in files if os.path.splitext(file)[1] == '.sch')
   
   num_files_modified = 0
   for file in replication_files:
      if (replace_in_files(file,"SET ANSI PADDING OFF","SET ANSI PADDING ON")):
         num_files_modified +=1 

   print(str(num_files_modified) + " file(s) fixed.") 
  


