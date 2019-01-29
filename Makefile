
SUBDIRS =  globalfifo globalfifo-platform globalmem globalmem2 \
           globalmem_test hellomodule mainaddmodule

all: subdirs

subdirs:
	for n in $(SUBDIRS); do $(MAKE) -C $$n || exit 1; done

clean:
	for n in $(SUBDIRS); do $(MAKE) -C $$n clean; done
