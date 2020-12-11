#!/usr/bin/env python

import time
from distutils.core import setup, Extension
from distutils.util import newer, spawn

v = time.strftime("%Y%m%d%H%M")
projectname = "getdate"

#module1 = Extension("libgetdate") #, sources=["getdate.tab.c", "getdate.c"])

extmodules = []
extmodules.append(Extension("libgetdate", ["pygetdate.c", "getdate-parser.c", "getdate-lexer-original.c", "getdate-timezones.c"]))
grammary = "getdate-parser.y"
grammarc = "getdate-parser.c"
if newer(grammary, grammarc):
  spawn(["make", grammarc], verbose=1)

setup(
  name=projectname,
  version=v,
  url="http://projects.zoidtechnologies.com/%s/" % (projectname),
  author="zoid technologies",
  author_email="%s@projects.zoidtechnologies.com" % (projectname),
  py_modules=["getdate",],
#  headers=["xtime.h"],
#  ext_modules=[Extension("libgetdate", ["pygetdate.c", "getdate-parser.c", "getdate-lexer-original.c", "getdate-timezones.c"])] # module1,]
  ext_modules=extmodules,
  classifiers = [
    "Development Status :: 5 - Production/Stable",
    "Intended Audience :: Developers",
    "License :: OSI Approved :: GNU Lesser General Public License v2 (LGPLv2)",
    "Programming Language :: Python :: 3",
    "Topic :: Software Development :: Libraries",
  ]
)
