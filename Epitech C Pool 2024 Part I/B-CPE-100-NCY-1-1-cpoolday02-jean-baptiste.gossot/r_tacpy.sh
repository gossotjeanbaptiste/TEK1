sed "1d" | sed -n 2~2p| cut -d: -f 1 | rev | sort -r | sed -n '24,42p' | tr -s "\n" "," | sed's/,$/.\n/' | sed "s/,/, /g" |
