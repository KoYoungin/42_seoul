cat /etc/passwd | sed '/^#/d'| awk "NR%2==0" | cut -d ':' -f 1 |\
rev | sort -r |\
awk "NR>=$FT_LINE1&&NR<=$FT_LINE2" |\
tr '\n' ',' |\
sed -e 's/,/, /g' -e 's/..$/./'|\
tr -d '\n'