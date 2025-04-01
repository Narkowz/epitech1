#!/bin/bash
sed -n 'n;p' | cut -d ":" -f 1  | rev | sort -r | sed "$MY_LINE1, $MY_LINE2!d" |  sed -e 's/$/,/' -e '$s/,$/./' | sed ':a;N;$!ba;s/\n/ /g'
