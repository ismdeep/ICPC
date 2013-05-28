compile:
	g++ ./src/newacm.cpp -o ./bin/newacm

install:
	sudo cp ./bin/newacm /usr/bin
	sudo mkdir /usr/share/newacm
	sudo mkdir /usr/share/newacm/resource
	sudo cp ./resource/* /usr/share/newacm/resource
	sudo mkdir /usr/share/newacm/ini
	sudo cp ./ini/* /usr/share/newacm/ini


clean:
	sudo rm /usr/bin/newacm
	sudo rm /usr/share/newacm/ini/*
	sudo rm /usr/share/newacm/resource/*
	sudo rmdir /usr/share/newacm/ini
	sudo rmdir /usr/share/newacm/resource
	sudo rmdir /usr/share/newacm





