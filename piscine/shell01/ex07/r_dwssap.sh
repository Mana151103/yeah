#!/bin/bash

function MAIN()
{
	sed '/^#/d' /etc/passwd | sed -e 's/:.*//g' | awk 'NR % 2 == 0' | rev | sort -r | awk "NR >= $FT_LINE1 && NR <= $FT_LINE2" | tr '\n' ',' | sed "s/,$/./" | tr -d '\n'
}

MAIN	




