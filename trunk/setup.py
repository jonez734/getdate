#!/usr/bin/env python

import time
from distutils.core import setup, Extension

v = time.strftime("%Y%m%d%H%M")
projectname = "getdate"

#module1 = Extension("libgetdate") #, sources=["getdate.tab.c", "getdate.c"])

setup(
  name=projectname,
  version=v,
  url="http://projects.zoidtechnologies.com/%s/" % (projectname),
  author="zoid technologies",
  author_email="%s@projects.zoidtechnologies.com" % (projectname),
  py_modules=["getdate",],
  ext_modules=[Extension("libgetdate", ["pygetdate.c"])] # module1,]
)
