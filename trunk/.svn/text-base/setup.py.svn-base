#!/usr/bin/env python

import time
from distutils.core import setup, Extension

v = time.strftime("%Y%m%d%H%M")
projectname = "getdate"

module1 = Extension("_getdate", sources=["getdate.tab.c", "getdate.c"])

setup(
  name=projectname,
  version=v,
  url="http://projects.zoidtechnologies.com/%s/" % (projectname),
  author="Zoid Technologies",
  author_email="%s@projects.zoidtechnologies.com" % (projectname),
  py_modules=["getdate",],
  ext_modules=[module1,]
)
