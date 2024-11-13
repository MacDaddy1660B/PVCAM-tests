tests: testParams.cpp
	g++ -o testParams testParams.cpp -L/usr/lib -lpvcam -ldl -lpthread -lraw1394
