TEMPLATE = subdirs

SUBDIRS += \
    KEBrowser \
    KEBrowserTest

KEBrowserTest.depends = KEBrowser
