copyNoMove:
	g++  copyNoMove.cc -o copyNoMove -std=c++11
HasPtrUseCount:
	g++  HasPtrUseCount.cc -o HasPtrUseCount -std=c++11
leetdp:
	g++  leetcode/dp.cc -o leet -std=c++11
erasemap:
	g++  asscon/erasemap.cc -o erasemap -std=c++11
arraycode:
	g++  leetcode/arraycode.cc -o arraycode -std=c++11
listcode:
	g++  leetcode/listcode.cc -o listcode -std=c++11
tmp:
	g++  leetcode/tmp.cc -o tmp -std=c++11


clean:
	rm -f copyNoMove HasPtrUseCount lc leet erasemap arraycode listcode tmp