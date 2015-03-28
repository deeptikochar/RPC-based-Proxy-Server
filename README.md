# RPC-based-Proxy-Server

To get top 1000 urls
head -1000 top-1m.csv | cut -d, -f2 | cut -d/ -f1 > topsites.txt