ldapsearch -Q 'uid=z*' cn | grep "^cn" | sed 's/cn: //g' | sort -r
