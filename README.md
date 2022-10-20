

Introduction
============

python-v4l2capture is a slim and easy to use Python extension for
capturing video with video4linux2. It supports libv4l to convert any
image format to RGB or YUV420.


Installation
============

v4l2capture requires libv4l by default. You can compile v4l2capture
without libv4l, but that reduces image format support to YUYV input
and RGB output only. You can do so by erasing ', libraries = ["v4l2"]'
in setup.py and erasing '#define USE_LIBV4L' in v4l2capture.c.

python-v4l2capture uses distutils.
To build: ./setup.py build
To build and install: ./setup.py install

Example
=======

See capture_picture.py, capture_picture_delayed.py and list_devices.py.


