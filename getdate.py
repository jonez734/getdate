import time
import libgetdate
# from libgetdate import getdate, error

def getdate(buf):
    time.tzset()
    return libgetdate.getdate(buf)

