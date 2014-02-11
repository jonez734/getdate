export PROJECT = getdate
export PROJECTRELEASEDIR = /nfs/gate/projects.zoidtechnologies.com/80/html/$(PROJECT)/

export datestamp = $(shell date +%Y%m%d-%H%M)
export archivename = $(PROJECT)-$(datestamp)-$(USER)

all: _getdate.so

clean:
	-rm -f *.o *~ a.out core getdate.tab.*

distclean: clean
	-rm -f getdate.so

getdate.tab.c: getdate.y
	bison --output-file=getdate.tab.c getdate.y

getdate.tab.o: getdate.tab.c
	gcc -Wall -shared -fPIC -c -o getdate.tab.o getdate.tab.c

getdate.o: getdate.tab.c
	gcc -Wall -shared -fPIC -c -I/usr/include/python2.7/ -o getdate.o getdate.c

_getdate.so: getdate.o getdate.tab.o
	gcc -shared -fPIC -o _getdate.so getdate.o getdate.tab.o

install: _getdate.so
	install _getdate.so /usr/lib/python2.7/site-packages/

release:
	echo "-=- making a new release of $(PROJECT) -=-";\
	pushd ../releases;\
	svn export http://aristotle/repos/$(PROJECT)/trunk/ $(archivename);\
	tar jcf $(archivename).tar.bz2 $(archivename)/*;\
	tar zcf $(archivename).tgz $(archivename)/*;\
	zip -r $(archivename).zip $(archivename)/*;\
	install --mode=0644 $(archivename).tar.bz2 $(archivename).tgz $(archivename).zip $(PROJECTRELEASEDIR);\
	install --mode=0644 $(archivename)/README.txt $(PROJECTRELEASEDIR);\
	popd;\
	echo "[DONE]"

rpm:	_getdate.so
	python ./setup.py bdist_rpm
