ifconfig | grep 'ether ' | sed -e 's/ //g' -e  's/ether//g' | tr -d '\t'
