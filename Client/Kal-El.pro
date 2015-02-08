TEMPLATE = subdirs

SUBDIRS += KENetwork \
           tests

test.depends = KENetwork
