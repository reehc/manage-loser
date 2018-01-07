#!/bin/bash

# stdin:0 stdout:1 stderr:2 

> rewrite
>> append
2> redirect stderr

echo "???" 1>out.txt 2>error.txt


