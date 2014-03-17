copyNoMove:
	g++  copyNoMove.cc -o copyNoMove -std=c++11
HasPtrUseCount:
	g++  HasPtrUseCount.cc -o HasPtrUseCount -std=c++11
leet:
	g++  leetcode/Solution.cc -o leet -std=c++11

clean:
	rm -f copyNoMove HasPtrUseCount lc leet