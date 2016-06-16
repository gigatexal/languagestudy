from distutils.core import setup
import py2exe

setup(console=['C:\\Users\\alexandar_narayan\\PycharmProjects\\languagestudy\\languagestudy\\work\\fixpadding.py'],
      options = {
                "py2exe":{
                         "includes":['pyreadline','win32evtlog', 'win32evtlogutil']
                         }
      }      
)
