ldapsearch -Q "(cn=*bon*)" cn | grep "^cn:" | sed 's/^....//g' | sort -u -f | wc -l | sed 's/ //g' | awk '{ print $0 }'
