#!/bin/sh
QUERY_STRING='idFalla=pointcloud_1'
export QUERY_STRING
gdb build/conversorCgi.cgi
