#!/bin/sh
QUERY_STRING='nombreCarpetaNube=pointcloud_1'
export QUERY_STRING
gdb build/conversorCgi.cgi
